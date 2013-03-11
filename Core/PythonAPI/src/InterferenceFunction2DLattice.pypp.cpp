// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "BasicVector3D.h"
#include "Bin.h"
#include "Crystal.h"
#include "DiffuseParticleInfo.h"
#include "FTDistributions.h"
#include "FormFactorBox.h"
#include "FormFactorCrystal.h"
#include "FormFactorCylinder.h"
#include "FormFactorDecoratorDebyeWaller.h"
#include "FormFactorFullSphere.h"
#include "FormFactorGauss.h"
#include "FormFactorLorentz.h"
#include "FormFactorPrism3.h"
#include "FormFactorPyramid.h"
#include "FormFactorSphereGaussianRadius.h"
#include "HomogeneousMaterial.h"
#include "ICloneable.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "IDecoration.h"
#include "IFormFactor.h"
#include "IFormFactorBorn.h"
#include "IFormFactorDecorator.h"
#include "IInterferenceFunction.h"
#include "IMaterial.h"
#include "IParameterized.h"
#include "ISample.h"
#include "ISampleBuilder.h"
#include "ISelectionRule.h"
#include "ISingleton.h"
#include "Instrument.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "InterferenceFunction2DLattice.h"
#include "InterferenceFunction2DParaCrystal.h"
#include "InterferenceFunctionNone.h"
#include "Lattice.h"
#include "Lattice2DIFParameters.h"
#include "LatticeBasis.h"
#include "Layer.h"
#include "LayerDecorator.h"
#include "LayerRoughness.h"
#include "MaterialManager.h"
#include "MesoCrystal.h"
#include "MultiLayer.h"
#include "OpticalFresnel.h"
#include "ParameterPool.h"
#include "Particle.h"
#include "ParticleBuilder.h"
#include "ParticleCoreShell.h"
#include "ParticleDecoration.h"
#include "ParticleInfo.h"
#include "PositionParticleInfo.h"
#include "PythonOutputData.h"
#include "PythonPlusplusHelper.h"
#include "RealParameterWrapper.h"
#include "Simulation.h"
#include "SimulationParameters.h"
#include "IStochasticParameter.h"
#include "StochasticGaussian.h"
#include "StochasticSampledParameter.h"
#include "Transform3D.h"
#include "Types.h"
#include "Units.h"
#include "InterferenceFunction2DLattice.pypp.h"

namespace bp = boost::python;

struct InterferenceFunction2DLattice_wrapper : InterferenceFunction2DLattice, bp::wrapper< InterferenceFunction2DLattice > {

    InterferenceFunction2DLattice_wrapper(::Lattice2DIFParameters const & lattice_params )
    : InterferenceFunction2DLattice( boost::ref(lattice_params) )
      , bp::wrapper< InterferenceFunction2DLattice >(){
        // constructor
    
    }

    virtual ::InterferenceFunction2DLattice * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->InterferenceFunction2DLattice::clone(  );
        }
    }
    
    ::InterferenceFunction2DLattice * default_clone(  ) const  {
        return InterferenceFunction2DLattice::clone( );
    }

    virtual double evaluate( ::cvector_t const & q ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( boost::ref(q) );
        else{
            return this->InterferenceFunction2DLattice::evaluate( boost::ref(q) );
        }
    }
    
    double default_evaluate( ::cvector_t const & q ) const  {
        return InterferenceFunction2DLattice::evaluate( boost::ref(q) );
    }

    virtual bool areParametersChanged(  ) {
        if( bp::override func_areParametersChanged = this->get_override( "areParametersChanged" ) )
            return func_areParametersChanged(  );
        else{
            return this->IParameterized::areParametersChanged(  );
        }
    }
    
    bool default_areParametersChanged(  ) {
        return IParameterized::areParametersChanged( );
    }

    virtual ::ParameterPool * createParameterTree(  ) const  {
        if( bp::override func_createParameterTree = this->get_override( "createParameterTree" ) )
            return func_createParameterTree(  );
        else{
            return this->IParameterized::createParameterTree(  );
        }
    }
    
    ::ParameterPool * default_createParameterTree(  ) const  {
        return IParameterized::createParameterTree( );
    }

    virtual double getKappa(  ) const  {
        if( bp::override func_getKappa = this->get_override( "getKappa" ) )
            return func_getKappa(  );
        else{
            return this->IInterferenceFunction::getKappa(  );
        }
    }
    
    double default_getKappa(  ) const  {
        return IInterferenceFunction::getKappa( );
    }

    virtual void printParameters(  ) const  {
        if( bp::override func_printParameters = this->get_override( "printParameters" ) )
            func_printParameters(  );
        else{
            this->IParameterized::printParameters(  );
        }
    }
    
    void default_printParameters(  ) const  {
        IParameterized::printParameters( );
    }

    virtual void print_structure(  ) {
        if( bp::override func_print_structure = this->get_override( "print_structure" ) )
            func_print_structure(  );
        else{
            this->ISample::print_structure(  );
        }
    }
    
    void default_print_structure(  ) {
        ISample::print_structure( );
    }

    virtual void setParametersAreChanged(  ) {
        if( bp::override func_setParametersAreChanged = this->get_override( "setParametersAreChanged" ) )
            func_setParametersAreChanged(  );
        else{
            this->IParameterized::setParametersAreChanged(  );
        }
    }
    
    void default_setParametersAreChanged(  ) {
        IParameterized::setParametersAreChanged( );
    }

};

