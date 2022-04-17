/**
 * @author: Balint Molnar
 * @date: 2017.04.24
 */
#ifndef SANDBOX_QUANTITY_TEST_DERIVED_MATHOP_HPP
#define SANDBOX_QUANTITY_TEST_DERIVED_MATHOP_HPP

#include "gtest/gtest.h"
#include "../../src/quantity.h"

class TestQuantityDerivedUnitsCreateDerivedUnitsViaMathOperation : public testing::Test{};
class TestQuantityDerivedUnitsConversionDurnigMathOperation : public testing::Test{};


TEST_F(TestQuantityDerivedUnitsCreateDerivedUnitsViaMathOperation, create_create_volumetricflow_zero){
    munits::Quantity v (munits::Volume, 0, "m3");
    munits::Quantity t (munits::Time, 1, "h");
    munits::Quantity vf = v / t;
    EXPECT_EQ(vf.getMatrixIndex(), munits::VolumetricFlow);
    EXPECT_EQ(vf("m3 h-1"), 0.);
}

TEST_F(TestQuantityDerivedUnitsCreateDerivedUnitsViaMathOperation, create_volumetricflow_233_2){
    munits::Quantity v (munits::Volume,12.649, "m3");
    munits::Quantity t (munits::Time, 2.33, "h");
    munits::Quantity vf2 = v / t;

    EXPECT_EQ(vf2.getMatrixIndex(), munits::VolumetricFlow);
    EXPECT_NEAR(vf2("m3 h-1"), 5.4289, 1e-3);
}

TEST_F(TestQuantityDerivedUnitsCreateDerivedUnitsViaMathOperation, create_molar_concentration_from_n_l_v_zero_4){
    munits::Quantity v (munits::Volume,  1, "m3");
    munits::Quantity n (munits::AmountOfSubstance, 0, "mol");
    munits::Quantity mc4 = n / v;

    EXPECT_EQ(mc4.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc4("mol m-3"), 0.);
}

