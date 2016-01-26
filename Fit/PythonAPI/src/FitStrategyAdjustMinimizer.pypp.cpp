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
#include "FitStrategyAdjustMinimizer.pypp.h"

namespace bp = boost::python;

struct FitStrategyAdjustMinimizer_wrapper : FitStrategyAdjustMinimizer, bp::wrapper< FitStrategyAdjustMinimizer > {

    FitStrategyAdjustMinimizer_wrapper(FitStrategyAdjustMinimizer const & arg )
    : FitStrategyAdjustMinimizer( arg )
      , bp::wrapper< FitStrategyAdjustMinimizer >(){
        // copy constructor
        m_pyobj = 0;
    }

    FitStrategyAdjustMinimizer_wrapper( )
    : FitStrategyAdjustMinimizer( )
      , bp::wrapper< FitStrategyAdjustMinimizer >(){
        // null constructor
    m_pyobj = 0;
    }

    FitStrategyAdjustMinimizer_wrapper(::std::string const & minimizer_name, ::std::string const & algorithm_name=std::basic_string<char, std::char_traits<char>, std::allocator<char> >(), ::std::string const & minimizer_options=std::basic_string<char, std::char_traits<char>, std::allocator<char> >() )
    : FitStrategyAdjustMinimizer( minimizer_name, algorithm_name, minimizer_options )
      , bp::wrapper< FitStrategyAdjustMinimizer >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::FitStrategyAdjustMinimizer * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FitStrategyAdjustMinimizer::clone(  );
        }
    }
    
    ::FitStrategyAdjustMinimizer * default_clone(  ) const  {
        return FitStrategyAdjustMinimizer::clone( );
    }

    virtual void execute(  ) {
        if( bp::override func_execute = this->get_override( "execute" ) )
            func_execute(  );
        else{
            this->FitStrategyAdjustMinimizer::execute(  );
        }
    }
    
    void default_execute(  ) {
        FitStrategyAdjustMinimizer::execute( );
    }

    virtual ::MinimizerOptions * getMinimizerOptions(  ) {
        if( bp::override func_getMinimizerOptions = this->get_override( "getMinimizerOptions" ) )
            return func_getMinimizerOptions(  );
        else{
            return this->FitStrategyAdjustMinimizer::getMinimizerOptions(  );
        }
    }
    
    ::MinimizerOptions * default_getMinimizerOptions(  ) {
        return FitStrategyAdjustMinimizer::getMinimizerOptions( );
    }

    PyObject* m_pyobj;

};

void register_FitStrategyAdjustMinimizer_class(){

    { //::FitStrategyAdjustMinimizer
        typedef bp::class_< FitStrategyAdjustMinimizer_wrapper, bp::bases< IFitStrategy >, std::auto_ptr< FitStrategyAdjustMinimizer_wrapper > > FitStrategyAdjustMinimizer_exposer_t;
        FitStrategyAdjustMinimizer_exposer_t FitStrategyAdjustMinimizer_exposer = FitStrategyAdjustMinimizer_exposer_t( "FitStrategyAdjustMinimizer", "Strategy modifies mimimizer settings before running minimization roun.", bp::init< >() );
        bp::scope FitStrategyAdjustMinimizer_scope( FitStrategyAdjustMinimizer_exposer );
        FitStrategyAdjustMinimizer_exposer.def( bp::init< std::string const &, bp::optional< std::string const &, std::string const & > >(( bp::arg("minimizer_name"), bp::arg("algorithm_name")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >(), bp::arg("minimizer_options")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >() )) );
        { //::FitStrategyAdjustMinimizer::clone
        
            typedef ::FitStrategyAdjustMinimizer * ( ::FitStrategyAdjustMinimizer::*clone_function_type)(  ) const;
            typedef ::FitStrategyAdjustMinimizer * ( FitStrategyAdjustMinimizer_wrapper::*default_clone_function_type)(  ) const;
            
            FitStrategyAdjustMinimizer_exposer.def( 
                "clone"
                , clone_function_type(&::FitStrategyAdjustMinimizer::clone)
                , default_clone_function_type(&FitStrategyAdjustMinimizer_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FitStrategyAdjustMinimizer::execute
        
            typedef void ( ::FitStrategyAdjustMinimizer::*execute_function_type)(  ) ;
            typedef void ( FitStrategyAdjustMinimizer_wrapper::*default_execute_function_type)(  ) ;
            
            FitStrategyAdjustMinimizer_exposer.def( 
                "execute"
                , execute_function_type(&::FitStrategyAdjustMinimizer::execute)
                , default_execute_function_type(&FitStrategyAdjustMinimizer_wrapper::default_execute) );
        
        }
        { //::FitStrategyAdjustMinimizer::getMinimizer
        
            typedef ::IMinimizer * ( ::FitStrategyAdjustMinimizer::*getMinimizer_function_type)(  ) ;
            
            FitStrategyAdjustMinimizer_exposer.def( 
                "getMinimizer"
                , getMinimizer_function_type( &::FitStrategyAdjustMinimizer::getMinimizer )
                , bp::return_internal_reference< >() );
        
        }
        { //::FitStrategyAdjustMinimizer::getMinimizerOptions
        
            typedef ::MinimizerOptions * ( ::FitStrategyAdjustMinimizer::*getMinimizerOptions_function_type)(  ) ;
            typedef ::MinimizerOptions * ( FitStrategyAdjustMinimizer_wrapper::*default_getMinimizerOptions_function_type)(  ) ;
            
            FitStrategyAdjustMinimizer_exposer.def( 
                "getMinimizerOptions"
                , getMinimizerOptions_function_type(&::FitStrategyAdjustMinimizer::getMinimizerOptions)
                , default_getMinimizerOptions_function_type(&FitStrategyAdjustMinimizer_wrapper::default_getMinimizerOptions)
                , bp::return_internal_reference< >() );
        
        }
        { //::FitStrategyAdjustMinimizer::setMinimizer
        
            typedef void ( ::FitStrategyAdjustMinimizer::*setMinimizer_function_type)( ::std::string const &,::std::string const &,::std::string const & ) ;
            
            FitStrategyAdjustMinimizer_exposer.def( 
                "setMinimizer"
                , setMinimizer_function_type( &::FitStrategyAdjustMinimizer::setMinimizer )
                , ( bp::arg("minimizer_name"), bp::arg("algorithm_name")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >(), bp::arg("minimizer_options")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >() ) );
        
        }
    }

}
