// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/Core/CoreTest.h
//! @brief     Declares class CoreTest.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef CORETEST_H
#define CORETEST_H

#include "IFunctionalTest.h" // inheriting from

template <class T> class OutputData;
class GISASSimulation;

//! @class CoreTest
//! @ingroup standard_samples
//! @brief A functional test of BornAgain/Core.
//!   Performs a given standard simulation, and compares results with reference data.
//!   Invoked from CoreStandardTest.

class CoreTest : public IFunctionalTest
{
public:
    CoreTest(
        const std::string& name, const std::string& description, GISASSimulation* simulation,
        double threshold);
    virtual ~CoreTest();

    virtual void runTest();
    virtual int analyseResults();
    virtual void printResults(std::ostream& ostr) const;

private:
    std::string getSimulationResultsFileNameAndPath() const;
    OutputData<double>* getIntensityData() const;

    GISASSimulation* m_simulation;
    double m_threshold;
    OutputData<double>* m_reference;
    double m_difference;
    std::string m_ref_filename;
};

#endif // CORETEST_H