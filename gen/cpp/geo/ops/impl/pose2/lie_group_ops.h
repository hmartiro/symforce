//  -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>

#include <geo/pose2.h>

namespace geo {
namespace pose2 {

/**
 * C++ LieGroupOps implementation for <class 'symforce.geo.pose2.Pose2'>.
 */
template <typename Scalar>
struct LieGroupOps {
  static constexpr int32_t TangentDim() {
      return 3;
  }

  static Pose2<Scalar> FromTangent(const Eigen::Matrix<Scalar, 3, 1>& vec, const Scalar epsilon);
  static Eigen::Matrix<Scalar, 3, 1> ToTangent(const Pose2<Scalar>& a, const Scalar epsilon);
  static Pose2<Scalar> Retract(const Pose2<Scalar>& a, const Eigen::Matrix<Scalar, 3, 1>& vec, const Scalar epsilon);
  static Eigen::Matrix<Scalar, 3, 1> LocalCoordinates(const Pose2<Scalar>& a, const Pose2<Scalar>& b, const Scalar epsilon);
};

}  // namespace pose2

// Specialization into the top level concept
template <>
struct LieGroupOps<Pose2<double>> : public pose2::LieGroupOps<double> {};
template <>
struct LieGroupOps<Pose2<float>> : public pose2::LieGroupOps<float> {};

}  // namespace geo
