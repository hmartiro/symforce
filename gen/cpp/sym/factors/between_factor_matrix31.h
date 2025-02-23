// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>

namespace sym {

/**
 * Residual that penalizes the difference between between(a, b) and a_T_b.
 *
 * In vector space terms that would be:
 *     (b - a) - a_T_b
 *
 * In lie group terms:
 *     local_coordinates(a_T_b, between(a, b))
 *     to_tangent(compose(inverse(a_T_b), compose(inverse(a), b)))
 *
 * Args:
 *     sqrt_info: Square root information matrix to whiten residual. This can be computed from
 *                a covariance matrix as the cholesky decomposition of the inverse. In the case
 *                of a diagonal it will contain 1/sigma values. Must match the tangent dim.
 *     jacobian: (3x6) jacobian of res wrt args a (3), b (3)
 *     hessian: (6x6) Gauss-Newton hessian for args a (3), b (3)
 *     rhs: (6x1) Gauss-Newton rhs for args a (3), b (3)
 */
template <typename Scalar>
void BetweenFactorMatrix31(const Eigen::Matrix<Scalar, 3, 1>& a,
                           const Eigen::Matrix<Scalar, 3, 1>& b,
                           const Eigen::Matrix<Scalar, 3, 1>& a_T_b,
                           const Eigen::Matrix<Scalar, 3, 3>& sqrt_info, const Scalar epsilon,
                           Eigen::Matrix<Scalar, 3, 1>* const res = nullptr,
                           Eigen::Matrix<Scalar, 3, 6>* const jacobian = nullptr,
                           Eigen::Matrix<Scalar, 6, 6>* const hessian = nullptr,
                           Eigen::Matrix<Scalar, 6, 1>* const rhs = nullptr) {
  // Total ops: 102

  // Input arrays

  // Intermediate terms (42)
  const Scalar _tmp0 = -a(1, 0) - a_T_b(1, 0) + b(1, 0);
  const Scalar _tmp1 = -a(2, 0) - a_T_b(2, 0) + b(2, 0);
  const Scalar _tmp2 = -a(0, 0) - a_T_b(0, 0) + b(0, 0);
  const Scalar _tmp3 = _tmp0 * sqrt_info(0, 1) + _tmp1 * sqrt_info(0, 2) + _tmp2 * sqrt_info(0, 0);
  const Scalar _tmp4 = _tmp0 * sqrt_info(1, 1) + _tmp1 * sqrt_info(1, 2) + _tmp2 * sqrt_info(1, 0);
  const Scalar _tmp5 = _tmp0 * sqrt_info(2, 1) + _tmp1 * sqrt_info(2, 2) + _tmp2 * sqrt_info(2, 0);
  const Scalar _tmp6 = std::pow(sqrt_info(0, 0), Scalar(2));
  const Scalar _tmp7 = std::pow(sqrt_info(2, 0), Scalar(2));
  const Scalar _tmp8 = std::pow(sqrt_info(1, 0), Scalar(2));
  const Scalar _tmp9 = _tmp6 + _tmp7 + _tmp8;
  const Scalar _tmp10 = sqrt_info(0, 0) * sqrt_info(0, 1);
  const Scalar _tmp11 = sqrt_info(2, 0) * sqrt_info(2, 1);
  const Scalar _tmp12 = sqrt_info(1, 0) * sqrt_info(1, 1);
  const Scalar _tmp13 = _tmp10 + _tmp11 + _tmp12;
  const Scalar _tmp14 = std::pow(sqrt_info(0, 1), Scalar(2));
  const Scalar _tmp15 = std::pow(sqrt_info(2, 1), Scalar(2));
  const Scalar _tmp16 = std::pow(sqrt_info(1, 1), Scalar(2));
  const Scalar _tmp17 = _tmp14 + _tmp15 + _tmp16;
  const Scalar _tmp18 = sqrt_info(0, 0) * sqrt_info(0, 2);
  const Scalar _tmp19 = sqrt_info(2, 0) * sqrt_info(2, 2);
  const Scalar _tmp20 = sqrt_info(1, 0) * sqrt_info(1, 2);
  const Scalar _tmp21 = _tmp18 + _tmp19 + _tmp20;
  const Scalar _tmp22 = sqrt_info(0, 1) * sqrt_info(0, 2);
  const Scalar _tmp23 = sqrt_info(2, 1) * sqrt_info(2, 2);
  const Scalar _tmp24 = sqrt_info(1, 1) * sqrt_info(1, 2);
  const Scalar _tmp25 = _tmp22 + _tmp23 + _tmp24;
  const Scalar _tmp26 = std::pow(sqrt_info(0, 2), Scalar(2));
  const Scalar _tmp27 = std::pow(sqrt_info(2, 2), Scalar(2));
  const Scalar _tmp28 = std::pow(sqrt_info(1, 2), Scalar(2));
  const Scalar _tmp29 = _tmp26 + _tmp27 + _tmp28;
  const Scalar _tmp30 = -_tmp10 - _tmp11 - _tmp12;
  const Scalar _tmp31 = -_tmp18 - _tmp19 - _tmp20;
  const Scalar _tmp32 = -_tmp22 - _tmp23 - _tmp24;
  const Scalar _tmp33 = _tmp5 * sqrt_info(2, 0);
  const Scalar _tmp34 = _tmp3 * sqrt_info(0, 0);
  const Scalar _tmp35 = _tmp4 * sqrt_info(1, 0);
  const Scalar _tmp36 = _tmp5 * sqrt_info(2, 1);
  const Scalar _tmp37 = _tmp3 * sqrt_info(0, 1);
  const Scalar _tmp38 = _tmp4 * sqrt_info(1, 1);
  const Scalar _tmp39 = _tmp5 * sqrt_info(2, 2);
  const Scalar _tmp40 = _tmp3 * sqrt_info(0, 2);
  const Scalar _tmp41 = _tmp4 * sqrt_info(1, 2);

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _res = (*res);

    _res(0, 0) = _tmp3;
    _res(1, 0) = _tmp4;
    _res(2, 0) = _tmp5;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 3, 6>& _jacobian = (*jacobian);

    _jacobian(0, 0) = -sqrt_info(0, 0);
    _jacobian(0, 1) = -sqrt_info(0, 1);
    _jacobian(0, 2) = -sqrt_info(0, 2);
    _jacobian(0, 3) = sqrt_info(0, 0);
    _jacobian(0, 4) = sqrt_info(0, 1);
    _jacobian(0, 5) = sqrt_info(0, 2);
    _jacobian(1, 0) = -sqrt_info(1, 0);
    _jacobian(1, 1) = -sqrt_info(1, 1);
    _jacobian(1, 2) = -sqrt_info(1, 2);
    _jacobian(1, 3) = sqrt_info(1, 0);
    _jacobian(1, 4) = sqrt_info(1, 1);
    _jacobian(1, 5) = sqrt_info(1, 2);
    _jacobian(2, 0) = -sqrt_info(2, 0);
    _jacobian(2, 1) = -sqrt_info(2, 1);
    _jacobian(2, 2) = -sqrt_info(2, 2);
    _jacobian(2, 3) = sqrt_info(2, 0);
    _jacobian(2, 4) = sqrt_info(2, 1);
    _jacobian(2, 5) = sqrt_info(2, 2);
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _hessian = (*hessian);

    _hessian(0, 0) = _tmp9;
    _hessian(0, 1) = 0;
    _hessian(0, 2) = 0;
    _hessian(0, 3) = 0;
    _hessian(0, 4) = 0;
    _hessian(0, 5) = 0;
    _hessian(1, 0) = _tmp13;
    _hessian(1, 1) = _tmp17;
    _hessian(1, 2) = 0;
    _hessian(1, 3) = 0;
    _hessian(1, 4) = 0;
    _hessian(1, 5) = 0;
    _hessian(2, 0) = _tmp21;
    _hessian(2, 1) = _tmp25;
    _hessian(2, 2) = _tmp29;
    _hessian(2, 3) = 0;
    _hessian(2, 4) = 0;
    _hessian(2, 5) = 0;
    _hessian(3, 0) = -_tmp6 - _tmp7 - _tmp8;
    _hessian(3, 1) = _tmp30;
    _hessian(3, 2) = _tmp31;
    _hessian(3, 3) = _tmp9;
    _hessian(3, 4) = 0;
    _hessian(3, 5) = 0;
    _hessian(4, 0) = _tmp30;
    _hessian(4, 1) = -_tmp14 - _tmp15 - _tmp16;
    _hessian(4, 2) = _tmp32;
    _hessian(4, 3) = _tmp13;
    _hessian(4, 4) = _tmp17;
    _hessian(4, 5) = 0;
    _hessian(5, 0) = _tmp31;
    _hessian(5, 1) = _tmp32;
    _hessian(5, 2) = -_tmp26 - _tmp27 - _tmp28;
    _hessian(5, 3) = _tmp21;
    _hessian(5, 4) = _tmp25;
    _hessian(5, 5) = _tmp29;
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 6, 1>& _rhs = (*rhs);

    _rhs(0, 0) = -_tmp33 - _tmp34 - _tmp35;
    _rhs(1, 0) = -_tmp36 - _tmp37 - _tmp38;
    _rhs(2, 0) = -_tmp39 - _tmp40 - _tmp41;
    _rhs(3, 0) = _tmp33 + _tmp34 + _tmp35;
    _rhs(4, 0) = _tmp36 + _tmp37 + _tmp38;
    _rhs(5, 0) = _tmp39 + _tmp40 + _tmp41;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
