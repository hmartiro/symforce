// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/ops/CLASS/storage_ops.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./storage_ops.h"

#include <algorithm>

#include <Eigen/Dense>

#include <sym/spherical_camera_cal.h>

namespace sym {

template <typename ScalarType>
void StorageOps<SphericalCameraCal<ScalarType>>::ToStorage(const SphericalCameraCal<ScalarType>& a,
                                                           ScalarType* out) {
  assert(out != nullptr);
  std::copy_n(a.Data().data(), a.StorageDim(), out);
}

template <typename ScalarType>
SphericalCameraCal<ScalarType> StorageOps<SphericalCameraCal<ScalarType>>::FromStorage(
    const ScalarType* data) {
  assert(data != nullptr);
  return SphericalCameraCal<ScalarType>(
      Eigen::Map<const typename SphericalCameraCal<ScalarType>::DataVec>(data));
}

}  // namespace sym

// Explicit instantiation
template struct sym::StorageOps<sym::SphericalCameraCal<double>>;
template struct sym::StorageOps<sym::SphericalCameraCal<float>>;