TEST_F(TestQuantityDerivedUnitsCreateDerivedUnitsViaMathOperation, create_molar_concentration_from_n_l_v_4){
    munits::Quantity v (munits::Volume, 1, "m3");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc4 = n / v;

    EXPECT_EQ(mc4.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc4("mol m-3"), 1.);
}
TEST_F(TestQuantityDerivedUnitsCreateDerivedUnitsViaMathOperation, create_molar_concentration_from_n_l_v_233_4){
    munits::Quantity v (munits::Volume, 12.649, "m3");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc4 = n / v;

    EXPECT_EQ(mc4.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_NEAR(mc4("mol m-3"), 0.0790, 1e-3);
}


TEST_F(TestQuantityDerivedUnitsCreateDerivedUnitsViaMathOperation, create_force_from_m_a_zero){
    munits::Quantity m (munits::Mass, 0, "g");
    munits::Quantity a (munits::Acceleration, 0, "m s-2");
    munits::Quantity f1 = m * a;
    EXPECT_EQ(f1.getMatrixIndex(), munits::Force);
    EXPECT_EQ(f1("kg m s-2"), 0.);
}
TEST_F(TestQuantityDerivedUnitsCreateDerivedUnitsViaMathOperation, create_force_from_m_a){
    munits::Quantity m (munits::Mass, 1, "kg");
    munits::Quantity a (munits::Acceleration, 1, "m s-2");
    munits::Quantity f1 = m * a;
    EXPECT_EQ(f1.getMatrixIndex(), munits::Force);
    EXPECT_EQ(f1("kg m s-2"), 1);
}
TEST_F(TestQuantityDerivedUnitsCreateDerivedUnitsViaMathOperation, create_force_from_m_a_233){
    munits::Quantity m (munits::Mass, 2.33, "kg");
    munits::Quantity a (munits::Acceleration, 1, "m s-2");
    munits::Quantity f1 = m * a;
    EXPECT_EQ(f1.getMatrixIndex(), munits::Force);
    EXPECT_EQ(f1("kg m s-2"), 2.33);
}

TEST_F(TestQuantityDerivedUnitsCreateDerivedUnitsViaMathOperation, create_power_from_force_length_and_time){
    munits::Quantity f (munits::Force, 2.33, "N");
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity t (munits::Time, 1, "s");

    munits::Quantity p = f * l / t;
    EXPECT_EQ(p.getMatrixIndex(), munits::Power);
    EXPECT_EQ(p("W"), 2.33);
}

TEST_F(TestQuantityDerivedUnitsCreateDerivedUnitsViaMathOperation, create_power_from_power){
    munits::Quantity f (munits::Power, 1, "kW");
    munits::Quantity t1 (munits::Time, 1, "h");
    munits::Quantity t2 (munits::Time, 1, "d");

    munits::Quantity p = f * t1 / t2;
    EXPECT_EQ(p.getMatrixIndex(), munits::Power);
    EXPECT_EQ(p("kW"), 1/24.);
}

TEST_F(TestQuantityDerivedUnitsConversionDurnigMathOperation, conversion_during_mathop_multiplication){

    munits::Quantity q (munits::VolumetricFlow, 1, "m3 d-1");
    munits::Quantity t (munits::Time, 24, "h");

    munits::Quantity v = q * t;

    EXPECT_EQ(v.getMatrixIndex(), munits::Volume);

    EXPECT_EQ(v("m3"), 1);

}

TEST_F(TestQuantityDerivedUnitsConversionDurnigMathOperation, conversion_during_mathop_division_rato_same_exponents){

    munits::Quantity v1 (munits::VolumetricFlow, 50, "m3 h-1");
    munits::Quantity v2 (munits::VolumetricFlow, 400, "m3 d-1");

    munits::Quantity r = v1 / v2;

    EXPECT_EQ(r.getMatrixIndex(), munits::_Last);

    EXPECT_NEAR((double) r, 3.0, 1e-15);
}
TEST_F(TestQuantityDerivedUnitsConversionDurnigMathOperation, conversion_during_mathop_division_rato_different_exponents_left){

    munits::Quantity v1 (munits::MolarConcentration, 10, "mol l-1");
    munits::Quantity v2 (munits::MolarConcentration, 1, "mol dm-3");

    munits::Quantity r = v1 / v2;

    EXPECT_EQ(r.getMatrixIndex(), munits::_Last);

    EXPECT_NEAR((double) r, 10., 10e-5);
}
TEST_F(TestQuantityDerivedUnitsConversionDurnigMathOperation, conversion_during_mathop_division_rato_different_exponents_right){

    munits::Quantity v1 (munits::MolarConcentration, 10, "mol dm-3");
    munits::Quantity v2 (munits::MolarConcentration, 1, "mol l-1");

    munits::Quantity r = v1 / v2;

    EXPECT_EQ(r.getMatrixIndex(), munits::_Last);

    EXPECT_NEAR((double) r, 10. , 10e-5);
}

TEST_F(TestQuantityDerivedUnitsConversionDurnigMathOperation, conversion_during_mathop_division){

    munits::Quantity v (munits::Volume, 9, "m3");
    munits::Quantity l (munits::Length, 3000, "mm");

    munits::Quantity a = v /l;

    EXPECT_EQ(a.getMatrixIndex(), munits::Area);

    EXPECT_NEAR(a("m2"), 3, 0.00001);
}
TEST_F(TestQuantityDerivedUnitsConversionDurnigMathOperation, conversion_during_mathop_division_right_special){

    munits::Quantity v (munits::Volume, 1, "m3");
    munits::Quantity l (munits::Length, 1, "inc");

    munits::Quantity a = v /l;

    EXPECT_EQ(a.getMatrixIndex(), munits::Area);
    EXPECT_NEAR(a("m2"), 39.37007874015748, 1e-4);
}
TEST_F(TestQuantityDerivedUnitsConversionDurnigMathOperation, conversion_during_mathop_division_left_special){

    munits::Quantity v (munits::Volume, 1, "l");
    munits::Quantity l (munits::Length, 1, "dm");

    munits::Quantity a = v /l;

    EXPECT_EQ(a.getMatrixIndex(), munits::Area);
    double avl = a("dm2");
    EXPECT_NEAR(avl, 1, 1e-4);
}



#endif //SANDBOX_QUANTITY_TEST_DERIVED_MATHOP_HPP
