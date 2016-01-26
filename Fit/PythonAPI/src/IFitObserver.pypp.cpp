// This file has been generated by Py++.

// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Automatically generated boost::python code for BornAgain Python bindings
//! @brief     Automatically generated boost::python code for BornAgain Python bindings
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Juelich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonFitList.h"
#include "IFitObserver.pypp.h"

namespace bp = boost::python;

struct IFitObserver_wrapper : IFitObserver, bp::wrapper< IFitObserver > {

    IFitObserver_wrapper(IFitObserver const & arg )
    : IFitObserver( arg )
      , bp::wrapper< IFitObserver >(){
        // copy constructor
        
    }

    IFitObserver_wrapper(int update_every_nth )
    : IFitObserver( update_every_nth )
      , bp::wrapper< IFitObserver >(){
        // constructor
    
    }

    virtual void update( ::FitSuite * fit_suite ) {
        if( bp::override func_update = this->get_override( "update" ) )
            func_update( boost::python::ptr(fit_suite) );
        else{
            this->IFitObserver::update( boost::python::ptr(fit_suite) );
        }
    }
    
    void default_update( ::FitSuite * fit_suite ) {
        IFitObserver::update( boost::python::ptr(fit_suite) );
    }

};

void register_IFitObserver_class(){

    { //::IFitObserver
        typedef bp::class_< IFitObserver_wrapper, bp::bases< IObserver > > IFitObserver_exposer_t;
        IFitObserver_exposer_t IFitObserver_exposer = IFitObserver_exposer_t( "IFitObserver", bp::init< int >(( bp::arg("update_every_nth") )) );
        bp::scope IFitObserver_scope( IFitObserver_exposer );
        { //::IFitObserver::update
        
            typedef void ( ::IFitObserver::*update_function_type)( ::FitSuite * ) ;
            typedef void ( IFitObserver_wrapper::*default_update_function_type)( ::FitSuite * ) ;
            
            IFitObserver_exposer.def( 
                "update"
                , update_function_type(&::IFitObserver::update)
                , default_update_function_type(&IFitObserver_wrapper::default_update)
                , ( bp::arg("fit_suite") ) );
        
        }
    }

}
