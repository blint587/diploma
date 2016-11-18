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

TEST_F(TestQuantityDerivedUnitsMathOperation, test_acceleration_from_l_t_zero_1) {
    munits::Quantity l (munits::Length, 0, "m");
    munits::Quantity t (munits::Time, 1, "s");
    munits::Quantity a1 = l / (t * t);

    EXPECT_EQ(a1.getMatrixIndex(), munits::Acceleration);

    EXPECT_EQ(a1("m s-2"), 0.);

}TEST_F(TestQuantityDerivedUnitsMathOperation, test_acceleration_from_l_t_zero_2) {
    munits::Quantity l (munits::Length, 0, "m");
    munits::Quantity t (munits::Time, 1, "s");
    munits::Quantity a2 = l /  pow(t, 2);

    EXPECT_EQ(a2.getMatrixIndex(), munits::Acceleration);

    EXPECT_EQ(a2("m s-2"), 0.);

}
TEST_F(TestQuantityDerivedUnitsMathOperation, test_acceleration_from_l_t_zero_3) {
    munits::Quantity l (munits::Length, 0, "m");
    munits::Quantity t (munits::Time, 1, "s");
    munits::Quantity a3 = l / t / t;

    EXPECT_EQ(a3.getMatrixIndex(), munits::Acceleration);

    EXPECT_EQ(a3("m s-2"), 0.);
}
TEST_F(TestQuantityDerivedUnitsMathOperation, test_acceleration_from_l_t_1) {
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity t (munits::Time, 1, "s");

    munits::Quantity a1 = l / (t * t);

    EXPECT_EQ(a1.getMatrixIndex(), munits::Acceleration);

    EXPECT_EQ(a1("m s-2"), 1.);
}
TEST_F(TestQuantityDerivedUnitsMathOperation, test_acceleration_from_l_t_2) {
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity t (munits::Time, 1, "s");

    munits::Quantity a2 = l / pow(t, 2);

    EXPECT_EQ(a2.getMatrixIndex(), munits::Acceleration);

    EXPECT_EQ(a2("m s-2"), 1.);
}
TEST_F(TestQuantityDerivedUnitsMathOperation, test_acceleration_from_l_t_3) {
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity t (munits::Time, 1, "s");

    munits::Quantity a3 = l / t / t;

    EXPECT_EQ(a3.getMatrixIndex(), munits::Acceleration);

    EXPECT_EQ(a3("m s-2"), 1.);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_acceleration_from_l_t_none_zero_1){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity t (munits::Time, 2.33, "s");
    munits::Quantity a1 = l / (t * t);

    EXPECT_EQ(a1.getMatrixIndex(), munits::Acceleration);

    EXPECT_NEAR(a1("m s-2"), 0.4229, 1e-2);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_acceleration_from_l_t_none_zero_2){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity t (munits::Time, 2.33, "s");
    munits::Quantity a2 = l / pow(t, 2);

    EXPECT_EQ(a2.getMatrixIndex(), munits::Acceleration);

    EXPECT_NEAR(a2("m s-2"), 0.4229, 1e-2);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_acceleration_from_l_t_none_zero_3){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity t (munits::Time, 2.33, "s");
    munits::Quantity a3 = l / t / t;

    EXPECT_EQ(a3.getMatrixIndex(), munits::Acceleration);

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

TEST_F(TestQuantityBaseUnitMathOperation, test_volumetricflow_one_1){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity v1 = l * l * l;
    munits::Quantity t (munits::Time, 1, "h");

    munits::Quantity vf1 = v1 / t;

    EXPECT_EQ(vf1.getMatrixIndex(), munits::VolumetricFlow);

    EXPECT_EQ(vf1("m3 h-1"),1.);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_volumetricflow_one_2){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity v2 = munits::pow(l, 3);
    munits::Quantity t (munits::Time, 1, "h");

    munits::Quantity vf2 = v2 / t;

    EXPECT_EQ(vf2.getMatrixIndex(), munits::VolumetricFlow);

    EXPECT_EQ(vf2("m3 h-1"),1.);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_volumetricflow_one_3){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity t (munits::Time, 1, "h");

    munits::Quantity vf3 = l * l * l / t;

    EXPECT_EQ(vf3.getMatrixIndex(), munits::VolumetricFlow);

    EXPECT_EQ(vf3("m3 h-1"),1.);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_volumetricflow_233_1){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity l1 = l * l * l;
    munits::Quantity t (munits::Time, 2.33, "h");
    munits::Quantity vf1 = l1 / t;

    EXPECT_EQ(vf1.getMatrixIndex(), munits::VolumetricFlow);

    EXPECT_NEAR(vf1("m3 h-1"), 5.4289, 1e-3);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_volumetricflow_233_2){
    munits::Quantity v (munits::Volume,12.649, "m3");
    munits::Quantity t (munits::Time, 2.33, "h");
    munits::Quantity vf2 = v / t;

    EXPECT_EQ(vf2.getMatrixIndex(), munits::VolumetricFlow);
    EXPECT_NEAR(vf2("m3 h-1"), 5.4289, 1e-3);
}


TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v_zero_1){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity n (munits::AmountOfSubstance, 0, "mol");
    munits::Quantity mc1 = n / (l * l * l);

    EXPECT_EQ(mc1.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc1("mol m-3"), 0.);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v_zero_2){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity n (munits::AmountOfSubstance, 0, "mol");
    munits::Quantity mc2 = n / munits::pow(l, 3);

    EXPECT_EQ(mc2.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc2("mol m-3"), 0.);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v_zero_3){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity n (munits::AmountOfSubstance, 0, "mol");
    munits::Quantity mc3 = n / l / l / l;

    EXPECT_EQ(mc3.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc3("mol m-3"), 0.);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v_zero_4){
    munits::Quantity v (munits::Volume,  1, "m3");
    munits::Quantity n (munits::AmountOfSubstance, 0, "mol");
    munits::Quantity mc4 = n / v;

    EXPECT_EQ(mc4.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc4("mol m-3"), 0.);
}


TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v_1){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc1 = n / (l * l * l);

    EXPECT_EQ(mc1.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc1("mol m-3"), 1.);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v_2){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc2 = n / munits::pow(l,3);

    EXPECT_EQ(mc2.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc2("mol m-3"), 1.);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v_3){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc3 = n / l / l / l;

    EXPECT_EQ(mc3.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc3("mol m-3"), 1.);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v_4){
    munits::Quantity v (munits::Volume, 1, "m3");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc4 = n / v;

    EXPECT_EQ(mc4.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc4("mol m-3"), 1.);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v_233_1){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc1 = n / (l * l * l);

    EXPECT_EQ(mc1.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_NEAR(mc1("mol m-3"), 0.0790, 1e-3);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v_233_2){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc2 = n / munits::pow(l, 3);

    EXPECT_EQ(mc2.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_NEAR(mc2("mol m-3"), 0.0790, 1e-3);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v_233_3){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc3 = n / l / l / l;

    EXPECT_EQ(mc3.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_NEAR(mc3("mol m-3"), 0.0790, 1e-3);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_molar_concentration_from_n_l_v_233_4){
    munits::Quantity v (munits::Volume, 12.649, "m3");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc4 = n / v;

    EXPECT_EQ(mc4.getMatrixIndex(), munits::MolarConcentration);

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

TEST_F(TestQuantityBaseUnitMathOperation, test_conversion_during_mathop_division_right_special){

    munits::Quantity v (munits::Volume, 1, "m3");
    munits::Quantity l (munits::Length, 1, "inc");

    munits::Quantity a = v /l;

    EXPECT_EQ(a.getMatrixIndex(), munits::Area);
    EXPECT_NEAR(a("m2"), 39.37007874015748, 1e-4);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_conversion_during_mathop_division_left_special){

    munits::Quantity v (munits::Volume, 1, "l");
    munits::Quantity l (munits::Length, 1, "dm");

    munits::Quantity a = v /l;

    EXPECT_EQ(a.getMatrixIndex(), munits::Area);
    double avl = a("dm2");
    EXPECT_NEAR(avl, 1, 1e-4);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_conversion_during_mathop_division_rato_same_exponents){

    munits::Quantity v1 (munits::VolumetricFlow, 50, "m3 h-1");
    munits::Quantity v2 (munits::VolumetricFlow, 400, "m3 d-1");

    munits::Quantity r = v1 / v2;

    EXPECT_EQ(r.getMatrixIndex(), munits::_Last);

    EXPECT_NEAR((double) r, 3.0, 1e-15);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_conversion_during_mathop_division_rato_different_exponents_left){

    munits::Quantity v1 (munits::MolarConcentration, 10, "mol l-1");
    munits::Quantity v2 (munits::MolarConcentration, 1, "mol dm-3");

    munits::Quantity r = v1 / v2;

    EXPECT_EQ(r.getMatrixIndex(), munits::_Last);

    EXPECT_NEAR((double) r, 10., 10e-5);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_conversion_during_mathop_division_rato_different_exponents_right){

    munits::Quantity v1 (munits::MolarConcentration, 10, "mol dm-3");
    munits::Quantity v2 (munits::MolarConcentration, 1, "mol l-1");

    munits::Quantity r = v1 / v2;

    EXPECT_EQ(r.getMatrixIndex(), munits::_Last);

    EXPECT_NEAR((double) r, 10. , 10e-5);
}



TEST_F(TestQuantityBaseUnitMathOperation, test_multiplication_with_numeric_type_from_right){
    munits::Quantity m (munits::Mass, 1, "kg");
    auto r = m * 2;

    EXPECT_EQ(r.getMatrixIndex(), munits::Mass);

    EXPECT_EQ(r("kg"), 2.);
}
TEST_F(TestQuantityBaseUnitMathOperation, test_multiplication_with_numeric_type_from_left){
    munits::Quantity m (munits::Mass, 1, "kg");
    auto r = 2 * m;

    EXPECT_EQ(r.getMatrixIndex(), munits::Mass);

    EXPECT_EQ(r("kg"), 2.);
}

TEST_F(TestQuantityBaseUnitMathOperation, test_division_with_numeric_type_from_right){
    munits::Quantity m (munits::Mass, 1, "kg");
    auto r = m / 2.;

    EXPECT_EQ(r.getMatrixIndex(), munits::Mass);

    EXPECT_EQ(r("kg"), .5);
}


#endif //MUSYS_QUANTITY_TEST_MATHOP_HPP
