// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonCoreAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonCoreList.h"
#include "VariableBinAxis.pypp.h"

namespace bp = boost::python;

struct VariableBinAxis_wrapper : VariableBinAxis, bp::wrapper< VariableBinAxis > {

    VariableBinAxis_wrapper(VariableBinAxis const & arg )
    : VariableBinAxis( arg )
      , bp::wrapper< VariableBinAxis >(){
        // copy constructor
        
    }

    VariableBinAxis_wrapper(::std::string name, ::std::size_t nbins, ::std::vector< double > const & bin_edges )
    : VariableBinAxis( name, nbins, boost::ref(bin_edges) )
      , bp::wrapper< VariableBinAxis >(){
        // constructor
    
    }

    virtual ::VariableBinAxis * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else
            return this->VariableBinAxis::clone(  );
    }
    
    
    ::VariableBinAxis * default_clone(  ) const  {
        return VariableBinAxis::clone( );
    }

    virtual ::std::size_t findClosestIndex( double value ) const  {
        if( bp::override func_findClosestIndex = this->get_override( "findClosestIndex" ) )
            return func_findClosestIndex( value );
        else
            return this->VariableBinAxis::findClosestIndex( value );
    }
    
    
    ::std::size_t default_findClosestIndex( double value ) const  {
        return VariableBinAxis::findClosestIndex( value );
    }

    virtual ::Bin1D getBin( ::std::size_t index ) const  {
        if( bp::override func_getBin = this->get_override( "getBin" ) )
            return func_getBin( index );
        else
            return this->VariableBinAxis::getBin( index );
    }
    
    
    ::Bin1D default_getBin( ::std::size_t index ) const  {
        return VariableBinAxis::getBin( index );
    }

    virtual double getMax(  ) const  {
        if( bp::override func_getMax = this->get_override( "getMax" ) )
            return func_getMax(  );
        else
            return this->VariableBinAxis::getMax(  );
    }
    
    
    double default_getMax(  ) const  {
        return VariableBinAxis::getMax( );
    }

    virtual double getMin(  ) const  {
        if( bp::override func_getMin = this->get_override( "getMin" ) )
            return func_getMin(  );
        else
            return this->VariableBinAxis::getMin(  );
    }
    
    
    double default_getMin(  ) const  {
        return VariableBinAxis::getMin( );
    }

    virtual ::std::size_t getSize(  ) const  {
        if( bp::override func_getSize = this->get_override( "getSize" ) )
            return func_getSize(  );
        else
            return this->VariableBinAxis::getSize(  );
    }
    
    
    ::std::size_t default_getSize(  ) const  {
        return VariableBinAxis::getSize( );
    }

    virtual double operator[]( ::std::size_t index ) const  {
        if( bp::override func___getitem__ = this->get_override( "__getitem__" ) )
            return func___getitem__( index );
        else
            return this->VariableBinAxis::operator[]( index );
    }
    
    
    double default___getitem__( ::std::size_t index ) const  {
        return VariableBinAxis::operator[]( index );
    }

    virtual ::IAxis * createDoubleBinSize(  ) const  {
        if( bp::override func_createDoubleBinSize = this->get_override( "createDoubleBinSize" ) )
            return func_createDoubleBinSize(  );
        else
            return this->IAxis::createDoubleBinSize(  );
    }
    
    
    ::IAxis * default_createDoubleBinSize(  ) const  {
        return IAxis::createDoubleBinSize( );
    }

};

