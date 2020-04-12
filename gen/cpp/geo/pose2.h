//  -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <ostream>
#include <vector>
#include <Eigen/Dense>

#include "./rot2.h"
#include "./ops/storage_ops.h"
#include "./ops/group_ops.h"
#include "./ops/lie_group_ops.h"

namespace geo {

/**
 * Autogenerated C++ implementation of <class 'symforce.geometry.pose2.Pose2'>.
 *
 * Group of two-dimensional rigid body transformations - rotation and translation.
 *
 * The storage space is a complex (real, imag) for rotation followed by a position (x, y).
 *
 * The tangent space is two elements for translation followed by one angle for rotation.
 * TODO(hayk): Flip this to match Pose3 with rotation first.
 */
template <typename ScalarType>
class Pose2 {
 public:
  // Typedefs
  using Scalar = ScalarType;
  using Self = Pose2<Scalar>;
  using StorageVec = Eigen::Matrix<Scalar, 4, 1>;
  using TangentVec = Eigen::Matrix<Scalar, 3, 1>;

  // Construct from storage
  explicit Pose2(const StorageVec& storage) : storage_(storage) {}

  // Default construct to identity
  Pose2() : Pose2(GroupOps<Self>::Identity()) {}

  // Access underlying storage as const
  inline const StorageVec& Storage() const {
      return storage_;
  }

  // --------------------------------------------------------------------------
  // StorageOps concept
  // --------------------------------------------------------------------------

  static constexpr int32_t StorageDim() {
    return StorageOps<Self>::StorageDim();
  }

  void ToList(std::vector<Scalar>* vec) const {
    return StorageOps<Self>::ToList(*this, vec);
  }

  static Pose2 FromList(const std::vector<Scalar>& vec) {
    return StorageOps<Self>::FromList(vec);
  }

  // --------------------------------------------------------------------------
  // GroupOps concept
  // --------------------------------------------------------------------------

  static Self Identity() {
    return GroupOps<Self>::Identity();
  }

  Self Inverse() const {
    return GroupOps<Self>::Inverse(*this);
  }

  Self Compose(const Self& b) const {
    return GroupOps<Self>::Compose(*this, b);
  }

  Self Between(const Self& b) const {
    return GroupOps<Self>::Between(*this, b);
  }

  // Compose shorthand
  template <typename Other>
  Other operator*(const Other& b) const {
    return Compose(b);
  }

// --------------------------------------------------------------------------
  // LieGroupOps concept
  // --------------------------------------------------------------------------

  static constexpr int32_t TangentDim() {
    return LieGroupOps<Self>::TangentDim();
  }

  static Self Expmap(const TangentVec& vec, const Scalar epsilon = 1e-8f) {
    return LieGroupOps<Self>::Expmap(vec, epsilon);
  }

  TangentVec Logmap(const Scalar epsilon = 1e-8f) const {
    return LieGroupOps<Self>::Logmap(*this, epsilon);
  }

  Self Retract(const TangentVec& vec, const Scalar epsilon = 1e-8f) const {
    return LieGroupOps<Self>::Retract(*this, vec, epsilon);
  }

  TangentVec LocalCoordinates(const Self& b, const Scalar epsilon = 1e-8f) const {
    return LieGroupOps<Self>::LocalCoordinates(*this, b, epsilon);
  }

  // --------------------------------------------------------------------------
  // General Helpers
  // --------------------------------------------------------------------------

  bool IsApprox(const Self& b, const Scalar tol) const {
    // isApprox is multiplicative so we check the norm for the exact zero case
    // https://eigen.tuxfamily.org/dox/classEigen_1_1DenseBase.html#ae8443357b808cd393be1b51974213f9c
    if (b.Storage() == StorageVec::Zero()) {
      return Storage().norm() < tol;
    }

    return Storage().isApprox(b.Storage(), tol);
  }

  template <typename ToScalar>
  Pose2<ToScalar> Cast() const {
    return Pose2<ToScalar>(Storage().template cast<ToScalar>());
  }

  // Included from "custom_methods/pose2.h":
  // --------------------------------------------------------------------------
  // Handwritten methods for Pose2
  // --------------------------------------------------------------------------

  Pose2(const Rot2<Scalar>& rotation, const Eigen::Matrix<Scalar, 2, 1>& position) {
    storage_.template head<2>() = rotation.Storage();
    storage_.template tail<2>() = position;
  }

  Rot2<Scalar> Rotation() const {
      return Rot2<Scalar>(storage_.template head<2>());
  }

  Eigen::Matrix<Scalar, 2, 1> Position() const {
      return storage_.template tail<2>();
  }

 protected:
  StorageVec storage_;
};

// Shorthand for scalar types
using Pose2d = Pose2<double>;
using Pose2f = Pose2<float>;

}  // namespace geo

// Externs to reduce duplicate instantiation
extern template class geo::Pose2<double>;
extern template class geo::Pose2<float>;

// Print definitions
std::ostream& operator<<(std::ostream& os, const geo::Pose2<double>& a);
std::ostream& operator<<(std::ostream& os, const geo::Pose2<float>& a);

// Concept implementations for this class
#include "./ops/impl/pose2/storage_ops.h"
#include "./ops/impl/pose2/group_ops.h"
#include "./ops/impl/pose2/lie_group_ops.h"
