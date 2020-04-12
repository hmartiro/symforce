//  -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>

#include <geo/rot3.h>

namespace geo {
namespace rot3 {

/**
 * C++ LieGroupOps implementation for <class 'symforce.geometry.rot3.Rot3'>.
 */
template <typename Scalar>
struct LieGroupOps {
  static constexpr int32_t TangentDim() {
      return 3;
  }

  static Rot3<Scalar> Expmap(const Eigen::Matrix<Scalar, 3, 1>& vec, const Scalar epsilon);
  static Eigen::Matrix<Scalar, 3, 1> Logmap(const Rot3<Scalar>& a, const Scalar epsilon);
  static Rot3<Scalar> Retract(const Rot3<Scalar>& a, const Eigen::Matrix<Scalar, 3, 1>& vec, const Scalar epsilon);
  static Eigen::Matrix<Scalar, 3, 1> LocalCoordinates(const Rot3<Scalar>& a, const Rot3<Scalar>& b, const Scalar epsilon);
};

}  // namespace rot3

// Specialization into the top level concept
template <>
struct LieGroupOps<Rot3<double>> : public rot3::LieGroupOps<double> {};
template <>
struct LieGroupOps<Rot3<float>> : public rot3::LieGroupOps<float> {};

}  // namespace geo
