// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>

namespace buffer_test {

/**
 * This function was autogenerated. Do not modify by hand.
 *
 * Args:
 *     a: Scalar
 *     b: Scalar
 *     buffer: DataBuffer
 *
 * Outputs:
 *     result: Scalar
 */
template <typename Scalar>
Scalar BufferFunc(const Scalar a, const Scalar b, const Scalar* const buffer) {
  // Total ops: 9

  // Input arrays

  // Intermediate terms (0)

  // Output terms (1)
  Scalar _result;

  _result = a + b + buffer[static_cast<size_t>((-a + b) * (a + b))] +
            buffer[static_cast<size_t>(-std::pow(a, Scalar(2)) + std::pow(b, Scalar(2)))];

  return _result;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace buffer_test
