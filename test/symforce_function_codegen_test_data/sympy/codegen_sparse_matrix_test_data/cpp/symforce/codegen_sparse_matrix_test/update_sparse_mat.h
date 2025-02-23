// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>
#include <Eigen/Sparse>

namespace codegen_sparse_matrix_test {

/**
 * This function was autogenerated. Do not modify by hand.
 *
 * Args:
 *     matrix_in: Matrix100_100
 *
 * Outputs:
 *     updated_mat: Matrix100_100
 */
template <typename Scalar>
void UpdateSparseMat(const Eigen::Matrix<Scalar, 100, 100>& matrix_in,
                     Eigen::SparseMatrix<Scalar>* const updated_mat = nullptr) {
  // Total ops: 100

  // Input arrays

  // Intermediate terms (0)

  // Output terms (1)
  if (updated_mat != nullptr) {
    static constexpr int kRows_updated_mat = 100;
    static constexpr int kCols_updated_mat = 100;
    static constexpr int kNumNonZero_updated_mat = 100;
    static constexpr int kColPtrs_updated_mat[] = {
        0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
        42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
        63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,
        84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
    static constexpr int kRowIndices_updated_mat[] = {
        0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
        40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
        60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
        80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
    if (updated_mat->nonZeros() != 100 || updated_mat->outerSize() != 100 ||
        updated_mat->innerSize() != 100 || !updated_mat->isCompressed()) {
      // Matrix does not have the expected layout, create a correctly initialized sparse matrix
      Scalar updated_mat_empty_value_ptr[100];
      *updated_mat = Eigen::Map<const Eigen::SparseMatrix<Scalar>>(
          kRows_updated_mat, kCols_updated_mat, kNumNonZero_updated_mat, kColPtrs_updated_mat,
          kRowIndices_updated_mat, updated_mat_empty_value_ptr);
    }
    Scalar* updated_mat_value_ptr = updated_mat->valuePtr();

    updated_mat_value_ptr[0] = 2 * matrix_in(0, 0);
    updated_mat_value_ptr[1] = 2 * matrix_in(1, 1);
    updated_mat_value_ptr[2] = 2 * matrix_in(2, 2);
    updated_mat_value_ptr[3] = 2 * matrix_in(3, 3);
    updated_mat_value_ptr[4] = 2 * matrix_in(4, 4);
    updated_mat_value_ptr[5] = 2 * matrix_in(5, 5);
    updated_mat_value_ptr[6] = 2 * matrix_in(6, 6);
    updated_mat_value_ptr[7] = 2 * matrix_in(7, 7);
    updated_mat_value_ptr[8] = 2 * matrix_in(8, 8);
    updated_mat_value_ptr[9] = 2 * matrix_in(9, 9);
    updated_mat_value_ptr[10] = 2 * matrix_in(10, 10);
    updated_mat_value_ptr[11] = 2 * matrix_in(11, 11);
    updated_mat_value_ptr[12] = 2 * matrix_in(12, 12);
    updated_mat_value_ptr[13] = 2 * matrix_in(13, 13);
    updated_mat_value_ptr[14] = 2 * matrix_in(14, 14);
    updated_mat_value_ptr[15] = 2 * matrix_in(15, 15);
    updated_mat_value_ptr[16] = 2 * matrix_in(16, 16);
    updated_mat_value_ptr[17] = 2 * matrix_in(17, 17);
    updated_mat_value_ptr[18] = 2 * matrix_in(18, 18);
    updated_mat_value_ptr[19] = 2 * matrix_in(19, 19);
    updated_mat_value_ptr[20] = 2 * matrix_in(20, 20);
    updated_mat_value_ptr[21] = 2 * matrix_in(21, 21);
    updated_mat_value_ptr[22] = 2 * matrix_in(22, 22);
    updated_mat_value_ptr[23] = 2 * matrix_in(23, 23);
    updated_mat_value_ptr[24] = 2 * matrix_in(24, 24);
    updated_mat_value_ptr[25] = 2 * matrix_in(25, 25);
    updated_mat_value_ptr[26] = 2 * matrix_in(26, 26);
    updated_mat_value_ptr[27] = 2 * matrix_in(27, 27);
    updated_mat_value_ptr[28] = 2 * matrix_in(28, 28);
    updated_mat_value_ptr[29] = 2 * matrix_in(29, 29);
    updated_mat_value_ptr[30] = 2 * matrix_in(30, 30);
    updated_mat_value_ptr[31] = 2 * matrix_in(31, 31);
    updated_mat_value_ptr[32] = 2 * matrix_in(32, 32);
    updated_mat_value_ptr[33] = 2 * matrix_in(33, 33);
    updated_mat_value_ptr[34] = 2 * matrix_in(34, 34);
    updated_mat_value_ptr[35] = 2 * matrix_in(35, 35);
    updated_mat_value_ptr[36] = 2 * matrix_in(36, 36);
    updated_mat_value_ptr[37] = 2 * matrix_in(37, 37);
    updated_mat_value_ptr[38] = 2 * matrix_in(38, 38);
    updated_mat_value_ptr[39] = 2 * matrix_in(39, 39);
    updated_mat_value_ptr[40] = 2 * matrix_in(40, 40);
    updated_mat_value_ptr[41] = 2 * matrix_in(41, 41);
    updated_mat_value_ptr[42] = 2 * matrix_in(42, 42);
    updated_mat_value_ptr[43] = 2 * matrix_in(43, 43);
    updated_mat_value_ptr[44] = 2 * matrix_in(44, 44);
    updated_mat_value_ptr[45] = 2 * matrix_in(45, 45);
    updated_mat_value_ptr[46] = 2 * matrix_in(46, 46);
    updated_mat_value_ptr[47] = 2 * matrix_in(47, 47);
    updated_mat_value_ptr[48] = 2 * matrix_in(48, 48);
    updated_mat_value_ptr[49] = 2 * matrix_in(49, 49);
    updated_mat_value_ptr[50] = 2 * matrix_in(50, 50);
    updated_mat_value_ptr[51] = 2 * matrix_in(51, 51);
    updated_mat_value_ptr[52] = 2 * matrix_in(52, 52);
    updated_mat_value_ptr[53] = 2 * matrix_in(53, 53);
    updated_mat_value_ptr[54] = 2 * matrix_in(54, 54);
    updated_mat_value_ptr[55] = 2 * matrix_in(55, 55);
    updated_mat_value_ptr[56] = 2 * matrix_in(56, 56);
    updated_mat_value_ptr[57] = 2 * matrix_in(57, 57);
    updated_mat_value_ptr[58] = 2 * matrix_in(58, 58);
    updated_mat_value_ptr[59] = 2 * matrix_in(59, 59);
    updated_mat_value_ptr[60] = 2 * matrix_in(60, 60);
    updated_mat_value_ptr[61] = 2 * matrix_in(61, 61);
    updated_mat_value_ptr[62] = 2 * matrix_in(62, 62);
    updated_mat_value_ptr[63] = 2 * matrix_in(63, 63);
    updated_mat_value_ptr[64] = 2 * matrix_in(64, 64);
    updated_mat_value_ptr[65] = 2 * matrix_in(65, 65);
    updated_mat_value_ptr[66] = 2 * matrix_in(66, 66);
    updated_mat_value_ptr[67] = 2 * matrix_in(67, 67);
    updated_mat_value_ptr[68] = 2 * matrix_in(68, 68);
    updated_mat_value_ptr[69] = 2 * matrix_in(69, 69);
    updated_mat_value_ptr[70] = 2 * matrix_in(70, 70);
    updated_mat_value_ptr[71] = 2 * matrix_in(71, 71);
    updated_mat_value_ptr[72] = 2 * matrix_in(72, 72);
    updated_mat_value_ptr[73] = 2 * matrix_in(73, 73);
    updated_mat_value_ptr[74] = 2 * matrix_in(74, 74);
    updated_mat_value_ptr[75] = 2 * matrix_in(75, 75);
    updated_mat_value_ptr[76] = 2 * matrix_in(76, 76);
    updated_mat_value_ptr[77] = 2 * matrix_in(77, 77);
    updated_mat_value_ptr[78] = 2 * matrix_in(78, 78);
    updated_mat_value_ptr[79] = 2 * matrix_in(79, 79);
    updated_mat_value_ptr[80] = 2 * matrix_in(80, 80);
    updated_mat_value_ptr[81] = 2 * matrix_in(81, 81);
    updated_mat_value_ptr[82] = 2 * matrix_in(82, 82);
    updated_mat_value_ptr[83] = 2 * matrix_in(83, 83);
    updated_mat_value_ptr[84] = 2 * matrix_in(84, 84);
    updated_mat_value_ptr[85] = 2 * matrix_in(85, 85);
    updated_mat_value_ptr[86] = 2 * matrix_in(86, 86);
    updated_mat_value_ptr[87] = 2 * matrix_in(87, 87);
    updated_mat_value_ptr[88] = 2 * matrix_in(88, 88);
    updated_mat_value_ptr[89] = 2 * matrix_in(89, 89);
    updated_mat_value_ptr[90] = 2 * matrix_in(90, 90);
    updated_mat_value_ptr[91] = 2 * matrix_in(91, 91);
    updated_mat_value_ptr[92] = 2 * matrix_in(92, 92);
    updated_mat_value_ptr[93] = 2 * matrix_in(93, 93);
    updated_mat_value_ptr[94] = 2 * matrix_in(94, 94);
    updated_mat_value_ptr[95] = 2 * matrix_in(95, 95);
    updated_mat_value_ptr[96] = 2 * matrix_in(96, 96);
    updated_mat_value_ptr[97] = 2 * matrix_in(97, 97);
    updated_mat_value_ptr[98] = 2 * matrix_in(98, 98);
    updated_mat_value_ptr[99] = 2 * matrix_in(99, 99);
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace codegen_sparse_matrix_test
