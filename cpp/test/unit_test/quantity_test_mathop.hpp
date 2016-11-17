#ifndef MUSYS_QUANTITY_TEST_MATHOP_HPP
#define MUSYS_QUANTITY_TEST_MATHOP_HPP

#include "gtest/gtest.h"
#include "../../src/quantity.h"

class TestQuantityBaseUnitMathOperation : public testing::Test{};

class TestQuantityDerivedUnitsMathOperation : public testing::Test{};

TEST_F(TestQuantityBaseUnitMathOperation, test_adding_mass_to_mass) {
    munits::Quantity m1 (munits::Mass, 1000., "g");
    munits::Quantity m2 (munits::Mass, 1., "kg");
    munits::Quantity m3 = m1 + m2;

    EXPECT_EQ(m3("g"), 2000.);
}

TEST_F(TestQuantityDerivedUnitsMathOperation, test_acceleration_from_l_t_zero) {
    munits::Quantity l (munits::Length, 0, "m");
    munits::Quantity t (munits::Time, 1, "s");
    munits::Quantity a1 = l / (t * t);
    munits::Quantity a2 = l /  pow(t, 2);
    munits::Quantity a3 = l / t / t;

    EXPECT_EQ(a1.getMatrixIndex(), munits::Acceleration);
    EXPECT_EQ(a2.getMatrixIndex(), munits::Acceleration);
    EXPECT_EQ(a3.getMatrixIndex(), munits::Acceleration);

    EXPECT_EQ(a1("m s-2"), 0.);
    EXPECT_EQ(a2("m s-2"), 0.);
    EXPECT_EQ(a3("m s-2"), 0.);
}
TEST_F(TestQuantityDerivedUnitsMathOperation, test_acceleration_from_l_t) {
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity t (munits::Time, 1, "s");

    munits::Quantity a1 = l / (t * t);
    munits::Quantity a2 = l / pow(t, 2);
    munits::Quantity a3 = l / t / t;

    EXPECT_EQ(a1.getMatrixIndex(), munits::Acceleration);
    EXPECT_EQ(a2.getMatrixIndex(), munits::Acceleration);
    EXPECT_EQ(a3.getMatrixIndex(), munits::Acceleration);

    EXPECT_EQ(a1("m s-2"), 1.);
    EXPECT_EQ(a2("m s-2"), 1.);
    EXPECT_EQ(a3("m s-2"), 1.);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_acceleration_from_l_t_none_zero){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity t (munits::Time, 2.33, "s");
    munits::Quantity a1 = l / (t * t);
    munits::Quantity a2 = l / pow(t, 2);
    munits::Quantity a3 = l / t / t;

    EXPECT_EQ(a1.getMatrixIndex(), munits::Acceleration);
    EXPECT_EQ(a2.getMatrixIndex(), munits::Acceleration);
    EXPECT_EQ(a3.getMatrixIndex(), munits::Acceleration);

    EXPECT_NEAR(a1("m s-2"), 0.4229, 1e-2);
    EXPECT_NEAR(a2("m s-2"), 0.4229, 1e-2);
    EXPECT_NEAR(a3("m s-2"), 0.4229, 1e-2);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_force_from_m_a_zero){
    munits::Quantity m (munits::Mass, 0, "g");
    munits::Quantity a (munits::Acceleration, 0, "m s-2");
    munits::Quantity f1 = m * a;
    EXPECT_EQ(f1.getMatrixIndex(), munits::Force);
    EXPECT_EQ(f1("kg m s-2"), 0.);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_force_from_m_a){
    munits::Quantity m (munits::Mass, 1, "kg");
    munits::Quantity a (munits::Acceleration, 1, "m s-2");
    munits::Quantity f1 = m * a;
    EXPECT_EQ(f1.getMatrixIndex(), munits::Force);
    EXPECT_EQ(f1("kg m s-2"), 1);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_force_from_m_a_233){
    munits::Quantity m (munits::Mass, 2.33, "kg");
    munits::Quantity a (munits::Acceleration, 1, "m s-2");
    munits::Quantity f1 = m * a;
    EXPECT_EQ(f1.getMatrixIndex(), munits::Force);
    EXPECT_EQ(f1("kg m s-2"), 2.33);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_volumetricflow_zero){
    munits::Quantity v (munits::Volume, 0, "m3");
    munits::Quantity t (munits::Time, 1, "h");
    munits::Quantity vf = v / t;
    EXPECT_EQ(vf.getMatrixIndex(), munits::VolumetricFlow);
    EXPECT_EQ(vf("m3 h-1"), 0.);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_volumetricflow_){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity v1 = l * l * l;
    munits::Quantity v2 = munits::pow(l, 3);
    munits::Quantity t (munits::Time, 1, "h");

    munits::Quantity vf1 = v1 / t;
    munits::Quantity vf2 = v2 / t;
    munits::Quantity vf3 = l * l * l / t;

    EXPECT_EQ(vf1.getMatrixIndex(), munits::VolumetricFlow);
    EXPECT_EQ(vf2.getMatrixIndex(), munits::VolumetricFlow);
    EXPECT_EQ(vf3.getMatrixIndex(), munits::VolumetricFlow);

    EXPECT_EQ(vf1("m3 h-1"),1.);
    EXPECT_EQ(vf2("m3 h-1"),1.);
    EXPECT_EQ(vf3("m3 h-1"),1.);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_volumetricflow_233){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity v (munits::Volume,12.649, "m3");
    munits::Quantity l1 = l * l * l;
    munits::Quantity t (munits::Time, 2.33, "h");
    munits::Quantity vf1 = l1 / t;
    munits::Quantity vf2 = v / t;

    EXPECT_EQ(vf1.getMatrixIndex(), munits::VolumetricFlow);

    EXPECT_NEAR(vf1("m3 h-1"), 5.4289, 1e-3);

    EXPECT_EQ(vf2.getMatrixIndex(), munits::VolumetricFlow);
    EXPECT_NEAR(vf2("m3 h-1"), 5.4289, 1e-3);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v_zero){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity v (munits::Volume,  1, "m3");
    munits::Quantity n (munits::AmountOfSubstance, 0, "mol");
    munits::Quantity mc1 = n / (l * l * l);
    munits::Quantity mc2 = n / munits::pow(l, 3);
    munits::Quantity mc3 = n / l / l / l;
    munits::Quantity mc4 = n / v;

    EXPECT_EQ(mc1.getMatrixIndex(), munits::MolarConcentration);
    EXPECT_EQ(mc2.getMatrixIndex(), munits::MolarConcentration);
    EXPECT_EQ(mc3.getMatrixIndex(), munits::MolarConcentration);
    EXPECT_EQ(mc4.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc1("mol m-3"), 0.);
    EXPECT_EQ(mc2("mol m-3"), 0.);
    EXPECT_EQ(mc3("mol m-3"), 0.);
    EXPECT_EQ(mc4("mol m-3"), 0.);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity v (munits::Volume, 1, "m3");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc1 = n / (l * l * l);
    munits::Quantity mc2 = n / munits::pow(l,3);
    munits::Quantity mc3 = n / l / l / l;
    munits::Quantity mc4 = n / v;

    EXPECT_EQ(mc1.getMatrixIndex(), munits::MolarConcentration);
    EXPECT_EQ(mc2.getMatrixIndex(), munits::MolarConcentration);
    EXPECT_EQ(mc3.getMatrixIndex(), munits::MolarConcentration);
    EXPECT_EQ(mc4.getMatrixIndex(), munits::MolarConcentration);


    EXPECT_EQ(mc1("mol m-3"), 1.);
    EXPECT_EQ(mc2("mol m-3"), 1.);
    EXPECT_EQ(mc3("mol m-3"), 1.);
    EXPECT_EQ(mc4("mol m-3"), 1.);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v_233){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity v (munits::Volume, 12.649, "m3");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc1 = n / (l * l * l);
    munits::Quantity mc2 = n / munits::pow(l, 3);
    munits::Quantity mc3 = n / l / l / l;
    munits::Quantity mc4 = n / v;

    EXPECT_EQ(mc1.getMatrixIndex(), munits::MolarConcentration);
    EXPECT_EQ(mc2.getMatrixIndex(), munits::MolarConcentration);
    EXPECT_EQ(mc3.getMatrixIndex(), munits::MolarConcentration);
    EXPECT_EQ(mc4.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_NEAR(mc1("mol m-3"), 0.0790, 1e-3);
    EXPECT_NEAR(mc2("mol m-3"), 0.0790, 1e-3);
    EXPECT_NEAR(mc3("mol m-3"), 0.0790, 1e-3);
    EXPECT_NEAR(mc4("mol m-3"), 0.0790, 1e-3);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_conversion_during_mathop_multiplication){

    munits::Quantity q (munits::VolumetricFlow, 1, "m3 d-1");
    munits::Quantity t (munits::Time, 24, "h");

    munits::Quantity v = q * t;

    EXPECT_EQ(v.getMatrixIndex(), munits::Volume);

    EXPECT_EQ(v("m3"), 1);


}

TEST_F(TestQuantityBaseUnitMathOperation, test_conversion_during_mathop_division){

    munits::Quantity v (munits::Volume, 9, "m3");
    munits::Quantity l (munits::Length, 3000, "mm");

    munits::Quantity a = v /l;

    EXPECT_EQ(a.getMatrixIndex(), munits::Area);

    EXPECT_EQ(a("m2"), 3);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_conversion_during_mathop_division_resultin_rato){

    munits::Quantity v1 (munits::VolumetricFlow, 50, "m3 h-1");
    munits::Quantity v2 (munits::VolumetricFlow, 400, "m3 d-1");

    munits::Quantity r = v1 / v2;

    EXPECT_EQ(r.getMatrixIndex(), munits::_Last);

    EXPECT_NEAR((double) r, 3.0, 1e-15);
}



#endif //MUSYS_QUANTITY_TEST_MATHOP_HPP
