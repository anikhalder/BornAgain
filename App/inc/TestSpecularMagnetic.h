// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      App/inc/TestSpecularMagnetic.h
//! @brief     Defines class TestSpecularMagnetic.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef TESTSPECULARMAGNETIC_H_
#define TESTSPECULARMAGNETIC_H_

#include "IFunctionalTest.h"
#include "SpecularMagnetic.h"
#include "MultiLayer.h"
#include "OutputData.h"

//! Returns amplitudes for different wave components and polarizations using
//! the magnetic matrix formalism for a typical multilayer sample and produce
//! validation plots

class TestSpecularMagnetic : public IFunctionalTest
{
public:
    TestSpecularMagnetic();

    void execute();

private:
    //! Returns amplitudes vs. alpha_i for several standard samples
    void test_standard_sample();
    //! draw results of the test
    void draw_standard_sample();

    MultiLayer *mp_sample; //!< pointer to multilayer sample
    OutputData<SpecularMagnetic::MultiLayerCoeff_t  >
        *mp_coeffs; //!< output data structure
};

#endif /* TESTSPECULARMAGNETIC_H_ */
