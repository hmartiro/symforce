#include <sym/rot3.h>
#include <symforce/codegen_cpp_test/codegen_cpp_test.h>

#include <lcmtypes/codegen_cpp_test/constants_t.hpp>
#include <lcmtypes/codegen_cpp_test/states_t.hpp>
#include <lcmtypes/codegen_cpp_test/values_vec_t.hpp>

// TODO(hayk): Use the catch unit testing framework (single header).
#define assertTrue(a)                                      \
  if (!(a)) {                                              \
    std::ostringstream o;                                  \
    o << __FILE__ << ":" << __LINE__ << ": Test failure."; \
    throw std::runtime_error(o.str());                     \
  }

int main(int argc, char** argv) {
  double x = 2.0;
  double y = -5.0;
  sym::Rot3<double> rot;
  std::array<sym::Rot3<double>, 3> rot_vec;
  std::array<double, 3> scalar_vec;
  std::array<std::array<sym::Rot3<double>, 3>, 3> list_of_lists;
  std::array<codegen_cpp_test::values_vec_t, 3> values_vec;
  std::array<std::array<codegen_cpp_test::values_vec_t, 1>, 2> values_vec_2D;
  codegen_cpp_test::states_t states;
  states.p[0] = 1.0;
  states.p[1] = 2.0;
  codegen_cpp_test::constants_t constants;
  constants.epsilon = 1e-8;

  double foo;
  double bar;
  std::array<double, 3> scalar_vec_out;
  std::array<codegen_cpp_test::values_vec_t, 3> values_vec_out;
  std::array<std::array<codegen_cpp_test::values_vec_t, 1>, 2> values_vec_2D_out;

  codegen_cpp_test::CodegenCppTest<double>(x, y, rot, rot_vec, scalar_vec, list_of_lists,
                                           values_vec, values_vec_2D, constants, states, &foo, &bar,
                                           &scalar_vec_out, &values_vec_out, &values_vec_2D_out);
  assertTrue(std::abs(foo - (std::pow(x, 2) + rot.Data()[3])) < 1e-8);
  assertTrue(std::abs(bar - (constants.epsilon + std::sin(y) + std::pow(x, 2))) < 1e-8);
  // TODO(nathan): Check other outputs (just checking that things compile for now)
}