void register_InterferenceFunction2DLattice_class(){

    bp::class_< InterferenceFunction2DLattice_wrapper, bp::bases< IInterferenceFunction >, boost::noncopyable >( "InterferenceFunction2DLattice", bp::init< Lattice2DIFParameters const & >(( bp::arg("lattice_params") )) )    
        .def( 
            "clone"
            , (::InterferenceFunction2DLattice * ( ::InterferenceFunction2DLattice::* )(  ) const)(&::InterferenceFunction2DLattice::clone)
            , (::InterferenceFunction2DLattice * ( InterferenceFunction2DLattice_wrapper::* )(  ) const)(&InterferenceFunction2DLattice_wrapper::default_clone)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "evaluate"
            , (double ( ::InterferenceFunction2DLattice::* )( ::cvector_t const & ) const)(&::InterferenceFunction2DLattice::evaluate)
            , (double ( InterferenceFunction2DLattice_wrapper::* )( ::cvector_t const & ) const)(&InterferenceFunction2DLattice_wrapper::default_evaluate)
            , ( bp::arg("q") ) )    
        .def( 
            "setProbabilityDistribution"
            , (void ( ::InterferenceFunction2DLattice::* )( ::IFTDistribution2D const & ) )( &::InterferenceFunction2DLattice::setProbabilityDistribution )
            , ( bp::arg("pdf") ) )    
        .def( 
            "areParametersChanged"
            , (bool ( ::IParameterized::* )(  ) )(&::IParameterized::areParametersChanged)
            , (bool ( InterferenceFunction2DLattice_wrapper::* )(  ) )(&InterferenceFunction2DLattice_wrapper::default_areParametersChanged) )    
        .def( 
            "createParameterTree"
            , (::ParameterPool * ( ::IParameterized::* )(  ) const)(&::IParameterized::createParameterTree)
            , (::ParameterPool * ( InterferenceFunction2DLattice_wrapper::* )(  ) const)(&InterferenceFunction2DLattice_wrapper::default_createParameterTree)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "getKappa"
            , (double ( ::IInterferenceFunction::* )(  ) const)(&::IInterferenceFunction::getKappa)
            , (double ( InterferenceFunction2DLattice_wrapper::* )(  ) const)(&InterferenceFunction2DLattice_wrapper::default_getKappa) )    
        .def( 
            "printParameters"
            , (void ( ::IParameterized::* )(  ) const)(&::IParameterized::printParameters)
            , (void ( InterferenceFunction2DLattice_wrapper::* )(  ) const)(&InterferenceFunction2DLattice_wrapper::default_printParameters) )    
        .def( 
            "print_structure"
            , (void ( ::ISample::* )(  ) )(&::ISample::print_structure)
            , (void ( InterferenceFunction2DLattice_wrapper::* )(  ) )(&InterferenceFunction2DLattice_wrapper::default_print_structure) )    
        .def( 
            "setParametersAreChanged"
            , (void ( ::IParameterized::* )(  ) )(&::IParameterized::setParametersAreChanged)
            , (void ( InterferenceFunction2DLattice_wrapper::* )(  ) )(&InterferenceFunction2DLattice_wrapper::default_setParametersAreChanged) );

}
