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
#include "PythonInterface_free_functions.pypp.h"

namespace bp = boost::python;

void register_free_functions(){

    { //::Geometry::CrossProduct
    
        typedef ::Geometry::BasicVector3D< std::complex< double > > ( *CrossProduct_function_type )( ::Geometry::BasicVector3D< std::complex< double > > const &,::Geometry::BasicVector3D< std::complex< double > > const & );
        
        bp::def( 
            "CrossProduct"
            , CrossProduct_function_type( &::Geometry::CrossProduct )
            , ( bp::arg("vectorLeft"), bp::arg("vectorRight") ) );
    
    }

    { //::Geometry::CrossProduct
    
        typedef ::Geometry::BasicVector3D< double > ( *CrossProduct_function_type )( ::Geometry::BasicVector3D< double > const &,::Geometry::BasicVector3D< double > const & );
        
        bp::def( 
            "CrossProduct"
            , CrossProduct_function_type( &::Geometry::CrossProduct )
            , ( bp::arg("vectorLeft"), bp::arg("vectorRight") ) );
    
    }

    { //::Geometry::DotProduct
    
        typedef ::std::complex< double > ( *DotProduct_function_type )( ::Geometry::BasicVector3D< std::complex< double > > const &,::Geometry::BasicVector3D< std::complex< double > > const & );
        
        bp::def( 
            "DotProduct"
            , DotProduct_function_type( &::Geometry::DotProduct )
            , ( bp::arg("left"), bp::arg("right") ) );
    
    }

    { //::Geometry::DotProduct
    
        typedef double ( *DotProduct_function_type )( ::Geometry::BasicVector3D< double > const &,::Geometry::BasicVector3D< double > const & );
        
        bp::def( 
            "DotProduct"
            , DotProduct_function_type( &::Geometry::DotProduct )
            , ( bp::arg("left"), bp::arg("right") ) );
    
    }

    { //::GetOutputData
    
        typedef ::PyObject * ( *GetOutputData_function_type )( ::Simulation const & );
        
        bp::def( 
            "GetOutputData"
            , GetOutputData_function_type( &::GetOutputData )
            , ( bp::arg("simulation") ) );
    
    }

    { //::GetOutputDataAxis
    
        typedef ::PyObject * ( *GetOutputDataAxis_function_type )( ::Simulation const &,int );
        
        bp::def( 
            "GetOutputDataAxis"
            , GetOutputDataAxis_function_type( &::GetOutputDataAxis )
            , ( bp::arg("simulation"), bp::arg("naxis") ) );
    
    }

    { //::GetOutputDataNdimensions
    
        typedef int ( *GetOutputDataNdimensions_function_type )( ::Simulation const & );
        
        bp::def( 
            "GetOutputDataNdimensions"
            , GetOutputDataNdimensions_function_type( &::GetOutputDataNdimensions )
            , ( bp::arg("simulation") ) );
    
    }

    { //::Units::deg2rad
    
        typedef double ( *deg2rad_function_type )( double );
        
        bp::def( 
            "deg2rad"
            , deg2rad_function_type( &::Units::deg2rad )
            , ( bp::arg("angle") ) );
    
    }

    { //::Units::rad2deg
    
        typedef double ( *rad2deg_function_type )( double );
        
        bp::def( 
            "rad2deg"
            , rad2deg_function_type( &::Units::rad2deg )
            , ( bp::arg("angle") ) );
    
    }

}
