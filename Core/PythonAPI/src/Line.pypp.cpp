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
#include "PythonCoreList.h"
#include "Line.pypp.h"

namespace bp = boost::python;

struct Line_wrapper : Geometry::Line, bp::wrapper< Geometry::Line > {

    Line_wrapper(double x1, double y1, double x2, double y2 )
    : Geometry::Line( x1, y1, x2, y2 )
      , bp::wrapper< Geometry::Line >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::Geometry::Line * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->Geometry::Line::clone(  );
        }
    }
    
    ::Geometry::Line * default_clone(  ) const  {
        return Geometry::Line::clone( );
    }

    virtual bool contains( double x, double y ) const  {
        if( bp::override func_contains = this->get_override( "contains" ) )
            return func_contains( x, y );
        else{
            return this->Geometry::Line::contains( x, y );
        }
    }
    
    bool default_contains( double x, double y ) const  {
        return Geometry::Line::contains( x, y );
    }

    virtual bool contains( ::Bin1D const & binx, ::Bin1D const & biny ) const  {
        if( bp::override func_contains = this->get_override( "contains" ) )
            return func_contains( boost::ref(binx), boost::ref(biny) );
        else{
            return this->Geometry::Line::contains( boost::ref(binx), boost::ref(biny) );
        }
    }
    
    bool default_contains( ::Bin1D const & binx, ::Bin1D const & biny ) const  {
        return Geometry::Line::contains( boost::ref(binx), boost::ref(biny) );
    }

    virtual void transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        if( bp::override func_transferToCPP = this->get_override( "transferToCPP" ) )
            func_transferToCPP(  );
        else{
            this->ICloneable::transferToCPP(  );
        }
    }
    
    void default_transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        ICloneable::transferToCPP( );
    }

    PyObject* m_pyobj;

};

void register_Line_class(){

    { //::Geometry::Line
        typedef bp::class_< Line_wrapper, bp::bases< Geometry::IShape2D >, std::auto_ptr< Line_wrapper >, boost::noncopyable > Line_exposer_t;
        Line_exposer_t Line_exposer = Line_exposer_t( "Line", "The line segmen.", bp::init< double, double, double, double >(( bp::arg("x1"), bp::arg("y1"), bp::arg("x2"), bp::arg("y2") ), "Line segment constructor.") );
        bp::scope Line_scope( Line_exposer );
        { //::Geometry::Line::clone
        
            typedef ::Geometry::Line * ( ::Geometry::Line::*clone_function_type)(  ) const;
            typedef ::Geometry::Line * ( Line_wrapper::*default_clone_function_type)(  ) const;
            
            Line_exposer.def( 
                "clone"
                , clone_function_type(&::Geometry::Line::clone)
                , default_clone_function_type(&Line_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::Geometry::Line::contains
        
            typedef bool ( ::Geometry::Line::*contains_function_type)( double,double ) const;
            typedef bool ( Line_wrapper::*default_contains_function_type)( double,double ) const;
            
            Line_exposer.def( 
                "contains"
                , contains_function_type(&::Geometry::Line::contains)
                , default_contains_function_type(&Line_wrapper::default_contains)
                , ( bp::arg("x"), bp::arg("y") ) );
        
        }
        { //::Geometry::Line::contains
        
            typedef bool ( ::Geometry::Line::*contains_function_type)( ::Bin1D const &,::Bin1D const & ) const;
            typedef bool ( Line_wrapper::*default_contains_function_type)( ::Bin1D const &,::Bin1D const & ) const;
            
            Line_exposer.def( 
                "contains"
                , contains_function_type(&::Geometry::Line::contains)
                , default_contains_function_type(&Line_wrapper::default_contains)
                , ( bp::arg("binx"), bp::arg("biny") ) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( Line_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            Line_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&Line_wrapper::default_transferToCPP) );
        
        }
    }

}