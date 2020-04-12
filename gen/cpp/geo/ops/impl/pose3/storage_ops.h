//  -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <vector>
#include <Eigen/Dense>

#include <geo/pose3.h>

namespace geo {
namespace pose3 {

/**
 * C++ StorageOps implementation for <class 'symforce.geometry.pose3.Pose3'>.
 */
template <typename Scalar>
struct StorageOps {
  static constexpr int32_t StorageDim() {
    return 7;
  }

  static void ToList(const geo::Pose3<Scalar>& a, std::vector<Scalar>* vec);
  static geo::Pose3<Scalar> FromList(const std::vector<Scalar>& vec);
};

}  // namespace pose3

// Wrapper to specialize the public concept

template <>
struct StorageOps<Pose3<double>> : public pose3::StorageOps<double> {};
template <>
struct StorageOps<Pose3<float>> : public pose3::StorageOps<float> {};

}  // namespace geo
