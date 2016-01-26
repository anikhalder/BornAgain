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
#include "OffSpecSimulation.pypp.h"

namespace bp = boost::python;

struct OffSpecSimulation_wrapper : OffSpecSimulation, bp::wrapper< OffSpecSimulation > {

    OffSpecSimulation_wrapper( )
    : OffSpecSimulation( )
      , bp::wrapper< OffSpecSimulation >(){
        // null constructor
    m_pyobj = 0;
    }

    virtual ::OffSpecSimulation * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->OffSpecSimulation::clone(  );
        }
    }
    
    ::OffSpecSimulation * default_clone(  ) const  {
        return OffSpecSimulation::clone( );
    }

    virtual ::OutputData< double > * getDetectorIntensity(  ) const  {
        if( bp::override func_getDetectorIntensity = this->get_override( "getDetectorIntensity" ) )
            return func_getDetectorIntensity(  );
        else{
            return this->OffSpecSimulation::getDetectorIntensity(  );
        }
    }
    
    ::OutputData< double > * default_getDetectorIntensity(  ) const  {
        return OffSpecSimulation::getDetectorIntensity( );
    }

    virtual int getNumberOfSimulationElements(  ) const  {
        if( bp::override func_getNumberOfSimulationElements = this->get_override( "getNumberOfSimulationElements" ) )
            return func_getNumberOfSimulationElements(  );
        else{
            return this->OffSpecSimulation::getNumberOfSimulationElements(  );
        }
    }
    
    int default_getNumberOfSimulationElements(  ) const  {
        return OffSpecSimulation::getNumberOfSimulationElements( );
    }

    virtual double getWavelength(  ) const  {
        if( bp::override func_getWavelength = this->get_override( "getWavelength" ) )
            return func_getWavelength(  );
        else{
            return this->OffSpecSimulation::getWavelength(  );
        }
    }
    
    double default_getWavelength(  ) const  {
        return OffSpecSimulation::getWavelength( );
    }

    virtual void prepareSimulation(  ) {
        if( bp::override func_prepareSimulation = this->get_override( "prepareSimulation" ) )
            func_prepareSimulation(  );
        else{
            this->OffSpecSimulation::prepareSimulation(  );
        }
    }
    
    void default_prepareSimulation(  ) {
        OffSpecSimulation::prepareSimulation( );
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

void register_OffSpecSimulation_class(){

    { //::OffSpecSimulation
        typedef bp::class_< OffSpecSimulation_wrapper, bp::bases< Simulation >, std::auto_ptr< OffSpecSimulation_wrapper >, boost::noncopyable > OffSpecSimulation_exposer_t;
        OffSpecSimulation_exposer_t OffSpecSimulation_exposer = OffSpecSimulation_exposer_t( "OffSpecSimulation", "Main class to run an off-specular simulation.", bp::init< >() );
        bp::scope OffSpecSimulation_scope( OffSpecSimulation_exposer );
        { //::OffSpecSimulation::clone
        
            typedef ::OffSpecSimulation * ( ::OffSpecSimulation::*clone_function_type)(  ) const;
            typedef ::OffSpecSimulation * ( OffSpecSimulation_wrapper::*default_clone_function_type)(  ) const;
            
            OffSpecSimulation_exposer.def( 
                "clone"
                , clone_function_type(&::OffSpecSimulation::clone)
                , default_clone_function_type(&OffSpecSimulation_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::OffSpecSimulation::getDetectorIntensity
        
            typedef ::OutputData< double > * ( ::OffSpecSimulation::*getDetectorIntensity_function_type)(  ) const;
            typedef ::OutputData< double > * ( OffSpecSimulation_wrapper::*default_getDetectorIntensity_function_type)(  ) const;
            
            OffSpecSimulation_exposer.def( 
                "getDetectorIntensity"
                , getDetectorIntensity_function_type(&::OffSpecSimulation::getDetectorIntensity)
                , default_getDetectorIntensity_function_type(&OffSpecSimulation_wrapper::default_getDetectorIntensity)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::OffSpecSimulation::getInstrument
        
            typedef ::Instrument const & ( ::OffSpecSimulation::*getInstrument_function_type)(  ) const;
            
            OffSpecSimulation_exposer.def( 
                "getInstrument"
                , getInstrument_function_type( &::OffSpecSimulation::getInstrument )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "Returns the instrument containing beam and detector information." );
        
        }
        { //::OffSpecSimulation::getIntensityData
        
            typedef ::Histogram2D * ( ::OffSpecSimulation::*getIntensityData_function_type)(  ) const;
            
            OffSpecSimulation_exposer.def( 
                "getIntensityData"
                , getIntensityData_function_type( &::OffSpecSimulation::getIntensityData )
                , bp::return_value_policy< bp::manage_new_object >()
                , "Returns clone of the detector intensity map in the form of 2D histogram." );
        
        }
        { //::OffSpecSimulation::getNumberOfSimulationElements
        
            typedef int ( ::OffSpecSimulation::*getNumberOfSimulationElements_function_type)(  ) const;
            typedef int ( OffSpecSimulation_wrapper::*default_getNumberOfSimulationElements_function_type)(  ) const;
            
            OffSpecSimulation_exposer.def( 
                "getNumberOfSimulationElements"
                , getNumberOfSimulationElements_function_type(&::OffSpecSimulation::getNumberOfSimulationElements)
                , default_getNumberOfSimulationElements_function_type(&OffSpecSimulation_wrapper::default_getNumberOfSimulationElements) );
        
        }
        { //::OffSpecSimulation::getWavelength
        
            typedef double ( ::OffSpecSimulation::*getWavelength_function_type)(  ) const;
            typedef double ( OffSpecSimulation_wrapper::*default_getWavelength_function_type)(  ) const;
            
            OffSpecSimulation_exposer.def( 
                "getWavelength"
                , getWavelength_function_type(&::OffSpecSimulation::getWavelength)
                , default_getWavelength_function_type(&OffSpecSimulation_wrapper::default_getWavelength) );
        
        }
        { //::OffSpecSimulation::prepareSimulation
        
            typedef void ( ::OffSpecSimulation::*prepareSimulation_function_type)(  ) ;
            typedef void ( OffSpecSimulation_wrapper::*default_prepareSimulation_function_type)(  ) ;
            
            OffSpecSimulation_exposer.def( 
                "prepareSimulation"
                , prepareSimulation_function_type(&::OffSpecSimulation::prepareSimulation)
                , default_prepareSimulation_function_type(&OffSpecSimulation_wrapper::default_prepareSimulation) );
        
        }
        { //::OffSpecSimulation::removeDetectorResolutionFunction
        
            typedef void ( ::OffSpecSimulation::*removeDetectorResolutionFunction_function_type)(  ) ;
            
            OffSpecSimulation_exposer.def( 
                "removeDetectorResolutionFunction"
                , removeDetectorResolutionFunction_function_type( &::OffSpecSimulation::removeDetectorResolutionFunction )
                , "Removes detector resolution function." );
        
        }
        { //::OffSpecSimulation::setAnalyzerProperties
        
            typedef void ( ::OffSpecSimulation::*setAnalyzerProperties_function_type)( ::kvector_t const &,double,double ) ;
            
            OffSpecSimulation_exposer.def( 
                "setAnalyzerProperties"
                , setAnalyzerProperties_function_type( &::OffSpecSimulation::setAnalyzerProperties )
                , ( bp::arg("direction"), bp::arg("efficiency"), bp::arg("total_transmission")=1.0e+0 )
                , "Sets the polarization analyzer characteristics of the detector." );
        
        }
        { //::OffSpecSimulation::setBeamIntensity
        
            typedef void ( ::OffSpecSimulation::*setBeamIntensity_function_type)( double ) ;
            
            OffSpecSimulation_exposer.def( 
                "setBeamIntensity"
                , setBeamIntensity_function_type( &::OffSpecSimulation::setBeamIntensity )
                , ( bp::arg("intensity") )
                , "Sets beam intensity from here (forwarded to Instrument)." );
        
        }
        { //::OffSpecSimulation::setBeamParameters
        
            typedef void ( ::OffSpecSimulation::*setBeamParameters_function_type)( double,::IAxis const &,double ) ;
            
            OffSpecSimulation_exposer.def( 
                "setBeamParameters"
                , setBeamParameters_function_type( &::OffSpecSimulation::setBeamParameters )
                , ( bp::arg("lambda"), bp::arg("alpha_axis"), bp::arg("phi_i") )
                , "Sets beam parameters from here (forwarded to Instrument)." );
        
        }
        { //::OffSpecSimulation::setBeamPolarization
        
            typedef void ( ::OffSpecSimulation::*setBeamPolarization_function_type)( ::kvector_t const & ) ;
            
            OffSpecSimulation_exposer.def( 
                "setBeamPolarization"
                , setBeamPolarization_function_type( &::OffSpecSimulation::setBeamPolarization )
                , ( bp::arg("bloch_vector") )
                , "Sets the beam polarization according to the given Bloch vector." );
        
        }
        { //::OffSpecSimulation::setDetectorParameters
        
            typedef void ( ::OffSpecSimulation::*setDetectorParameters_function_type)( ::OutputData< double > const & ) ;
            
            OffSpecSimulation_exposer.def( 
                "setDetectorParameters"
                , setDetectorParameters_function_type( &::OffSpecSimulation::setDetectorParameters )
                , ( bp::arg("output_data") )
                , "Sets detector parameters using axes of output data." );
        
        }
        { //::OffSpecSimulation::setDetectorParameters
        
            typedef void ( ::OffSpecSimulation::*setDetectorParameters_function_type)( ::std::size_t,double,double,::std::size_t,double,double ) ;
            
            OffSpecSimulation_exposer.def( 
                "setDetectorParameters"
                , setDetectorParameters_function_type( &::OffSpecSimulation::setDetectorParameters )
                , ( bp::arg("n_x"), bp::arg("x_min"), bp::arg("x_max"), bp::arg("n_y"), bp::arg("y_min"), bp::arg("y_max") )
                , "Sets detector parameters using angle ranges." );
        
        }
        { //::OffSpecSimulation::setDetectorResolutionFunction
        
            typedef void ( ::OffSpecSimulation::*setDetectorResolutionFunction_function_type)( ::IResolutionFunction2D const & ) ;
            
            OffSpecSimulation_exposer.def( 
                "setDetectorResolutionFunction"
                , setDetectorResolutionFunction_function_type( &::OffSpecSimulation::setDetectorResolutionFunction )
                , ( bp::arg("resolution_function") )
                , "Define resolution function for detector." );
        
        }
        { //::OffSpecSimulation::setInstrument
        
            typedef void ( ::OffSpecSimulation::*setInstrument_function_type)( ::Instrument const & ) ;
            
            OffSpecSimulation_exposer.def( 
                "setInstrument"
                , setInstrument_function_type( &::OffSpecSimulation::setInstrument )
                , ( bp::arg("instrument") )
                , "Sets the instrument containing beam and detector information." );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( OffSpecSimulation_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            OffSpecSimulation_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&OffSpecSimulation_wrapper::default_transferToCPP) );
        
        }
    }

}
