cmake_minimum_required (VERSION 3.8)
project (Evaluator)

set (CMAKE_CXX_STANDARD 11)
  
add_subdirectory(interpreter)

add_executable(Evaluator main.cpp)

target_link_libraries(Evaluator Interpreter)

include(CheckIPOSupported)
check_ipo_supported(RESULT result OUTPUT output)
if(result)
  set_property(TARGET Evaluator PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
  message(WARNING "IPO is not supported: ${output}")
endif()

include(CTest)

macro (do_test arg result)
  set(test_name Evaluator_${arg})
  add_test (${test_name} Evaluator ${PROJECT_SOURCE_DIR}/tests/${arg})
  set_tests_properties (${test_name}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

do_test (trivial "x = 1")
do_test (simple_sum "x = 6")
do_test (reversed_order "x = 1\ny = 1")
do_test (multi_level "x = 1\ny = 1\nz = 1")
do_test (example "location = 16\noffset = 7\norigin = 8\nrandom = 2")