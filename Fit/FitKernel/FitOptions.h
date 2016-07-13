// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Fit/FitKernel/FitOptions.h
//! @brief     Declares class FitOptions.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FITOPTIONS_H
#define FITOPTIONS_H

#include "WinDllMacros.h"
#include <iostream>
#include <iomanip>


//! @class FitOptions
//! @ingroup fitting
//! @brief General fitting options.

class BA_CORE_API_ FitOptions
{
 public:
    FitOptions();
    ~FitOptions(){}

    double getDerivEpsilon() const;
    void setDerivEpsilon(double deriv_epsilon);

    double getStepFactor() const;
    void setStepFactor(double step_factor);

 private:
    double m_deriv_epsilon;  //! epsilon for derivative calculation
    double m_step_factor; //! default relative parameter step
};

inline FitOptions::FitOptions()
    : m_deriv_epsilon(1e-09)
    , m_step_factor(0.01)
{
}

inline double FitOptions::getDerivEpsilon() const
{
    return m_deriv_epsilon;
}

inline void FitOptions::setDerivEpsilon(double deriv_epsilon)
{
    m_deriv_epsilon = deriv_epsilon;
}

inline double FitOptions::getStepFactor() const
{
    return m_step_factor;
}

inline void FitOptions::setStepFactor(double step_factor)
{
    m_step_factor = step_factor;
}



#endif // FITOPTIONS_H


