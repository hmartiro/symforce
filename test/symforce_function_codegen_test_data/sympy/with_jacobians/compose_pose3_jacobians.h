// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>

#include <sym/pose3.h>

namespace sym {

/**
 * Composition of two elements in the group.
 *
 * Returns:
 *     res_D_a: (6x6) jacobian of res (6) wrt arg a (6)
 *     res_D_b: (6x6) jacobian of res (6) wrt arg b (6)
 */
template <typename Scalar>
void ComposePose3Jacobians(const sym::Pose3<Scalar>& a, const sym::Pose3<Scalar>& b,
                           Eigen::Matrix<Scalar, 6, 6>* const res_D_a = nullptr,
                           Eigen::Matrix<Scalar, 6, 6>* const res_D_b = nullptr) {
  // Total ops: 300

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _b = b.Data();

  // Intermediate terms (97)
  const Scalar _tmp0 = _a[1] * _b[1];
  const Scalar _tmp1 = (Scalar(1) / Scalar(2)) * _tmp0;
  const Scalar _tmp2 = _a[0] * _b[0];
  const Scalar _tmp3 = (Scalar(1) / Scalar(2)) * _tmp2;
  const Scalar _tmp4 = (Scalar(1) / Scalar(2)) * _a[3] * _b[3];
  const Scalar _tmp5 = _a[2] * _b[2];
  const Scalar _tmp6 = (Scalar(1) / Scalar(2)) * _tmp5;
  const Scalar _tmp7 = _tmp4 + _tmp6;
  const Scalar _tmp8 = _tmp1 - _tmp3 + _tmp7;
  const Scalar _tmp9 = 2 * _a[3] * _b[3] - 2 * _tmp0 - 2 * _tmp2 - 2 * _tmp5;
  const Scalar _tmp10 = _a[3] * _b[0];
  const Scalar _tmp11 = _a[0] * _b[3];
  const Scalar _tmp12 = _a[1] * _b[2];
  const Scalar _tmp13 = -2 * _a[2] * _b[1] + 2 * _tmp10 + 2 * _tmp11 + 2 * _tmp12;
  const Scalar _tmp14 = -_tmp13;
  const Scalar _tmp15 = (Scalar(1) / Scalar(2)) * _tmp11;
  const Scalar _tmp16 = (Scalar(1) / Scalar(2)) * _tmp12;
  const Scalar _tmp17 = (Scalar(1) / Scalar(2)) * _tmp10;
  const Scalar _tmp18 = (Scalar(1) / Scalar(2)) * _a[2] * _b[1];
  const Scalar _tmp19 = _tmp17 + _tmp18;
  const Scalar _tmp20 = -_tmp15 + _tmp16 - _tmp19;
  const Scalar _tmp21 = _a[3] * _b[1];
  const Scalar _tmp22 = _a[1] * _b[3];
  const Scalar _tmp23 = _a[2] * _b[0];
  const Scalar _tmp24 = -2 * _a[0] * _b[2] + 2 * _tmp21 + 2 * _tmp22 + 2 * _tmp23;
  const Scalar _tmp25 = -_tmp24;
  const Scalar _tmp26 = (Scalar(1) / Scalar(2)) * _tmp23;
  const Scalar _tmp27 = (Scalar(1) / Scalar(2)) * _tmp21;
  const Scalar _tmp28 = (Scalar(1) / Scalar(2)) * _a[0] * _b[2];
  const Scalar _tmp29 = (Scalar(1) / Scalar(2)) * _tmp22;
  const Scalar _tmp30 = _tmp28 + _tmp29;
  const Scalar _tmp31 = -_tmp26 + _tmp27 - _tmp30;
  const Scalar _tmp32 = _a[3] * _b[2];
  const Scalar _tmp33 = (Scalar(1) / Scalar(2)) * _tmp32;
  const Scalar _tmp34 = _a[2] * _b[3];
  const Scalar _tmp35 = (Scalar(1) / Scalar(2)) * _tmp34;
  const Scalar _tmp36 = _a[0] * _b[1];
  const Scalar _tmp37 = (Scalar(1) / Scalar(2)) * _tmp36;
  const Scalar _tmp38 = _a[1] * _b[0];
  const Scalar _tmp39 = (Scalar(1) / Scalar(2)) * _tmp38;
  const Scalar _tmp40 = _tmp37 + _tmp39;
  const Scalar _tmp41 = -_tmp33 + _tmp35 - _tmp40;
  const Scalar _tmp42 = 2 * _tmp32 + 2 * _tmp34 + 2 * _tmp36 - 2 * _tmp38;
  const Scalar _tmp43 = -_tmp1 + _tmp3 + _tmp7;
  const Scalar _tmp44 = _tmp33 - _tmp35 - _tmp40;
  const Scalar _tmp45 = _tmp26 - _tmp27 - _tmp30;
  const Scalar _tmp46 = _tmp15 - _tmp16 - _tmp19;
  const Scalar _tmp47 = _tmp1 + _tmp3;
  const Scalar _tmp48 = _tmp4 + _tmp47 - _tmp6;
  const Scalar _tmp49 = _tmp26 + _tmp27;
  const Scalar _tmp50 = -_tmp28 + _tmp29 - _tmp49;
  const Scalar _tmp51 = _tmp33 + _tmp35;
  const Scalar _tmp52 = _tmp37 - _tmp39 - _tmp51;
  const Scalar _tmp53 = _tmp15 + _tmp16;
  const Scalar _tmp54 = _tmp17 - _tmp18 - _tmp53;
  const Scalar _tmp55 = -_tmp42;
  const Scalar _tmp56 = 2 * _a[1];
  const Scalar _tmp57 = _a[3] * _tmp56;
  const Scalar _tmp58 = 2 * _a[2];
  const Scalar _tmp59 = _a[0] * _tmp58;
  const Scalar _tmp60 = _tmp57 + _tmp59;
  const Scalar _tmp61 = _a[3] * _tmp58;
  const Scalar _tmp62 = _a[0] * _tmp56;
  const Scalar _tmp63 = _tmp61 - _tmp62;
  const Scalar _tmp64 = std::pow(_a[0], Scalar(2));
  const Scalar _tmp65 = std::pow(_a[1], Scalar(2));
  const Scalar _tmp66 = -_tmp65;
  const Scalar _tmp67 = std::pow(_a[3], Scalar(2));
  const Scalar _tmp68 = std::pow(_a[2], Scalar(2));
  const Scalar _tmp69 = _tmp67 - _tmp68;
  const Scalar _tmp70 = _tmp64 + _tmp66 + _tmp69;
  const Scalar _tmp71 = -_tmp63;
  const Scalar _tmp72 = 2 * _a[0] * _a[3];
  const Scalar _tmp73 = _a[2] * _tmp56;
  const Scalar _tmp74 = _tmp72 - _tmp73;
  const Scalar _tmp75 = -_tmp74;
  const Scalar _tmp76 = -_tmp64;
  const Scalar _tmp77 = _tmp65 + _tmp69 + _tmp76;
  const Scalar _tmp78 = _tmp61 + _tmp62;
  const Scalar _tmp79 = _tmp72 + _tmp73;
  const Scalar _tmp80 = _tmp66 + _tmp67 + _tmp68 + _tmp76;
  const Scalar _tmp81 = _tmp57 - _tmp59;
  const Scalar _tmp82 = -_tmp81;
  const Scalar _tmp83 = _tmp37 - _tmp39 + _tmp51;
  const Scalar _tmp84 = _tmp17 - _tmp18 + _tmp53;
  const Scalar _tmp85 = -_tmp84;
  const Scalar _tmp86 = _tmp14 * _tmp85;
  const Scalar _tmp87 = (Scalar(1) / Scalar(2)) * _a[3] * _b[3] - _tmp47 - _tmp6;
  const Scalar _tmp88 = _tmp87 * _tmp9;
  const Scalar _tmp89 = -_tmp28 + _tmp29 + _tmp49;
  const Scalar _tmp90 = -_tmp89;
  const Scalar _tmp91 = _tmp25 * _tmp90 + _tmp88;
  const Scalar _tmp92 = -_tmp83;
  const Scalar _tmp93 = _tmp55 * _tmp92;
  const Scalar _tmp94 = 2 * _tmp65;
  const Scalar _tmp95 = 2 * _tmp68 - 1;
  const Scalar _tmp96 = 2 * _tmp64;

  // Output terms (2)
  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _tmp14 * _tmp20 + _tmp25 * _tmp31 + _tmp41 * _tmp42 + _tmp8 * _tmp9;
    _res_D_a(0, 1) = _tmp14 * _tmp45 + _tmp25 * _tmp46 + _tmp42 * _tmp43 + _tmp44 * _tmp9;
    _res_D_a(0, 2) = _tmp14 * _tmp52 + _tmp25 * _tmp48 + _tmp42 * _tmp54 + _tmp50 * _tmp9;
    _res_D_a(0, 3) = 0;
    _res_D_a(0, 4) = 0;
    _res_D_a(0, 5) = 0;
    _res_D_a(1, 0) = _tmp13 * _tmp31 + _tmp20 * _tmp25 + _tmp41 * _tmp9 + _tmp55 * _tmp8;
    _res_D_a(1, 1) = _tmp13 * _tmp46 + _tmp25 * _tmp45 + _tmp43 * _tmp9 + _tmp44 * _tmp55;
    _res_D_a(1, 2) = _tmp13 * _tmp48 + _tmp25 * _tmp52 + _tmp50 * _tmp55 + _tmp54 * _tmp9;
    _res_D_a(1, 3) = 0;
    _res_D_a(1, 4) = 0;
    _res_D_a(1, 5) = 0;
    _res_D_a(2, 0) = _tmp14 * _tmp41 + _tmp20 * _tmp55 + _tmp24 * _tmp8 + _tmp31 * _tmp9;
    _res_D_a(2, 1) = _tmp14 * _tmp43 + _tmp24 * _tmp44 + _tmp45 * _tmp55 + _tmp46 * _tmp9;
    _res_D_a(2, 2) = _tmp14 * _tmp54 + _tmp24 * _tmp50 + _tmp48 * _tmp9 + _tmp52 * _tmp55;
    _res_D_a(2, 3) = 0;
    _res_D_a(2, 4) = 0;
    _res_D_a(2, 5) = 0;
    _res_D_a(3, 0) = _b[5] * _tmp60 + _b[6] * _tmp63;
    _res_D_a(3, 1) = -_b[4] * _tmp60 + _b[6] * _tmp70;
    _res_D_a(3, 2) = _b[4] * _tmp71 - _b[5] * _tmp70;
    _res_D_a(3, 3) = 1;
    _res_D_a(3, 4) = 0;
    _res_D_a(3, 5) = 0;
    _res_D_a(4, 0) = _b[5] * _tmp75 - _b[6] * _tmp77;
    _res_D_a(4, 1) = _b[4] * _tmp74 + _b[6] * _tmp78;
    _res_D_a(4, 2) = _b[4] * _tmp77 - _b[5] * _tmp78;
    _res_D_a(4, 3) = 0;
    _res_D_a(4, 4) = 1;
    _res_D_a(4, 5) = 0;
    _res_D_a(5, 0) = _b[5] * _tmp80 - _b[6] * _tmp79;
    _res_D_a(5, 1) = -_b[4] * _tmp80 + _b[6] * _tmp82;
    _res_D_a(5, 2) = _b[4] * _tmp79 + _b[5] * _tmp81;
    _res_D_a(5, 3) = 0;
    _res_D_a(5, 4) = 0;
    _res_D_a(5, 5) = 1;
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _res_D_b = (*res_D_b);

    _res_D_b(0, 0) = _tmp42 * _tmp83 + _tmp86 + _tmp91;
    _res_D_b(0, 1) = _tmp14 * _tmp90 + _tmp25 * _tmp84 + _tmp42 * _tmp87 + _tmp9 * _tmp92;
    _res_D_b(0, 2) = _tmp14 * _tmp92 + _tmp25 * _tmp87 + _tmp42 * _tmp85 + _tmp89 * _tmp9;
    _res_D_b(0, 3) = 0;
    _res_D_b(0, 4) = 0;
    _res_D_b(0, 5) = 0;
    _res_D_b(1, 0) = _tmp13 * _tmp90 + _tmp25 * _tmp85 + _tmp55 * _tmp87 + _tmp83 * _tmp9;
    _res_D_b(1, 1) = _tmp13 * _tmp84 + _tmp91 + _tmp93;
    _res_D_b(1, 2) = _tmp13 * _tmp87 + _tmp25 * _tmp92 + _tmp55 * _tmp89 + _tmp85 * _tmp9;
    _res_D_b(1, 3) = 0;
    _res_D_b(1, 4) = 0;
    _res_D_b(1, 5) = 0;
    _res_D_b(2, 0) = _tmp14 * _tmp83 + _tmp24 * _tmp87 + _tmp55 * _tmp85 + _tmp9 * _tmp90;
    _res_D_b(2, 1) = _tmp14 * _tmp87 + _tmp24 * _tmp92 + _tmp55 * _tmp90 + _tmp84 * _tmp9;
    _res_D_b(2, 2) = _tmp24 * _tmp89 + _tmp86 + _tmp88 + _tmp93;
    _res_D_b(2, 3) = 0;
    _res_D_b(2, 4) = 0;
    _res_D_b(2, 5) = 0;
    _res_D_b(3, 0) = 0;
    _res_D_b(3, 1) = 0;
    _res_D_b(3, 2) = 0;
    _res_D_b(3, 3) = -_tmp94 - _tmp95;
    _res_D_b(3, 4) = _tmp71;
    _res_D_b(3, 5) = _tmp60;
    _res_D_b(4, 0) = 0;
    _res_D_b(4, 1) = 0;
    _res_D_b(4, 2) = 0;
    _res_D_b(4, 3) = _tmp78;
    _res_D_b(4, 4) = -_tmp95 - _tmp96;
    _res_D_b(4, 5) = _tmp75;
    _res_D_b(5, 0) = 0;
    _res_D_b(5, 1) = 0;
    _res_D_b(5, 2) = 0;
    _res_D_b(5, 3) = _tmp82;
    _res_D_b(5, 4) = _tmp79;
    _res_D_b(5, 5) = -_tmp94 - _tmp96 + 1;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
