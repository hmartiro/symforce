// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>

namespace gnc_factors {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: barron_factor
 *
 * Args:
 *     x: Matrix51
 *     y: Matrix51
 *     mu: Scalar
 *     eps: Scalar
 *
 * Outputs:
 *     res: Matrix51
 *     jacobian: (5x5) jacobian of res wrt arg x (5)
 *     hessian: (5x5) Gauss-Newton hessian for arg x (5)
 *     rhs: (5x1) Gauss-Newton rhs for arg x (5)
 */
template <typename Scalar>
void BarronFactor(const Eigen::Matrix<Scalar, 5, 1>& x, const Eigen::Matrix<Scalar, 5, 1>& y,
                  const Scalar mu, const Scalar eps,
                  Eigen::Matrix<Scalar, 5, 1>* const res = nullptr,
                  Eigen::Matrix<Scalar, 5, 5>* const jacobian = nullptr,
                  Eigen::Matrix<Scalar, 5, 5>* const hessian = nullptr,
                  Eigen::Matrix<Scalar, 5, 1>* const rhs = nullptr) {
  // Total ops: 151

  // Input arrays

  // Intermediate terms (48)
  const Scalar _tmp0 = std::sqrt(eps);
  const Scalar _tmp1 = eps - mu + 1;
  const Scalar _tmp2 = eps + Scalar(1.0) / (std::fabs(_tmp1));
  const Scalar _tmp3 = Scalar(1.0) / (_tmp2);
  const Scalar _tmp4 = _tmp3 * std::pow(Scalar(x(0, 0) - y(0, 0)), Scalar(2)) + 1;
  const Scalar _tmp5 = Scalar(1.0) / (_tmp1);
  const Scalar _tmp6 = 2 - _tmp5;
  const Scalar _tmp7 = eps * (2 * std::min<Scalar>(0, (((_tmp6) > 0) - ((_tmp6) < 0))) + 1);
  const Scalar _tmp8 = -Scalar(1) / Scalar(2) * _tmp5 + (Scalar(1) / Scalar(2)) * _tmp7 + 1;
  const Scalar _tmp9 = std::pow(_tmp4, _tmp8);
  const Scalar _tmp10 = _tmp6 + _tmp7;
  const Scalar _tmp11 = Scalar(1.0) / (_tmp10);
  const Scalar _tmp12 = 2 * _tmp11 * _tmp2;
  const Scalar _tmp13 = _tmp12 * (_tmp9 - 1) + eps;
  const Scalar _tmp14 = std::sqrt(_tmp13);
  const Scalar _tmp15 = -_tmp0 + _tmp14;
  const Scalar _tmp16 = _tmp3 * std::pow(Scalar(x(1, 0) - y(1, 0)), Scalar(2)) + 1;
  const Scalar _tmp17 = std::pow(_tmp16, _tmp8);
  const Scalar _tmp18 = _tmp12 * (_tmp17 - 1) + eps;
  const Scalar _tmp19 = std::sqrt(_tmp18);
  const Scalar _tmp20 = -_tmp0 + _tmp19;
  const Scalar _tmp21 = _tmp3 * std::pow(Scalar(x(2, 0) - y(2, 0)), Scalar(2)) + 1;
  const Scalar _tmp22 = std::pow(_tmp21, _tmp8);
  const Scalar _tmp23 = _tmp12 * (_tmp22 - 1) + eps;
  const Scalar _tmp24 = std::sqrt(_tmp23);
  const Scalar _tmp25 = -_tmp0 + _tmp24;
  const Scalar _tmp26 = _tmp3 * std::pow(Scalar(x(3, 0) - y(3, 0)), Scalar(2)) + 1;
  const Scalar _tmp27 = std::pow(_tmp26, _tmp8);
  const Scalar _tmp28 = _tmp12 * (_tmp27 - 1) + eps;
  const Scalar _tmp29 = std::sqrt(_tmp28);
  const Scalar _tmp30 = -_tmp0 + _tmp29;
  const Scalar _tmp31 = _tmp3 * std::pow(Scalar(x(4, 0) - y(4, 0)), Scalar(2)) + 1;
  const Scalar _tmp32 = std::pow(_tmp31, _tmp8);
  const Scalar _tmp33 = _tmp12 * (_tmp32 - 1) + eps;
  const Scalar _tmp34 = std::sqrt(_tmp33);
  const Scalar _tmp35 = -_tmp0 + _tmp34;
  const Scalar _tmp36 = 2 * x(0, 0) - 2 * y(0, 0);
  const Scalar _tmp37 = _tmp11 * _tmp8;
  const Scalar _tmp38 = _tmp36 * _tmp37 * _tmp9 / (_tmp14 * _tmp4);
  const Scalar _tmp39 = 2 * x(1, 0) - 2 * y(1, 0);
  const Scalar _tmp40 = _tmp17 * _tmp37 * _tmp39 / (_tmp16 * _tmp19);
  const Scalar _tmp41 = 2 * x(2, 0) - 2 * y(2, 0);
  const Scalar _tmp42 = _tmp22 * _tmp37 * _tmp41 / (_tmp21 * _tmp24);
  const Scalar _tmp43 = 2 * x(3, 0) - 2 * y(3, 0);
  const Scalar _tmp44 = _tmp27 * _tmp37 * _tmp43 / (_tmp26 * _tmp29);
  const Scalar _tmp45 = 2 * x(4, 0) - 2 * y(4, 0);
  const Scalar _tmp46 = _tmp32 * _tmp37 * _tmp45 / (_tmp31 * _tmp34);
  const Scalar _tmp47 = std::pow(_tmp8, Scalar(2)) / std::pow(_tmp10, Scalar(2));

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 5, 1>& _res = (*res);

    _res(0, 0) = _tmp15;
    _res(1, 0) = _tmp20;
    _res(2, 0) = _tmp25;
    _res(3, 0) = _tmp30;
    _res(4, 0) = _tmp35;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 5, 5>& _jacobian = (*jacobian);

    _jacobian.setZero();

    _jacobian(0, 0) = _tmp38;
    _jacobian(1, 1) = _tmp40;
    _jacobian(2, 2) = _tmp42;
    _jacobian(3, 3) = _tmp44;
    _jacobian(4, 4) = _tmp46;
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 5, 5>& _hessian = (*hessian);

    _hessian.setZero();

    _hessian(0, 0) = std::pow(_tmp36, Scalar(2)) * std::pow(_tmp4, _tmp10) * _tmp47 /
                     (_tmp13 * std::pow(_tmp4, Scalar(2)));
    _hessian(1, 1) = std::pow(_tmp16, _tmp10) * std::pow(_tmp39, Scalar(2)) * _tmp47 /
                     (std::pow(_tmp16, Scalar(2)) * _tmp18);
    _hessian(2, 2) = std::pow(_tmp21, _tmp10) * std::pow(_tmp41, Scalar(2)) * _tmp47 /
                     (std::pow(_tmp21, Scalar(2)) * _tmp23);
    _hessian(3, 3) = std::pow(_tmp26, _tmp10) * std::pow(_tmp43, Scalar(2)) * _tmp47 /
                     (std::pow(_tmp26, Scalar(2)) * _tmp28);
    _hessian(4, 4) = std::pow(_tmp31, _tmp10) * std::pow(_tmp45, Scalar(2)) * _tmp47 /
                     (std::pow(_tmp31, Scalar(2)) * _tmp33);
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 5, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp15 * _tmp38;
    _rhs(1, 0) = _tmp20 * _tmp40;
    _rhs(2, 0) = _tmp25 * _tmp42;
    _rhs(3, 0) = _tmp30 * _tmp44;
    _rhs(4, 0) = _tmp35 * _tmp46;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace gnc_factors
