// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/ops/CLASS/storage_ops.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./storage_ops.h"

#include <algorithm>

#include <Eigen/Dense>

#include <sym/rot2.h>

namespace sym {

template <typename ScalarType>
void StorageOps<Rot2<ScalarType>>::ToStorage(const Rot2<ScalarType>& a, ScalarType* out) {
  assert(out != nullptr);
  std::copy_n(a.Data().data(), a.StorageDim(), out);
}

template <typename ScalarType>
Rot2<ScalarType> StorageOps<Rot2<ScalarType>>::FromStorage(const ScalarType* data) {
  assert(data != nullptr);
  return Rot2<ScalarType>(Eigen::Map<const typename Rot2<ScalarType>::DataVec>(data));
}

}  // namespace sym

// Explicit instantiation
template struct sym::StorageOps<sym::Rot2<double>>;
template struct sym::StorageOps<sym::Rot2<float>>;
