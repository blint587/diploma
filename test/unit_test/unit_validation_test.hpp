//
// Created by bmolnar on 2019. 11. 21..
//

#ifndef MUNITS_UNIT_VALIDATION_TEST_HPP
#define MUNITS_UNIT_VALIDATION_TEST_HPP

#include "gtest/gtest.h"
#include "../../src/unit_validator.hpp"
#include "../../src/dynamic.hpp"
#include "../../src/unit_notation.hpp"

typedef  munits::UnitNotationVector un;

class TestUnitValidator : public testing::Test{};

TEST_F(TestUnitValidator, Validate_length){
    /*
     * Passing "m" as unit and Length
     * should return True
     */
    EXPECT_TRUE(munits::validate_unit(un::compose_unit_vector("m"), munits::Length));
}

TEST_F(TestUnitValidator, Validate_volume){
    /*
     * Passing "gal" as unit and Volume
     * should return True
     */
    EXPECT_TRUE(munits::validate_unit(un::compose_unit_vector("gal"), munits::Volume));
}

TEST_F(TestUnitValidator, Validate_force){
    /*
     * Passing "N" as unit and Force
     * should return True
     */
    EXPECT_TRUE(munits::validate_unit(un::compose_unit_vector("N"), munits::Force));
}

TEST_F(TestUnitValidator, Validate_power){
    /*
     * Passing "W" as unit and Power
     * should return True
     */
    EXPECT_TRUE(munits::validate_unit(un::compose_unit_vector("W"), munits::Power));
}

TEST_F(TestUnitValidator, Validate_power_abnormal){
    /*
     * Passing "kW h d-1" as unit and Power
     * should return True
     */
    EXPECT_TRUE(munits::validate_unit(un::compose_unit_vector("kW h d-1"), munits::Power));
}

TEST_F(TestUnitValidator, Validate_volumetricflow){
    /*
     * Passing "MGD" as unit and VolumetricFlow
     * should return True
     */
    EXPECT_TRUE(munits::validate_unit(un::compose_unit_vector("MGD"), munits::VolumetricFlow));
}

TEST_F(TestUnitValidator, Distingushe_length_from_volume){
    /*
     * Passing "m" as unit and Volume
     * should return True
     */
    EXPECT_FALSE(munits::validate_unit(un::compose_unit_vector("m"), munits::Volume));
}

TEST_F(TestUnitValidator, Distingushe_volume_from_lenght){
    /*
     * Passing "m3" as unit and Length
     * should return True
     */
    EXPECT_FALSE(munits::validate_unit(un::compose_unit_vector("m3"), munits::Length));
}

TEST_F(TestUnitValidator, Distingushe_volume_from_lenght_2){
    /*
     * Passing "gal" as unit and Length
     * should return True
     */
    EXPECT_FALSE(munits::validate_unit(un::compose_unit_vector("gal"), munits::Length));
}



#endif //MUNITS_UNIT_VALIDATION_TEST_HPP
