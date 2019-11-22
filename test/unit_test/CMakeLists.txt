include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES
        ../../src/quantity.h
        ../../src/quantity.cpp
        ../../src/converter_function.hpp
        ../../src/converter_function.cpp
        ../../src/unit.hpp
        ../../src/unit.cpp
        ../../src/unit_notation.cpp
        ../../src/unit_notation.hpp
        ../../src/parsers.cpp
        ../../src/parsers.hpp
        ../../src/uresolver.hpp
        ../../src/uresolver.cpp
        ../../src/metric.cpp
        ../../src/metric.hpp
        ../../src/converter.cpp
        ../../src/converter.hpp
        ../../src/dynamic.hpp
        ../../src/dynamic.cpp
        ../../src/uresolver.cpp
        ../../src/uresolver.hpp
        ../../lib/Accesories/mymath.hpp
        ../../src/prefix.cpp
        ../../src/prefix.hpp
        ../../src/parsers.hpp
        ../../src/searchers.cpp
        ../../src/searchers.hpp
        ../../src/unit_validator.cpp
        ../../src/unit_validator.hpp
        run_unit_tests.cpp
        quantity_test_conversion.hpp
        quantity_test_comparison.hpp
        quantity_test_base_mathop.hpp
        quantity_test_input_validation.hpp
        resolver_test.hpp
        quantity_test_representation.hpp
        converterfunction_test.hpp
        quantity_test_derived_mathop.hpp
        qunatity_test_basic_initialization.hpp
        unit_validation_test.hpp)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

add_executable(runUnitTest ${SOURCE_FILES})

target_link_libraries(runUnitTest gtest gtest_main)
