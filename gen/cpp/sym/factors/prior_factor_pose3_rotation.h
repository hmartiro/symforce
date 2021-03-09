// -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>
#include <sym/pose3.h>
#include <sym/rot3.h>

namespace sym {

/**
 * Residual that penalizes the difference between a value and prior (desired / measured value).
 *
 * In vector space terms that would be:
 *     prior - value
 *
 * In lie group terms:
 *     to_tangent(compose(inverse(value), prior))
 *
 * Args:
 *     sqrt_info: Square root information matrix to whiten residual. This can be computed from
 *                a covariance matrix as the cholesky decomposition of the inverse. In the case
 *                of a diagonal it will contain 1/sigma values. Must match the tangent dim.
 *
 */
template <typename Scalar>
void PriorFactorPose3Rotation(const sym::Pose3<Scalar>& value, const sym::Rot3<Scalar>& prior,
                              const Eigen::Matrix<Scalar, 3, 3>& sqrt_info, const Scalar epsilon,
                              Eigen::Matrix<Scalar, 3, 1>* const res = nullptr,
                              Eigen::Matrix<Scalar, 3, 6>* const jac = nullptr) {
  // Total ops: 467

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _value = value.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _prior = prior.Data();

  // Intermediate terms (76)
  const Scalar _tmp0 =
      _prior[0] * _value[2] - _prior[1] * _value[3] - _prior[2] * _value[0] + _prior[3] * _value[1];
  const Scalar _tmp1 =
      _prior[0] * _value[0] + _prior[1] * _value[1] + _prior[2] * _value[2] + _prior[3] * _value[3];
  const Scalar _tmp2 = (((_tmp1) > 0) - ((_tmp1) < 0));
  const Scalar _tmp3 = 2 * std::min<Scalar>(0, _tmp2) + 1;
  const Scalar _tmp4 = std::fabs(_tmp1);
  const Scalar _tmp5 = 1 - epsilon;
  const Scalar _tmp6 = std::min<Scalar>(_tmp4, _tmp5);
  const Scalar _tmp7 = std::acos(_tmp6);
  const Scalar _tmp8 = 1 - (_tmp6 * _tmp6);
  const Scalar _tmp9 = 2 * _tmp7 / std::sqrt(_tmp8);
  const Scalar _tmp10 = _tmp3 * _tmp9;
  const Scalar _tmp11 = _tmp0 * _tmp10;
  const Scalar _tmp12 = -_prior[0] * _value[1] + _prior[1] * _value[0] - _prior[2] * _value[3] +
                        _prior[3] * _value[2];
  const Scalar _tmp13 = _tmp10 * _tmp12;
  const Scalar _tmp14 = -_prior[0] * _value[3] - _prior[1] * _value[2] + _prior[2] * _value[1] +
                        _prior[3] * _value[0];
  const Scalar _tmp15 = _tmp10 * _tmp14;
  const Scalar _tmp16 = _tmp9 * sqrt_info(2, 1);
  const Scalar _tmp17 = _tmp16 * _tmp3;
  const Scalar _tmp18 = _tmp10 * sqrt_info(2, 0);
  const Scalar _tmp19 = _prior[3] * _tmp3;
  const Scalar _tmp20 = _tmp2 * ((((-_tmp4 + _tmp5) > 0) - ((-_tmp4 + _tmp5) < 0)) + 1);
  const Scalar _tmp21 = _tmp20 / _tmp8;
  const Scalar _tmp22 = _tmp14 * _tmp21;
  const Scalar _tmp23 = _tmp19 * _tmp22;
  const Scalar _tmp24 = _tmp20 * _tmp6 * _tmp7 / (_tmp8 * std::sqrt(_tmp8));
  const Scalar _tmp25 = _tmp14 * _tmp24;
  const Scalar _tmp26 = _tmp25 * sqrt_info(0, 0);
  const Scalar _tmp27 = _prior[2] * _tmp3;
  const Scalar _tmp28 = _tmp27 * sqrt_info(0, 2);
  const Scalar _tmp29 = _tmp0 * _tmp24;
  const Scalar _tmp30 = _tmp29 * sqrt_info(0, 1);
  const Scalar _tmp31 = _tmp12 * _tmp21;
  const Scalar _tmp32 = _tmp19 * _tmp31;
  const Scalar _tmp33 = _tmp0 * _tmp21;
  const Scalar _tmp34 = _tmp33 * sqrt_info(0, 1);
  const Scalar _tmp35 = _prior[0] * _tmp3;
  const Scalar _tmp36 = _tmp35 * _tmp9;
  const Scalar _tmp37 = _tmp12 * _tmp24;
  const Scalar _tmp38 = _tmp19 * _tmp37;
  const Scalar _tmp39 = _prior[1] * _tmp10;
  const Scalar _tmp40 = _tmp19 * _tmp26 + _tmp19 * _tmp30 - _tmp19 * _tmp34 -
                        _tmp23 * sqrt_info(0, 0) - _tmp28 * _tmp9 - _tmp32 * sqrt_info(0, 2) -
                        _tmp36 * sqrt_info(0, 0) + _tmp38 * sqrt_info(0, 2) -
                        _tmp39 * sqrt_info(0, 1);
  const Scalar _tmp41 = (1.0 / 2.0) * _value[0];
  const Scalar _tmp42 = _prior[3] * _tmp10;
  const Scalar _tmp43 = _tmp22 * _tmp27;
  const Scalar _tmp44 = _tmp26 * _tmp27 + _tmp27 * _tmp30 - _tmp27 * _tmp34 - _tmp28 * _tmp31 +
                        _tmp28 * _tmp37 + _tmp36 * sqrt_info(0, 1) - _tmp39 * sqrt_info(0, 0) +
                        _tmp42 * sqrt_info(0, 2) - _tmp43 * sqrt_info(0, 0);
  const Scalar _tmp45 = (1.0 / 2.0) * _value[1];
  const Scalar _tmp46 = _prior[1] * _tmp3;
  const Scalar _tmp47 = _tmp46 * sqrt_info(0, 2);
  const Scalar _tmp48 = _tmp22 * _tmp46;
  const Scalar _tmp49 = _tmp27 * _tmp9;
  const Scalar _tmp50 = _tmp26 * _tmp46 + _tmp30 * _tmp46 - _tmp31 * _tmp47 - _tmp34 * _tmp46 -
                        _tmp36 * sqrt_info(0, 2) + _tmp37 * _tmp47 + _tmp42 * sqrt_info(0, 1) -
                        _tmp48 * sqrt_info(0, 0) + _tmp49 * sqrt_info(0, 0);
  const Scalar _tmp51 = (1.0 / 2.0) * _value[2];
  const Scalar _tmp52 = _tmp22 * _tmp35;
  const Scalar _tmp53 = _tmp31 * _tmp35;
  const Scalar _tmp54 = _tmp35 * _tmp37;
  const Scalar _tmp55 = _tmp26 * _tmp35 + _tmp30 * _tmp35 - _tmp34 * _tmp35 +
                        _tmp39 * sqrt_info(0, 2) + _tmp42 * sqrt_info(0, 0) -
                        _tmp49 * sqrt_info(0, 1) - _tmp52 * sqrt_info(0, 0) -
                        _tmp53 * sqrt_info(0, 2) + _tmp54 * sqrt_info(0, 2);
  const Scalar _tmp56 = (1.0 / 2.0) * _value[3];
  const Scalar _tmp57 = _tmp25 * sqrt_info(1, 0);
  const Scalar _tmp58 = _tmp33 * sqrt_info(1, 1);
  const Scalar _tmp59 = _tmp29 * sqrt_info(1, 1);
  const Scalar _tmp60 = _tmp19 * _tmp57 - _tmp19 * _tmp58 + _tmp19 * _tmp59 -
                        _tmp23 * sqrt_info(1, 0) - _tmp32 * sqrt_info(1, 2) -
                        _tmp36 * sqrt_info(1, 0) + _tmp38 * sqrt_info(1, 2) -
                        _tmp39 * sqrt_info(1, 1) - _tmp49 * sqrt_info(1, 2);
  const Scalar _tmp61 = _tmp27 * _tmp37;
  const Scalar _tmp62 = _tmp31 * sqrt_info(1, 2);
  const Scalar _tmp63 = _tmp27 * _tmp57 - _tmp27 * _tmp58 + _tmp27 * _tmp59 - _tmp27 * _tmp62 +
                        _tmp36 * sqrt_info(1, 1) - _tmp39 * sqrt_info(1, 0) +
                        _tmp42 * sqrt_info(1, 2) - _tmp43 * sqrt_info(1, 0) +
                        _tmp61 * sqrt_info(1, 2);
  const Scalar _tmp64 = _tmp37 * _tmp46;
  const Scalar _tmp65 = -_tmp36 * sqrt_info(1, 2) + _tmp42 * sqrt_info(1, 1) + _tmp46 * _tmp57 -
                        _tmp46 * _tmp58 + _tmp46 * _tmp59 - _tmp46 * _tmp62 -
                        _tmp48 * sqrt_info(1, 0) + _tmp49 * sqrt_info(1, 0) +
                        _tmp64 * sqrt_info(1, 2);
  const Scalar _tmp66 = _tmp35 * _tmp57 - _tmp35 * _tmp58 + _tmp35 * _tmp59 +
                        _tmp39 * sqrt_info(1, 2) + _tmp42 * sqrt_info(1, 0) -
                        _tmp49 * sqrt_info(1, 1) - _tmp52 * sqrt_info(1, 0) -
                        _tmp53 * sqrt_info(1, 2) + _tmp54 * sqrt_info(1, 2);
  const Scalar _tmp67 = _tmp25 * sqrt_info(2, 0);
  const Scalar _tmp68 = _tmp33 * sqrt_info(2, 1);
  const Scalar _tmp69 = _tmp31 * sqrt_info(2, 2);
  const Scalar _tmp70 = _tmp29 * sqrt_info(2, 1);
  const Scalar _tmp71 = -_prior[1] * _tmp18 + _tmp16 * _tmp35 + _tmp27 * _tmp67 - _tmp27 * _tmp68 -
                        _tmp27 * _tmp69 + _tmp27 * _tmp70 + _tmp42 * sqrt_info(2, 2) -
                        _tmp43 * sqrt_info(2, 0) + _tmp61 * sqrt_info(2, 2);
  const Scalar _tmp72 = _prior[3] * _tmp17 - _tmp36 * sqrt_info(2, 2) + _tmp46 * _tmp67 -
                        _tmp46 * _tmp68 - _tmp46 * _tmp69 + _tmp46 * _tmp70 -
                        _tmp48 * sqrt_info(2, 0) + _tmp49 * sqrt_info(2, 0) +
                        _tmp64 * sqrt_info(2, 2);
  const Scalar _tmp73 = -_prior[1] * _tmp17 + _tmp19 * _tmp67 - _tmp19 * _tmp68 + _tmp19 * _tmp70 -
                        _tmp23 * sqrt_info(2, 0) - _tmp32 * sqrt_info(2, 2) -
                        _tmp36 * sqrt_info(2, 0) + _tmp38 * sqrt_info(2, 2) -
                        _tmp49 * sqrt_info(2, 2);
  const Scalar _tmp74 = _prior[3] * _tmp18 - _tmp16 * _tmp27 + _tmp35 * _tmp67 - _tmp35 * _tmp68 -
                        _tmp35 * _tmp69 + _tmp35 * _tmp70 + _tmp39 * sqrt_info(2, 2) -
                        _tmp52 * sqrt_info(2, 0) + _tmp54 * sqrt_info(2, 2);
  const Scalar _tmp75 = (1.0 / 2.0) * _tmp72;

  // Output terms (2)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _res = (*res);

    _res(0, 0) = _tmp11 * sqrt_info(0, 1) + _tmp13 * sqrt_info(0, 2) + _tmp15 * sqrt_info(0, 0);
    _res(1, 0) = _tmp11 * sqrt_info(1, 1) + _tmp13 * sqrt_info(1, 2) + _tmp15 * sqrt_info(1, 0);
    _res(2, 0) = _tmp0 * _tmp17 + _tmp13 * sqrt_info(2, 2) + _tmp14 * _tmp18;
  }

