//
// Created by bmolnar on 2016. 11. 21..
//

#ifndef SANDBOX_QUANTITY_TEST_REPRESENTATION_HPP
#define SANDBOX_QUANTITY_TEST_REPRESENTATION_HPP

#include "gtest/gtest.h"
#include "../../src/quantity.h"

class TestQuantityBaseUnitsRepresentation : public testing::Test{};
class TestQuantityDerivedUnitsRepresentation : public testing::Test{};


TEST_F(TestQuantityBaseUnitsRepresentation, test_mass){
    munits::Quantity m1 (munits::Mass, 1, "kg");

    std::string s = (std::string &&) m1;

    EXPECT_EQ(s, "1 kg");

}
TEST_F(TestQuantityBaseUnitsRepresentation, test_time){
    munits::Quantity t1 (munits::Time, 1, "s");

    std::string s = (std::string &&) t1;

    EXPECT_EQ(s, "1 s");

}

TEST_F(TestQuantityBaseUnitsRepresentation, test_legth){
    munits::Quantity l1 (munits::Length, 1, "inc");

    std::string s = (std::string &&) l1;

    EXPECT_EQ(s, "1 inc");

}

TEST_F(TestQuantityBaseUnitsRepresentation, test_temperature){
    munits::Quantity l1 (munits::Temperature, 1, "°C");

    std::string s = (std::string &&) l1;

    EXPECT_EQ(s, "1 °C");

}
TEST_F(TestQuantityBaseUnitsRepresentation, test_amount_of_substance){
    munits::Quantity l1 (munits::AmountOfSubstance, 1, "mol");

    std::string s = (std::string &&) l1;

    EXPECT_EQ(s, "1 mol");

}

TEST_F(TestQuantityDerivedUnitsRepresentation, test_velocity_direct_creation){
    munits::Quantity l1 (munits::Velocity, 1, "m s-1");

    std::string s = (std::string &&) l1;

    EXPECT_EQ(s, "1 m s-1");

}

TEST_F(TestQuantityDerivedUnitsRepresentation, test_velocity_indirect_creation){
    munits::Quantity l1 (munits::Length, 1, "m");
    munits::Quantity t1 (munits::Time, 1, "s");

    auto v1 = l1 / t1;

    std::string s = (std::string &&) v1;

    EXPECT_EQ(s, "1 m s-1");

}

TEST_F(TestQuantityDerivedUnitsRepresentation, test_force_direct_creation){
    munits::Quantity f (munits::Force, 1, "kg m s-2");


    std::string s = (std::string &&) f;

    EXPECT_EQ(s, "1 N"); // should be represented as N

}
TEST_F(TestQuantityDerivedUnitsRepresentation, test_force_indirect_creation){
    munits::Quantity a (munits::Acceleration, 1, "m s-2");
    munits::Quantity m (munits::Mass, 1, "kg");

    auto f = m * a;

    std::string s = (std::string &&) f;

    EXPECT_EQ(s, "1 N"); // should be represented as N

}
TEST_F(TestQuantityDerivedUnitsRepresentation, test_mass_flow_indirect_creation){
    munits::Quantity q (munits::VolumetricFlow, 1, "m3 h-1");
    munits::Quantity c (munits::Concentration, 1, "g l-1");

    auto mdot = q * c;

    std::string s = (std::string &&) mdot;

    EXPECT_EQ(s, "1000 g h-1"); // should be represented as N

}




#endif //SANDBOX_QUANTITY_TEST_REPRESENTATION_HPP
