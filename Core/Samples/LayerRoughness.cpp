// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Samples/src/LayerRoughness.cpp
//! @brief     Implements class LayerRoughness.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Units.h"
#include "LayerRoughness.h"
#include "BornAgainNamespace.h"

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace BornAgain;

LayerRoughness::LayerRoughness()
: m_sigma(0)
, m_hurstParameter(0)
, m_latteralCorrLength(0)
{
    initialize();
}

LayerRoughness::LayerRoughness(double sigma, double hurstParameter, double latteralCorrLength)
: m_sigma(sigma)
, m_hurstParameter(hurstParameter)
, m_latteralCorrLength(latteralCorrLength)
{
    initialize();
}

LayerRoughness *LayerRoughness::clone() const
{
    return new LayerRoughness(m_sigma, m_hurstParameter, m_latteralCorrLength);
}

void LayerRoughness::init_parameters()
{
    clearParameterPool();
    registerParameter(Sigma, &m_sigma);
    registerParameter(Hurst, &m_hurstParameter);
    registerParameter(CorrelationLength, &m_latteralCorrLength);
}


/* ************************************************************************* */
//! Power spectral density of the surface roughness is a result of two-dimensional
//! Fourier transform of the correlation function of the roughness profile.
//!
//! Based on the article
//! D.K.G. de Boer, Physical review B, Volume 51, Number 8, 15 February 1995
//! "X-ray reflection and transmission by rough surfaces"
/* ************************************************************************* */
double LayerRoughness::getSpectralFun(const kvector_t& kvec) const
{
    double H = m_hurstParameter;
    double clength2 = m_latteralCorrLength*m_latteralCorrLength;
    double Qpar2 = kvec.x()*kvec.x() + kvec.y()*kvec.y();
    return 4.0*Units::PI*H * m_sigma*m_sigma * clength2 * std::pow( (1.0 + Qpar2*clength2), (-1-H) );
}

//! Correlation function of the roughness profile

double LayerRoughness::getCorrFun(const kvector_t& k) const
{
    double H = m_hurstParameter;
    double clength = m_latteralCorrLength;
    double R = sqrt(k.x()*k.x() + k.y()*k.y());
    return m_sigma*m_sigma*std::exp( -1.0*std::pow(R/clength, 2.*H) );
}

void LayerRoughness::setSigma(double sigma)
{
    m_sigma = sigma;
}

double LayerRoughness::getSigma() const
{
    return m_sigma;
}

void LayerRoughness::setHurstParameter(double hurstParameter)
{
    m_hurstParameter = hurstParameter;
}

double LayerRoughness::getHurstParameter() const
{
    return m_hurstParameter;
}

void LayerRoughness::setLatteralCorrLength(double latteralCorrLength)
{
    m_latteralCorrLength = latteralCorrLength;
}

double LayerRoughness::getLatteralCorrLength() const
{
    return m_latteralCorrLength;
}

std::ostream &operator<<(std::ostream &ostr, LayerRoughness &m)
{
    m.print(ostr);
    return ostr;
}

void LayerRoughness::print(std::ostream& ostr) const
{
    ISample::print(ostr);
    ostr << "-->LayerRoughness{ sigma=" << m_sigma << "}";
}

void LayerRoughness::initialize()
{
    setName(LayerBasicRoughnessType);
    init_parameters();
}