void register_VariableBinAxis_class(){

    { //::VariableBinAxis
        typedef bp::class_< VariableBinAxis_wrapper, bp::bases< IAxis > > VariableBinAxis_exposer_t;
        VariableBinAxis_exposer_t VariableBinAxis_exposer = VariableBinAxis_exposer_t( "VariableBinAxis", bp::init< std::string, std::size_t, std::vector< double > const & >(( bp::arg("name"), bp::arg("nbins"), bp::arg("bin_edges") )) );
        bp::scope VariableBinAxis_scope( VariableBinAxis_exposer );
        { //::VariableBinAxis::clone
        
            typedef ::VariableBinAxis * ( ::VariableBinAxis::*clone_function_type )(  ) const;
            typedef ::VariableBinAxis * ( VariableBinAxis_wrapper::*default_clone_function_type )(  ) const;
            
            VariableBinAxis_exposer.def( 
                "clone"
                , clone_function_type(&::VariableBinAxis::clone)
                , default_clone_function_type(&VariableBinAxis_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::VariableBinAxis::findClosestIndex
        
            typedef ::std::size_t ( ::VariableBinAxis::*findClosestIndex_function_type )( double ) const;
            typedef ::std::size_t ( VariableBinAxis_wrapper::*default_findClosestIndex_function_type )( double ) const;
            
            VariableBinAxis_exposer.def( 
                "findClosestIndex"
                , findClosestIndex_function_type(&::VariableBinAxis::findClosestIndex)
                , default_findClosestIndex_function_type(&VariableBinAxis_wrapper::default_findClosestIndex)
                , ( bp::arg("value") ) );
        
        }
        { //::VariableBinAxis::getBin
        
            typedef ::Bin1D ( ::VariableBinAxis::*getBin_function_type )( ::std::size_t ) const;
            typedef ::Bin1D ( VariableBinAxis_wrapper::*default_getBin_function_type )( ::std::size_t ) const;
            
            VariableBinAxis_exposer.def( 
                "getBin"
                , getBin_function_type(&::VariableBinAxis::getBin)
                , default_getBin_function_type(&VariableBinAxis_wrapper::default_getBin)
                , ( bp::arg("index") ) );
        
        }
        { //::VariableBinAxis::getMax
        
            typedef double ( ::VariableBinAxis::*getMax_function_type )(  ) const;
            typedef double ( VariableBinAxis_wrapper::*default_getMax_function_type )(  ) const;
            
            VariableBinAxis_exposer.def( 
                "getMax"
                , getMax_function_type(&::VariableBinAxis::getMax)
                , default_getMax_function_type(&VariableBinAxis_wrapper::default_getMax) );
        
        }
        { //::VariableBinAxis::getMin
        
            typedef double ( ::VariableBinAxis::*getMin_function_type )(  ) const;
            typedef double ( VariableBinAxis_wrapper::*default_getMin_function_type )(  ) const;
            
            VariableBinAxis_exposer.def( 
                "getMin"
                , getMin_function_type(&::VariableBinAxis::getMin)
                , default_getMin_function_type(&VariableBinAxis_wrapper::default_getMin) );
        
        }
        { //::VariableBinAxis::getSize
        
            typedef ::std::size_t ( ::VariableBinAxis::*getSize_function_type )(  ) const;
            typedef ::std::size_t ( VariableBinAxis_wrapper::*default_getSize_function_type )(  ) const;
            
            VariableBinAxis_exposer.def( 
                "getSize"
                , getSize_function_type(&::VariableBinAxis::getSize)
                , default_getSize_function_type(&VariableBinAxis_wrapper::default_getSize) );
        
        }
        { //::VariableBinAxis::operator[]
        
            typedef double ( ::VariableBinAxis::*__getitem___function_type )( ::std::size_t ) const;
            typedef double ( VariableBinAxis_wrapper::*default___getitem___function_type )( ::std::size_t ) const;
            
            VariableBinAxis_exposer.def( 
                "__getitem__"
                , __getitem___function_type(&::VariableBinAxis::operator[])
                , default___getitem___function_type(&VariableBinAxis_wrapper::default___getitem__)
                , ( bp::arg("index") ) );
        
        }
        { //::IAxis::createDoubleBinSize
        
            typedef ::IAxis * ( ::IAxis::*createDoubleBinSize_function_type )(  ) const;
            typedef ::IAxis * ( VariableBinAxis_wrapper::*default_createDoubleBinSize_function_type )(  ) const;
            
            VariableBinAxis_exposer.def( 
                "createDoubleBinSize"
                , createDoubleBinSize_function_type(&::IAxis::createDoubleBinSize)
                , default_createDoubleBinSize_function_type(&VariableBinAxis_wrapper::default_createDoubleBinSize)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
    }

}
