/**
 * @author: Balint Molnar
 * @date: 2017.04.21
 */

#ifndef SANDBOX_CONVERTERFUNCTION_TEST_HPP
#define SANDBOX_CONVERTERFUNCTION_TEST_HPP

#include "gtest/gtest.h"
#include "../../src/converter_function.hpp"

class TestConverterFunction : public testing::Test{};


TEST_F(TestConverterFunction, to_base_with_only_first_order_parameter_1_exponent_1){
    munits::ConverterFunction cf(1.0, 0., "");
    EXPECT_EQ(cf.to_base(1.0, 1), 1.0);
}
TEST_F(TestConverterFunction, to_base_with_only_first_order_parameter_1_exponent_neg1){
    munits::ConverterFunction cf(1.0, 0., "");
    EXPECT_EQ(cf.to_base(1.0, -1), 1.0);
}

TEST_F(TestConverterFunction, to_base_with_only_first_order_parameter_1_exponent_2){
    munits::ConverterFunction cf(1.0, 0., "");
    EXPECT_EQ(cf.to_base(1.0, 2), 1.0);
}

TEST_F(TestConverterFunction, to_base_with_only_first_order_parameter_10_exponent_1){
    munits::ConverterFunction cf(10.0, 0., "");
    EXPECT_EQ(cf.to_base(1.0, 1), 10.0);
}

TEST_F(TestConverterFunction, to_base_with_only_first_order_parameter_10_exponent_2){
    munits::ConverterFunction cf(10.0, 0., "");
    EXPECT_EQ(cf.to_base(1.0, 2), 100.0);
}

TEST_F(TestConverterFunction, to_base_with_only_first_order_parameter_10_exponent_neg1){
    munits::ConverterFunction cf(10.0, 0., "");
    EXPECT_EQ(cf.to_base(1.0, -1), .1);
}



#endif //SANDBOX_CONVERTERFUNCTION_TEST_HPP
