include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES ../../quantity.h ../../quantity.cpp run_unit_tests.cpp quantity_test_conversion.hpp quantity_test_comparison.hpp)

add_executable(runUnitTest
        ${SOURCE_FILES})

target_link_libraries(runUnitTest gtest gtest_main)
