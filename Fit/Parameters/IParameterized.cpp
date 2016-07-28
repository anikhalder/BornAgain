// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Parametrization/IParameterized.cpp
//! @brief     Implements class IParameterized.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "IParameterized.h"
#include "AttLimits.h"
#include "ParameterPool.h"
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>

IParameterized::IParameterized(const std::string& name)
    : INamed(name)
{
    m_parameters = new ParameterPool(this);
}

IParameterized::IParameterized(const IParameterized& other)
    : IParameterized(other.getName())
{
    if( other.getParameterPool()->size() )
        throw std::runtime_error( "BUG: not prepared to copy parameters of " + getName() );
}

IParameterized::~IParameterized()
{
    delete m_parameters;
}

ParameterPool* IParameterized::createParameterTree()
{
    auto P_new_pool = new ParameterPool(this);
    addParametersToExternalPool("/", P_new_pool);
    return P_new_pool;
}

//! Copies local parameters to external_pool, under name "path/<name>copy_number/"

std::string IParameterized::addParametersToExternalPool(
    std::string path, ParameterPool* external_pool, int copy_number) const
{
    if( path[path.length()-1] != '/' )
        path += "/";
    std::ostringstream osCopyNumber;
    if(copy_number >=0)
        osCopyNumber << copy_number;
    path += getName() + osCopyNumber.str() + "/";

    // copy local parameter to external pool
    m_parameters->copyToExternalPool(path, external_pool);

    return path;
}

void IParameterized::printParameters()
{
    std::unique_ptr<ParameterPool> P_pool( createParameterTree() );
    std::cout << *P_pool << std::endl;
}

//! Register parameter address in the parameter pool; name allows for wildcard '*'
void IParameterized::registerParameter(const std::string& name, double* parpointer)
{
    m_parameters->registerParameter(name, parpointer, AttLimits::limitless());
}

//! Register parameter address in the parameter pool; name allows for wildcard '*'
void IParameterized::registerParameter(
    const std::string& name, double* parpointer, const AttLimits& limits)
{
    m_parameters->registerParameter(name, parpointer, limits);
}

void IParameterized::setParameterValue(const std::string& name, double value)
{
    if(name.find('*') == std::string::npos && name.find('/') == std::string::npos) {
        m_parameters->setParameterValue(name, value);
    } else {
        std::unique_ptr<ParameterPool> P_pool { createParameterTree() };
        if(name.find('*') != std::string::npos)
            P_pool->setMatchedParametersValue(name, value);
        else
            P_pool->setParameterValue(name, value);
    }
    onChange();
}

//! Returns parameter with given 'name'.
RealParameter* IParameterized::getParameter(const std::string& name) const {
    return m_parameters->getParameter(name);
}

void IParameterized::print(std::ostream& ostr) const
{
    ostr << "IParameterized:" << getName() << " " << *m_parameters;
}