//
// Created by bmolnar on 2016. 11. 21..
//

#ifndef SANDBOX_QUANTITY_TEST_REPRESENTATION_HPP
#define SANDBOX_QUANTITY_TEST_REPRESENTATION_HPP

#include "gtest/gtest.h"
#include "../../src/quantity.h"

class TestQuantityBaseUnitsRepresentation : public testing::Test{};


TEST_F(TestQuantityBaseUnitsRepresentation, test_mass){
    munits::Quantity m1 (munits::Mass, 1, "kg");

    std::string s = (std::string) m1;

    EXPECT_EQ(s, "1 kg");

}
TEST_F(TestQuantityBaseUnitsRepresentation, test_time){
    munits::Quantity t1 (munits::Time, 1, "s");

    std::string s = (std::string) t1;

    EXPECT_EQ(s, "1 s");

}

#endif //SANDBOX_QUANTITY_TEST_REPRESENTATION_HPP
