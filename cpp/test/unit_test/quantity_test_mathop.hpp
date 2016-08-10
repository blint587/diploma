

#ifndef MUSYS_QUANTITY_TEST_MATHOP_HPP
#define MUSYS_QUANTITY_TEST_MATHOP_HPP

#include "gtest/gtest.h"
#include "../../quantity.h"

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
//    a2 = l / (t * *2);
    munits::Quantity a3 = l / t / t;

    EXPECT_EQ(a1.getMatrixIndex(), munits::Acceleration);
//    EXPECT_EQ(a2.getMatrixIndex(), munits::Acceleration);
    EXPECT_EQ(a3.getMatrixIndex(), munits::Acceleration);
}
//TEST_F(test_acceleration_from_l_t){
//l = munits.Length(1, "m")
//t = munits.Time(1, "s")
//a1 = l / (t * t)
//a2 = l / (t ** 2)
//a3 = l / t / t
//
//self.assertIsInstance(a1, munits.Acceleration)
//self.assertIsInstance(a2, munits.Acceleration)
//self.assertIsInstance(a3, munits.Acceleration)
//
//TEST_F(test_acceleration_from_l_t_none_zero){
//l = munits.Length(2.33, "m")
//t = munits.Time(2.33, "s")
//a1 = l / (t * t)
//a2 = l / (t ** 2)
//a3 = l / t / t
//
//EXPECT_NEAR(a1("m s-2"), "0.4229"), delta=1e-2)
//EXPECT_NEAR(a2("m s-2"), "0.4229"), delta=1e-2)
//EXPECT_NEAR(a3("m s-2"), "0.4229"), delta=1e-2)
//
//TEST_F(test_force_from_m_a_zero){
//m = munits.Mass(0, "g")
//a = munits.Acceleration(0, "m s-2")
//f1 = m * a
//self.assertIsInstance(f1, munits.Force)
//EXPECT_EQ(f1("kg m s-2"), "0."))
//
//TEST_F(test_force_from_m_a){
//m = munits.Mass(1, "kg")
//a = munits.Acceleration(1, "m s-2")
//f1 = m * a
//EXPECT_EQ(f1("kg m s-2"), "1"))
//
//TEST_F(test_force_from_m_a_233){
//m = munits.Mass(2.33, "kg")
//a = munits.Acceleration(1, "m s-2")
//f1 = m * a
//EXPECT_EQ(f1("kg m s-2"), "2.33"))
//
//TEST_F(test_volumetricflow_zero){
//v = munits.Volume(0, "m3")
//t = munits.Time(1, "h")
//vf = v / t
//self.assertIsInstance(vf, munits.VolumetricFlow)
//EXPECT_EQ(vf("m3 h-1"), "0."))
//
//TEST_F(test_volumetricflow_){
//l = munits.Length(1, "m")
//v1 = l * l * l
//v2 = l ** 3
//t = munits.Time(1, "h")
//vf1 = v1 / t
//vf2 = v2 / t
//vf3 = l * l * l / t
//self.assertIsInstance(vf1, munits.VolumetricFlow)
//EXPECT_EQ(vf1("m3 h-1"), "1."))
//
//self.assertIsInstance(vf2, munits.VolumetricFlow)
//EXPECT_EQ(vf2("m3 h-1"), "1."))
//
//self.assertIsInstance(vf3, munits.VolumetricFlow)
//EXPECT_EQ(vf3("m3 h-1"), "1."))
//
//TEST_F(test_volumetricflow_233){
//l = munits.Length(2.33, "m")
//v = munits.Volume(12.649, "m3")
//l1 = l * l * l
//t = munits.Time(2.33, "h")
//vf1 = l1 / t
//vf2 = v / t
//self.assertIsInstance(vf1, munits.VolumetricFlow)
//EXPECT_NEAR(vf1("m3 h-1"), "5.4289"), delta=1e-6)
//
//self.assertIsInstance(vf2, munits.VolumetricFlow)
//EXPECT_NEAR(vf2("m3 h-1"), "5.4289"), delta=1e-3)
//
//
//TEST_F(test_molar_concentration_from_n_l_v_zero){
//l = munits.Length(1, "m")
//v = munits.Volume(1, "m3")
//n = munits.AmountOfSubstance(0, "mol")
//mc1 = n / (l * l * l)
//mc2 = n / (l ** 3)
//mc3 = n / l / l / l
//mc4 = n / v
//
//self.assertIsInstance(mc1, munits.MolarConcentration)
//self.assertIsInstance(mc2, munits.MolarConcentration)
//self.assertIsInstance(mc3, munits.MolarConcentration)
//self.assertIsInstance(mc4, munits.MolarConcentration)
//
//EXPECT_EQ(mc1("mol m-3"), "0."))
//EXPECT_EQ(mc2("mol m-3"), "0."))
//EXPECT_EQ(mc3("mol m-3"), "0."))
//EXPECT_EQ(mc4("mol m-3"), "0."))
//
//
//TEST_F(test_molar_concentration_from_n_l_v){
//l = munits.Length(1, "m")
//v = munits.Volume(1, "m3")
//n = munits.AmountOfSubstance(1, "mol")
//mc1 = n / (l * l * l)
//mc2 = n / (l ** 3)
//mc3 = n / l / l / l
//mc4 = n / v
//
//EXPECT_EQ(mc1("mol m-3"), "1."))
//EXPECT_EQ(mc2("mol m-3"), "1."))
//EXPECT_EQ(mc3("mol m-3"), "1."))
//EXPECT_EQ(mc4("mol m-3"), "1."))
//
//
//TEST_F(test_molar_concentration_from_n_l_v_233){
//l = munits.Length(2.33, "m")
//v = munits.Volume(12.649, "m3")
//n = munits.AmountOfSubstance(1, "mol")
//mc1 = n / (l * l * l)
//mc2 = n / (l ** 3)
//mc3 = n / l / l / l
//mc4 = n / v
//
//EXPECT_NEAR(mc1("mol m-3"), "0.0790"), delta=1e-3)
//EXPECT_NEAR(mc2("mol m-3"), "0.0790"), delta=1e-3)
//EXPECT_NEAR(mc3("mol m-3"), "0.0790"), delta=1e-3)
//EXPECT_NEAR(mc4("mol m-3"), "0.0790"), delta=1e-3)
//
//

#endif //MUSYS_QUANTITY_TEST_MATHOP_HPP
