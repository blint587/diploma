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
        run_unit_tests.cpp
        quantity_test_conversion.hpp
        quantity_test_comparison.hpp
        quantity_test_mathop.hpp
        quantity_test_input_validation.hpp

        ../../src/metric.cpp ../../src/metric.hpp ../../src/converter.cpp ../../src/converter.hpp ../../src/dynamic.hpp ../../src/dynamic.cpp quantity_test_representation.hpp)

add_executable(runUnitTest
        ${SOURCE_FILES})

target_link_libraries(runUnitTest gtest gtest_main)
