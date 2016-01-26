// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FormFactors/inc/FormFactorDecoratorMultiPositionFactor.h
//! @brief     Defines class FormFactorDecoratorMultiPositionFactor.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FORMFACTORDECORATORMULTIPOSITIONFACTOR_H_
#define FORMFACTORDECORATORMULTIPOSITIONFACTOR_H_

#include "IFormFactorDecorator.h"

//! @class FormFactorDecoratorMultiPositionFactor
//! @ingroup formfactors_internal
//! @brief The formfactor for the same particle at different fixed positions.

class BA_CORE_API_ FormFactorDecoratorMultiPositionFactor : public IFormFactorDecorator
{
public:
    FormFactorDecoratorMultiPositionFactor(const IFormFactor &form_factor,
                                           std::vector<kvector_t> positions);

    virtual FormFactorDecoratorMultiPositionFactor *clone() const;

    virtual void accept(ISampleVisitor *visitor) const;

    virtual double getVolume() const;

    virtual double getRadius() const;

    virtual complex_t evaluate(const WavevectorInfo& wavevectors) const;

#ifndef GCCXML_SKIP_THIS
    virtual Eigen::Matrix2cd evaluatePol(const WavevectorInfo& wavevectors) const;
#endif

private:
    complex_t getPositionsFactor(const cvector_t &q) const;
    std::vector<kvector_t> m_positions;
};

#endif /* FORMFACTORDECORATORMULTIPOSITIONFACTOR_H_ */
