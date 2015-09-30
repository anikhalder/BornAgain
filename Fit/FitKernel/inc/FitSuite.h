// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FitKernel/inc/FitSuite.h
//! @brief     Defines class FitSuite.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FITSUITE_H
#define FITSUITE_H

#include "AttFitting.h"
#include "FitSuiteFunctions.h"
#include "FitSuiteObjects.h"
#include "FitSuiteParameters.h"
#include "FitSuiteStrategies.h"
#include "IMinimizer.h"
#include "IObserver.h"
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>

class GISASSimulation;
class ParameterPool;


//! @class FitSuite
//! @ingroup fitting
//! @brief Main class to perform fitting

class BA_CORE_API_ FitSuite : public IObservable
{
 public:
    FitSuite();
    virtual ~FitSuite();

    //! clear all and prepare for the next fit
    void clear();

    //! Adds pair of (simulation, real data) for consecutive simulation
    void addSimulationAndRealData(
        const GISASSimulation& simulation,
        const OutputData<double>& real_data,
        const IChiSquaredModule& chi2_module=ChiSquaredModule());

    //! Adds fit parameter
    void addFitParameter(const std::string& name, double value, double step, const AttLimits& attlim=AttLimits::limitless(), double error=0.0);
    void addFitParameter(const std::string& name, double value, const AttLimits& attlim=AttLimits::limitless(), double error=0.0);

    //! Adds fit strategy
    void addFitStrategy(IFitStrategy *strategy);
    void addFitStrategy(const IFitStrategy &strategy);

    //! Sets minimizer
    void setMinimizer(IMinimizer *minimizer);

    void setMinimizer(const std::string& minimizer, const std::string& algorithm = std::string(), const std::string& options=std::string());

    //! Returns minimizer
    IMinimizer *getMinimizer() { return m_minimizer; }



    //! link fitting parameters to parameters defined in simulations
    virtual void link_fit_parameters();

    //! run fitting which may consist of several minimization rounds
    virtual void runFit();

    //! run single minimization round
    virtual void minimize();

    //! Returns reference to the kit with data
    FitSuiteObjects *getFitObjects() { return& m_fit_objects; }

    //! Returns reference to fit parameters
    FitSuiteParameters *getFitParameters() { return& m_fit_parameters; }

    //! Returns reference to fit parameters
    FitSuiteStrategies *getFitStrategies() { return& m_fit_strategies; }

    //! if the last iteration is done (used by observers to print summary)
    bool isLastIteration() const { return m_is_last_iteration; }

    //! Returns current number of minimization function calls
    size_t getNCalls() const;

    //! Returns the number of current strategy
    size_t getNStrategy() const { return m_fit_strategies.getCurrentStrategyIndex(); }

    //! Prints results of the screen
    void printResults() const;

    //! set print level
    void initPrint(int print_every_nth);

    AttFitting &getAttributes() { return m_fit_attributes; }
    void setAttributes(const AttFitting &fit_attributes) { m_fit_attributes = fit_attributes; }

    //! Returns fit parameter with given name
    FitParameter *getFitParameter(const std::string &name);

    //! Set all parameters to fixed
    void fixAllParameters();

    //! Set all parameters to released
    void releaseAllParameters();

    //! Set fixed flag for parameters from the list
    void setParametersFixed(const std::vector<std::string> &pars, bool is_fixed);

    //! Returns total wall time in seconds which was spend for run fit
    double getRunTime() const;

 private:
    //! disabled copy constructor and assignment operator
    FitSuite& operator=(const FitSuite& );
    FitSuite(const FitSuite& );

    //! Checks if all prerequisites to run fit fit are filled
    bool check_prerequisites() const;

    AttFitting m_fit_attributes; //! general fit attributes
    FitSuiteObjects m_fit_objects; //! kit which contains sets of <simulation,real_data,chi_module> to fit
    FitSuiteParameters m_fit_parameters; //! collection of fit parameters
    FitSuiteStrategies m_fit_strategies; //! collection of strategies which drives multiple minimization rounds
    IMinimizer  *m_minimizer; //! minimization engine
    FitSuiteChiSquaredFunction m_function_chi2;
    FitSuiteGradientFunction m_function_gradient;

    bool m_is_last_iteration; //! Sets to true after last iteration complete

    boost::posix_time::ptime m_start_time;
    boost::posix_time::ptime m_end_time;
};

#endif // FITSUITE_H


