# ----------------------------------------------------------------------------
# SymForce - Copyright 2022, Skydio, Inc.
# This source code is under the Apache 2.0 license found in the LICENSE file.
# ----------------------------------------------------------------------------

include(FetchContent)

find_package(pybind11 QUIET)
if (NOT pybind11_FOUND)
  message(STATUS "pybind11 not found, adding with FetchContent")
  FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11
    GIT_TAG e7c9753f1d35061d137ac3ce561e94a7407e5583 # release 2.8.1
  )
  FetchContent_MakeAvailable(pybind11)
else()
  message(STATUS "pybind11 found")
endif()

pybind11_add_module(
  cc_sym
  SHARED
  cc_factor.cc
  cc_key.cc
  cc_linearization.cc
  cc_logger.cc
  cc_optimization_stats.cc
  cc_optimizer.cc
  cc_sym.cc
  cc_values.cc
  sym_type_casters.cc
)

if(SYMFORCE_PY_EXTENSION_MODULE_OUTPUT_PATH)
  set_target_properties(cc_sym PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${SYMFORCE_PY_EXTENSION_MODULE_OUTPUT_PATH}
  )
endif()

target_link_libraries(
  cc_sym
  PRIVATE
  symforce_opt
  symforce_gen
)
