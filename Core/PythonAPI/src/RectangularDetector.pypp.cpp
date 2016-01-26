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
#include "RectangularDetector.pypp.h"

namespace bp = boost::python;

struct RectangularDetector_wrapper : RectangularDetector, bp::wrapper< RectangularDetector > {

    RectangularDetector_wrapper(int nxbins, double width, int nybins, double height )
    : RectangularDetector( nxbins, width, nybins, height )
      , bp::wrapper< RectangularDetector >(){
        // constructor
    m_pyobj = 0;
    }

    RectangularDetector_wrapper(::RectangularDetector const & other )
    : RectangularDetector( boost::ref(other) )
      , bp::wrapper< RectangularDetector >(){
        // copy constructor
    m_pyobj = 0;
    }

    virtual ::RectangularDetector * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->RectangularDetector::clone(  );
        }
    }
    
    ::RectangularDetector * default_clone(  ) const  {
        return RectangularDetector::clone( );
    }

    PyObject* m_pyobj;

};

void register_RectangularDetector_class(){

    { //::RectangularDetector
        typedef bp::class_< RectangularDetector_wrapper, bp::bases< IDetector2D >, std::auto_ptr< RectangularDetector_wrapper > > RectangularDetector_exposer_t;
        RectangularDetector_exposer_t RectangularDetector_exposer = RectangularDetector_exposer_t( "RectangularDetector", "A rectangular plane detector with axes and resolution function.", bp::init< int, double, int, double >(( bp::arg("nxbins"), bp::arg("width"), bp::arg("nybins"), bp::arg("height") ), "Rectangular detector constructor @param nxbins Number of bins (pixels) in x-direction @param width Width of the detector in mm along x-direction @param nybins Number of bins (pixels) in y-direction @param height Height of the detector in mm along y-direction \n\n:Parameters:\n  - 'nxbins' - Number of bins (pixels) in x-direction\n  - 'width' - Width of the detector in mm along x-direction\n  - 'nybins' - Number of bins (pixels) in y-direction\n  - 'height' - Height of the detector in mm along y-direction\n") );
        bp::scope RectangularDetector_scope( RectangularDetector_exposer );
        bp::enum_< RectangularDetector::EDetectorArrangement>("EDetectorArrangement")
            .value("GENERIC", RectangularDetector::GENERIC)
            .value("PERPENDICULAR_TO_SAMPLE", RectangularDetector::PERPENDICULAR_TO_SAMPLE)
            .value("PERPENDICULAR_TO_DIRECT_BEAM", RectangularDetector::PERPENDICULAR_TO_DIRECT_BEAM)
            .value("PERPENDICULAR_TO_REFLECTED_BEAM", RectangularDetector::PERPENDICULAR_TO_REFLECTED_BEAM)
            .value("PERPENDICULAR_TO_REFLECTED_BEAM_DPOS", RectangularDetector::PERPENDICULAR_TO_REFLECTED_BEAM_DPOS)
            .export_values()
            ;
        RectangularDetector_exposer.def( bp::init< RectangularDetector const & >(( bp::arg("other") ), "Rectangular detector constructor @param nxbins Number of bins (pixels) in x-direction @param width Width of the detector in mm along x-direction @param nybins Number of bins (pixels) in y-direction @param height Height of the detector in mm along y-direction \n\n:Parameters:\n  - 'nxbins' - Number of bins (pixels) in x-direction\n  - 'width' - Width of the detector in mm along x-direction\n  - 'nybins' - Number of bins (pixels) in y-direction\n  - 'height' - Height of the detector in mm along y-direction\n") );
        { //::RectangularDetector::clone
        
            typedef ::RectangularDetector * ( ::RectangularDetector::*clone_function_type)(  ) const;
            typedef ::RectangularDetector * ( RectangularDetector_wrapper::*default_clone_function_type)(  ) const;
            
            RectangularDetector_exposer.def( 
                "clone"
                , clone_function_type(&::RectangularDetector::clone)
                , default_clone_function_type(&RectangularDetector_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::RectangularDetector::getDetectorArrangment
        
            typedef ::RectangularDetector::EDetectorArrangement ( ::RectangularDetector::*getDetectorArrangment_function_type)(  ) const;
            
            RectangularDetector_exposer.def( 
                "getDetectorArrangment"
                , getDetectorArrangment_function_type( &::RectangularDetector::getDetectorArrangment ) );
        
        }
        { //::RectangularDetector::getDirectBeamU0
        
            typedef double ( ::RectangularDetector::*getDirectBeamU0_function_type)(  ) const;
            
            RectangularDetector_exposer.def( 
                "getDirectBeamU0"
                , getDirectBeamU0_function_type( &::RectangularDetector::getDirectBeamU0 ) );
        
        }
        { //::RectangularDetector::getDirectBeamV0
        
            typedef double ( ::RectangularDetector::*getDirectBeamV0_function_type)(  ) const;
            
            RectangularDetector_exposer.def( 
                "getDirectBeamV0"
                , getDirectBeamV0_function_type( &::RectangularDetector::getDirectBeamV0 ) );
        
        }
        { //::RectangularDetector::getDirectionVector
        
            typedef ::kvector_t ( ::RectangularDetector::*getDirectionVector_function_type)(  ) const;
            
            RectangularDetector_exposer.def( 
                "getDirectionVector"
                , getDirectionVector_function_type( &::RectangularDetector::getDirectionVector ) );
        
        }
        { //::RectangularDetector::getDistance
        
            typedef double ( ::RectangularDetector::*getDistance_function_type)(  ) const;
            
            RectangularDetector_exposer.def( 
                "getDistance"
                , getDistance_function_type( &::RectangularDetector::getDistance ) );
        
        }
        { //::RectangularDetector::getHeight
        
            typedef double ( ::RectangularDetector::*getHeight_function_type)(  ) const;
            
            RectangularDetector_exposer.def( 
                "getHeight"
                , getHeight_function_type( &::RectangularDetector::getHeight ) );
        
        }
        { //::RectangularDetector::getNbinsX
        
            typedef ::std::size_t ( ::RectangularDetector::*getNbinsX_function_type)(  ) const;
            
            RectangularDetector_exposer.def( 
                "getNbinsX"
                , getNbinsX_function_type( &::RectangularDetector::getNbinsX ) );
        
        }
        { //::RectangularDetector::getNbinsY
        
            typedef ::std::size_t ( ::RectangularDetector::*getNbinsY_function_type)(  ) const;
            
            RectangularDetector_exposer.def( 
                "getNbinsY"
                , getNbinsY_function_type( &::RectangularDetector::getNbinsY ) );
        
        }
        { //::RectangularDetector::getNormalVector
        
            typedef ::kvector_t ( ::RectangularDetector::*getNormalVector_function_type)(  ) const;
            
            RectangularDetector_exposer.def( 
                "getNormalVector"
                , getNormalVector_function_type( &::RectangularDetector::getNormalVector ) );
        
        }
        { //::RectangularDetector::getU0
        
            typedef double ( ::RectangularDetector::*getU0_function_type)(  ) const;
            
            RectangularDetector_exposer.def( 
                "getU0"
                , getU0_function_type( &::RectangularDetector::getU0 ) );
        
        }
        { //::RectangularDetector::getV0
        
            typedef double ( ::RectangularDetector::*getV0_function_type)(  ) const;
            
            RectangularDetector_exposer.def( 
                "getV0"
                , getV0_function_type( &::RectangularDetector::getV0 ) );
        
        }
        { //::RectangularDetector::getWidth
        
            typedef double ( ::RectangularDetector::*getWidth_function_type)(  ) const;
            
            RectangularDetector_exposer.def( 
                "getWidth"
                , getWidth_function_type( &::RectangularDetector::getWidth ) );
        
        }
        { //::RectangularDetector::operator=
        
            typedef ::RectangularDetector & ( ::RectangularDetector::*assign_function_type)( ::RectangularDetector const & ) ;
            
            RectangularDetector_exposer.def( 
                "assign"
                , assign_function_type( &::RectangularDetector::operator= )
                , ( bp::arg("other") )
                , bp::return_self< >() );
        
        }
        { //::RectangularDetector::setDirectBeamPosition
        
            typedef void ( ::RectangularDetector::*setDirectBeamPosition_function_type)( double,double ) ;
            
            RectangularDetector_exposer.def( 
                "setDirectBeamPosition"
                , setDirectBeamPosition_function_type( &::RectangularDetector::setDirectBeamPosition )
                , ( bp::arg("u0"), bp::arg("v0") ) );
        
        }
        { //::RectangularDetector::setPerpendicularToDirectBeam
        
            typedef void ( ::RectangularDetector::*setPerpendicularToDirectBeam_function_type)( double,double,double ) ;
            
            RectangularDetector_exposer.def( 
                "setPerpendicularToDirectBeam"
                , setPerpendicularToDirectBeam_function_type( &::RectangularDetector::setPerpendicularToDirectBeam )
                , ( bp::arg("distance"), bp::arg("u0"), bp::arg("v0") ) );
        
        }
        { //::RectangularDetector::setPerpendicularToReflectedBeam
        
            typedef void ( ::RectangularDetector::*setPerpendicularToReflectedBeam_function_type)( double,double,double ) ;
            
            RectangularDetector_exposer.def( 
                "setPerpendicularToReflectedBeam"
                , setPerpendicularToReflectedBeam_function_type( &::RectangularDetector::setPerpendicularToReflectedBeam )
                , ( bp::arg("distance"), bp::arg("u0")=0.0, bp::arg("v0")=0.0 ) );
        
        }
        { //::RectangularDetector::setPerpendicularToSampleX
        
            typedef void ( ::RectangularDetector::*setPerpendicularToSampleX_function_type)( double,double,double ) ;
            
            RectangularDetector_exposer.def( 
                "setPerpendicularToSampleX"
                , setPerpendicularToSampleX_function_type( &::RectangularDetector::setPerpendicularToSampleX )
                , ( bp::arg("distance"), bp::arg("u0"), bp::arg("v0") ) );
        
        }
        { //::RectangularDetector::setPosition
        
            typedef void ( ::RectangularDetector::*setPosition_function_type)( ::kvector_t const &,double,double,::kvector_t const & ) ;
            
            RectangularDetector_exposer.def( 
                "setPosition"
                , setPosition_function_type( &::RectangularDetector::setPosition )
                , ( bp::arg("normal_to_detector"), bp::arg("u0"), bp::arg("v0"), bp::arg("direction")=Geometry::BasicVector3D<double>(0.0, -1.0e+0, 0.0) ) );
        
        }
    }

}
