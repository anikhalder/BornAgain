// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Multilayer/ScalarSpecularInfoMap.h
//! @brief     Declares class ScalarSpecularInfoMap.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef SCALARSPECULARINFOMAP_H
#define SCALARSPECULARINFOMAP_H

#include "ISpecularInfoMap.h"
#include "Vectors3D.h"

//! @class ScalarSpecularInfoMap
//! @ingroup algorithms_internal
//! @brief Implementation of ISpecularInfoMap for scalar valued reflection/
//! transmission coefficients

class BA_CORE_API_ ScalarSpecularInfoMap : public ISpecularInfoMap
{
public:
    ScalarSpecularInfoMap(const class MultiLayer* multilayer, int layer);
    virtual ~ScalarSpecularInfoMap() {}

    virtual ScalarSpecularInfoMap* clone() const;

    //! Retrieves the amplitude coefficients for the given angles
    virtual const class ILayerRTCoefficients* getOutCoefficients(
        double alpha_f, double phi_f, double wavelength) const;

    //! Retrieves the amplitude coefficients for the given angles
    virtual const class ILayerRTCoefficients* getInCoefficients(
        double alpha_i, double phi_i, double wavelength) const;
private:
    const class MultiLayer* mp_multilayer;
    const int m_layer;
    const class ScalarRTCoefficients* getCoefficients(kvector_t kvec) const;
};

#endif // SCALARSPECULARINFOMAP_H
