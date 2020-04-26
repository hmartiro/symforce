//  ----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>

#include <geo/pose3.h>

namespace geo {
namespace pose3 {

/**
 * C++ GroupOps implementation for <class 'symforce.geo.pose3.Pose3'>.
 */
template <typename Scalar>
struct GroupOps {
  static Pose3<Scalar> Identity();
  static Pose3<Scalar> Inverse(const Pose3<Scalar>& a);
  static Pose3<Scalar> Compose(const Pose3<Scalar>& a, const Pose3<Scalar>& b);
  static Pose3<Scalar> Between(const Pose3<Scalar>& a, const Pose3<Scalar>& b);

};

}  // namespace pose3

// Wrapper to specialize the public concept

template <>
struct GroupOps<Pose3<double>> : public pose3::GroupOps<double> {};
template <>
struct GroupOps<Pose3<float>> : public pose3::GroupOps<float> {};

}  // namespace geo
