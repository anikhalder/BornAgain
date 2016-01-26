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
#include "IParticle.pypp.h"

namespace bp = boost::python;

struct IParticle_wrapper : IParticle, bp::wrapper< IParticle > {

    virtual ::IParticle * clone(  ) const {
        bp::override func_clone = this->get_override( "clone" );
        return func_clone(  );
    }

    virtual ::IParticle * cloneInvertB(  ) const {
        bp::override func_cloneInvertB = this->get_override( "cloneInvertB" );
        return func_cloneInvertB(  );
    }

    virtual ::IFormFactor * createTransformedFormFactor( ::complex_t wavevector_scattering_factor, ::IRotation const * p_rotation, ::kvector_t translation ) const {
        bp::override func_createTransformedFormFactor = this->get_override( "createTransformedFormFactor" );
        return func_createTransformedFormFactor( wavevector_scattering_factor, boost::python::ptr(p_rotation), translation );
    }

    virtual bool containsMagneticMaterial(  ) const  {
        if( bp::override func_containsMagneticMaterial = this->get_override( "containsMagneticMaterial" ) )
            return func_containsMagneticMaterial(  );
        else{
            return this->ISample::containsMagneticMaterial(  );
        }
    }
    
    bool default_containsMagneticMaterial(  ) const  {
        return ISample::containsMagneticMaterial( );
    }

    virtual ::IMaterial const * getAmbientMaterial(  ) const {
        bp::override func_getAmbientMaterial = this->get_override( "getAmbientMaterial" );
        return func_getAmbientMaterial(  );
    }

    virtual ::std::vector< const ISample* > getChildren(  ) const  {
        if( bp::override func_getChildren = this->get_override( "getChildren" ) )
            return func_getChildren(  );
        else{
            return this->ICompositeSample::getChildren(  );
        }
    }
    
    ::std::vector< const ISample* > default_getChildren(  ) const  {
        return ICompositeSample::getChildren( );
    }

    virtual void printSampleTree(  ) {
        if( bp::override func_printSampleTree = this->get_override( "printSampleTree" ) )
            func_printSampleTree(  );
        else{
            this->ISample::printSampleTree(  );
        }
    }
    
    void default_printSampleTree(  ) {
        ISample::printSampleTree( );
    }

    virtual void setAmbientMaterial( ::IMaterial const & material ) {
        if( bp::override func_setAmbientMaterial = this->get_override( "setAmbientMaterial" ) )
            func_setAmbientMaterial( boost::ref(material) );
        else{
            this->IAbstractParticle::setAmbientMaterial( boost::ref(material) );
        }
    }
    
    void default_setAmbientMaterial( ::IMaterial const & material ) {
        IAbstractParticle::setAmbientMaterial( boost::ref(material) );
    }

    virtual ::std::size_t size(  ) const  {
        if( bp::override func_size = this->get_override( "size" ) )
            return func_size(  );
        else{
            return this->ICompositeSample::size(  );
        }
    }
    
