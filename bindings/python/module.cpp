//
// Copyright (c) 2015-2018 CNRS
// Copyright (c) 2015 Wandercraft, 86 rue de Paris 91400 Orsay, France.
//

#include <eigenpy/eigenpy.hpp>
#include <eigenpy/geometry.hpp>

#include "pinocchio/bindings/python/fwd.hpp"
#include "pinocchio/multibody/fwd.hpp"
#include "pinocchio/utils/version.hpp"
#include "pinocchio/bindings/python/utils/version.hpp"
#include "pinocchio/bindings/python/utils/dependencies.hpp"
#include "pinocchio/bindings/python/utils/conversions.hpp"

namespace bp = boost::python;
using namespace pinocchio::python;

BOOST_PYTHON_MODULE(libpinocchio_pywrap)
{
  bp::scope().attr("__version__") = pinocchio::printVersion();
  
  eigenpy::enableEigenPy();
  eigenpy::exposeAngleAxis();
  eigenpy::exposeQuaternion();

  typedef Eigen::Matrix<double,6,6> Matrix6d;
  typedef Eigen::Matrix<double,6,1> Vector6d;
  typedef Eigen::Matrix<double,6,Eigen::Dynamic> Matrix6x;
  typedef Eigen::Matrix<double,3,Eigen::Dynamic> Matrix3x;
  
  eigenpy::enableEigenPySpecific<Matrix6d>();
  eigenpy::enableEigenPySpecific<Vector6d>();
  eigenpy::enableEigenPySpecific<Matrix6x>();
  eigenpy::enableEigenPySpecific<Matrix3x>();

  exposeSE3();
  exposeForce();
  exposeMotion();
  exposeInertia();
  exposeJoints();
  exposeExplog();
  
  bp::enum_< ::pinocchio::ReferenceFrame >("ReferenceFrame")
  .value("WORLD",::pinocchio::WORLD)
  .value("LOCAL",::pinocchio::LOCAL)
  .value("LOCAL_CARTESIAN_ORIENTED",::pinocchio::LOCAL_CARTESIAN_ORIENTED)
  ;

  exposeModel();
  exposeFrame();
  exposeData();
  exposeGeometry();
  
  exposeAlgorithms();
  exposeParsers();
  
#ifdef PINOCCHIO_WITH_HPP_FCL
  exposeFCL();
#endif // PINOCCHIO_WITH_HPP_FCL
  
  exposeVersion();
  exposeDependencies();
  exposeConversions();
  
}
 