  if (jac != nullptr) {
    Eigen::Matrix<Scalar, 3, 6>& _jac = (*jac);

    _jac(0, 0) = -_tmp40 * _tmp41 - _tmp44 * _tmp45 + _tmp50 * _tmp51 + _tmp55 * _tmp56;
    _jac(0, 1) = -_tmp40 * _tmp45 + _tmp41 * _tmp44 + _tmp50 * _tmp56 - _tmp51 * _tmp55;
    _jac(0, 2) = -_tmp40 * _tmp51 - _tmp41 * _tmp50 + _tmp44 * _tmp56 + _tmp45 * _tmp55;
    _jac(0, 3) = 0;
    _jac(0, 4) = 0;
    _jac(0, 5) = 0;
    _jac(1, 0) = -_tmp41 * _tmp60 - _tmp45 * _tmp63 + _tmp51 * _tmp65 + _tmp56 * _tmp66;
    _jac(1, 1) = _tmp41 * _tmp63 - _tmp45 * _tmp60 - _tmp51 * _tmp66 + _tmp56 * _tmp65;
    _jac(1, 2) = -_tmp41 * _tmp65 + _tmp45 * _tmp66 - _tmp51 * _tmp60 + _tmp56 * _tmp63;
    _jac(1, 3) = 0;
    _jac(1, 4) = 0;
    _jac(1, 5) = 0;
    _jac(2, 0) = -_tmp41 * _tmp73 - _tmp45 * _tmp71 + _tmp51 * _tmp72 + _tmp56 * _tmp74;
    _jac(2, 1) = _tmp41 * _tmp71 - _tmp45 * _tmp73 - _tmp51 * _tmp74 + _tmp75 * _value[3];
    _jac(2, 2) = _tmp45 * _tmp74 - _tmp51 * _tmp73 + _tmp56 * _tmp71 - _tmp75 * _value[0];
    _jac(2, 3) = 0;
    _jac(2, 4) = 0;
    _jac(2, 5) = 0;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