    ::std::size_t default_size(  ) const  {
        return ICompositeSample::size( );
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

void register_IParticle_class(){

    { //::IParticle
        typedef bp::class_< IParticle_wrapper, bp::bases< IAbstractParticle >, std::auto_ptr< IParticle_wrapper >, boost::noncopyable > IParticle_exposer_t;
        IParticle_exposer_t IParticle_exposer = IParticle_exposer_t( "IParticle", "Interface for a real particle (one that has position/rotation and form factor.", bp::no_init );
        bp::scope IParticle_scope( IParticle_exposer );
        { //::IParticle::applyRotation
        
            typedef void ( ::IParticle::*applyRotation_function_type)( ::IRotation const & ) ;
            
            IParticle_exposer.def( 
                "applyRotation"
                , applyRotation_function_type( &::IParticle::applyRotation )
                , ( bp::arg("rotation") )
                , "Applies transformation by composing it with the existing one." );
        
        }
        { //::IParticle::applyTranslation
        
            typedef void ( ::IParticle::*applyTranslation_function_type)( ::kvector_t ) ;
            
            IParticle_exposer.def( 
                "applyTranslation"
                , applyTranslation_function_type( &::IParticle::applyTranslation )
                , ( bp::arg("displacement") )
                , "Applies extra translation by adding it to the current one." );
        
        }
        { //::IParticle::clone
        
            typedef ::IParticle * ( ::IParticle::*clone_function_type)(  ) const;
            
            IParticle_exposer.def( 
                "clone"
                , bp::pure_virtual( clone_function_type(&::IParticle::clone) )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParticle::cloneInvertB
        
            typedef ::IParticle * ( ::IParticle::*cloneInvertB_function_type)(  ) const;
            
            IParticle_exposer.def( 
                "cloneInvertB"
                , bp::pure_virtual( cloneInvertB_function_type(&::IParticle::cloneInvertB) )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "Returns a clone with inverted magnetic fields." );
        
        }
        { //::IParticle::createFormFactor
        
            typedef ::IFormFactor * ( ::IParticle::*createFormFactor_function_type)( ::complex_t ) const;
            
            IParticle_exposer.def( 
                "createFormFactor"
                , createFormFactor_function_type( &::IParticle::createFormFactor )
                , ( bp::arg("wavevector_scattering_factor") )
                , bp::return_value_policy< bp::manage_new_object >()
                , "Create a form factor for this particle with an extra scattering factor." );
        
        }
        { //::IParticle::createTransformedFormFactor
        
            typedef ::IFormFactor * ( ::IParticle::*createTransformedFormFactor_function_type)( ::complex_t,::IRotation const *,::kvector_t ) const;
            
            IParticle_exposer.def( 
                "createTransformedFormFactor"
                , bp::pure_virtual( createTransformedFormFactor_function_type(&::IParticle::createTransformedFormFactor) )
                , ( bp::arg("wavevector_scattering_factor"), bp::arg("p_rotation"), bp::arg("translation") )
                , bp::return_value_policy< bp::manage_new_object >()
                , "Create a form factor for this particle with an extra scattering factor." );
        
        }
        { //::IParticle::getPosition
        
            typedef ::kvector_t ( ::IParticle::*getPosition_function_type)(  ) const;
            
            IParticle_exposer.def( 
                "getPosition"
                , getPosition_function_type( &::IParticle::getPosition ) );
        
        }
        { //::IParticle::getRotation
        
            typedef ::IRotation const * ( ::IParticle::*getRotation_function_type)(  ) const;
            
            IParticle_exposer.def( 
                "getRotation"
                , getRotation_function_type( &::IParticle::getRotation )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IParticle::setPosition
        
            typedef void ( ::IParticle::*setPosition_function_type)( ::kvector_t ) ;
            
            IParticle_exposer.def( 
                "setPosition"
                , setPosition_function_type( &::IParticle::setPosition )
                , ( bp::arg("position") ) );
        
        }
        { //::IParticle::setPosition
        
            typedef void ( ::IParticle::*setPosition_function_type)( double,double,double ) ;
            
            IParticle_exposer.def( 
                "setPosition"
                , setPosition_function_type( &::IParticle::setPosition )
                , ( bp::arg("x"), bp::arg("y"), bp::arg("z") ) );
        
        }
        { //::IParticle::setRotation
        
            typedef void ( ::IParticle::*setRotation_function_type)( ::IRotation const & ) ;
            
            IParticle_exposer.def( 
                "setRotation"
                , setRotation_function_type( &::IParticle::setRotation )
                , ( bp::arg("rotation") )
                , "Sets transformation." );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type)(  ) const;
            typedef bool ( IParticle_wrapper::*default_containsMagneticMaterial_function_type)(  ) const;
            
            IParticle_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&IParticle_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::IAbstractParticle::getAmbientMaterial
        
            typedef ::IMaterial const * ( ::IAbstractParticle::*getAmbientMaterial_function_type)(  ) const;
            
            IParticle_exposer.def( 
                "getAmbientMaterial"
                , bp::pure_virtual( getAmbientMaterial_function_type(&::IAbstractParticle::getAmbientMaterial) )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "Returns particle's material." );
        
        }
        { //::ICompositeSample::getChildren
        
            typedef ::std::vector< const ISample* > ( ::ICompositeSample::*getChildren_function_type)(  ) const;
            typedef ::std::vector< const ISample* > ( IParticle_wrapper::*default_getChildren_function_type)(  ) const;
            
            IParticle_exposer.def( 
                "getChildren"
                , getChildren_function_type(&::ICompositeSample::getChildren)
                , default_getChildren_function_type(&IParticle_wrapper::default_getChildren) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type)(  ) ;
            typedef void ( IParticle_wrapper::*default_printSampleTree_function_type)(  ) ;
            
            IParticle_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&IParticle_wrapper::default_printSampleTree) );
        
        }
        { //::IAbstractParticle::setAmbientMaterial
        
            typedef void ( ::IAbstractParticle::*setAmbientMaterial_function_type)( ::IMaterial const & ) ;
            typedef void ( IParticle_wrapper::*default_setAmbientMaterial_function_type)( ::IMaterial const & ) ;
            
            IParticle_exposer.def( 
                "setAmbientMaterial"
                , setAmbientMaterial_function_type(&::IAbstractParticle::setAmbientMaterial)
                , default_setAmbientMaterial_function_type(&IParticle_wrapper::default_setAmbientMaterial)
                , ( bp::arg("material") ) );
        
        }
        { //::ICompositeSample::size
        
            typedef ::std::size_t ( ::ICompositeSample::*size_function_type)(  ) const;
            typedef ::std::size_t ( IParticle_wrapper::*default_size_function_type)(  ) const;
            
            IParticle_exposer.def( 
                "size"
                , size_function_type(&::ICompositeSample::size)
                , default_size_function_type(&IParticle_wrapper::default_size) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( IParticle_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            IParticle_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&IParticle_wrapper::default_transferToCPP) );
        
        }
    }

}
