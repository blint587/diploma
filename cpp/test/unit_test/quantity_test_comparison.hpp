#ifndef MUSYS_QUANTITY_TEST_COMPARISON_HPP
#define MUSYS_QUANTITY_TEST_COMPARISON_HPP

#include "gtest/gtest.h"
#include "../../quantity.h"

class TestQuantityBaseUnitComparison: public testing::Test{};

class TestQuantityDerivedUnitComparison: public testing::Test{};

TEST_F(TestQuantityBaseUnitComparison, test_comparing_base_with_base_equal) {
    munits::Quantity m1 (munits::Mass, 1., "g");
    munits::Quantity m2 (munits::Mass, 1., "g");
    EXPECT_TRUE(m1 == m2);
    EXPECT_TRUE(m1 <= m2);
    EXPECT_TRUE(m1 >= m2);
    EXPECT_FALSE(m1 > m2);
    EXPECT_FALSE(m1 < m2);
    EXPECT_FALSE(m1 != m2);
}
TEST_F(TestQuantityBaseUnitComparison, test_comparing_base_with_base_greater){
    munits::Quantity m1 (munits::Mass, 2., "g");
    munits::Quantity m2 (munits::Mass, 1., "g");
    EXPECT_FALSE(m1 == m2);
    EXPECT_FALSE(m1 <= m2);
    EXPECT_TRUE(m1 >= m2);
    EXPECT_TRUE(m1 > m2);
    EXPECT_FALSE(m1 < m2);
    EXPECT_TRUE(m1 != m2);
}
TEST_F(TestQuantityBaseUnitComparison, test_comparing_base_with_base_less) {
    munits::Quantity m1 (munits::Mass, 1., "g");
    munits::Quantity m2 (munits::Mass, 2., "g");
    EXPECT_FALSE(m1 == m2);
    EXPECT_TRUE(m1 <= m2);
    EXPECT_FALSE(m1 >= m2);
    EXPECT_FALSE(m1 > m2);
    EXPECT_TRUE(m1 < m2);
    EXPECT_TRUE(m1 != m2);
}
TEST_F(TestQuantityBaseUnitComparison, test_comparing_none_base_with_base_equal) {
    munits::Quantity l1 (munits::Length, 1000., "mm");
    munits::Quantity l2 (munits::Length, 1., "m");
    EXPECT_TRUE(l1 == l2);
    EXPECT_TRUE(l1 <= l2);
    EXPECT_TRUE(l1 >= l2);
    EXPECT_FALSE(l1 > l2);
    EXPECT_FALSE(l1 < l2);
    EXPECT_FALSE(l1 != l2);
}
TEST_F(TestQuantityBaseUnitComparison, test_comparing_none_base_with_base_greater) {
    munits::Quantity l1 (munits::Length, 10000., "mm");
    munits::Quantity l2 (munits::Length, 1., "m");
    EXPECT_FALSE(l1 == l2);
    EXPECT_FALSE(l1 <= l2);
    EXPECT_TRUE(l1 >= l2);
    EXPECT_TRUE(l1 > l2);
    EXPECT_FALSE(l1 < l2);
    EXPECT_TRUE(l1 != l2);
}
TEST_F(TestQuantityBaseUnitComparison, test_comparing_none_base_with_base_less) {
    munits::Quantity l1 (munits::Length, 100., "mm");
    munits::Quantity l2 (munits::Length, 1., "m");
    EXPECT_FALSE(l1 == l2);
    EXPECT_TRUE(l1 <= l2);
    EXPECT_FALSE(l1 >= l2);
    EXPECT_FALSE(l1 > l2);
    EXPECT_TRUE(l1 < l2);
    EXPECT_TRUE(l1 != l2);
}
TEST_F(TestQuantityBaseUnitComparison, test_comparing_none_base_with_none_base_equal) {
    munits::Quantity m1 (munits::Mass, 100., "dag");
    munits::Quantity m2 (munits::Mass, 1., "kg");
    EXPECT_TRUE(m1 == m2);
    EXPECT_TRUE(m1 <= m2);
    EXPECT_TRUE(m1 >= m2);
    EXPECT_FALSE(m1 > m2);
    EXPECT_FALSE(m1 < m2);
    EXPECT_FALSE(m1 != m2);
}
TEST_F(TestQuantityBaseUnitComparison, test_comparing_none_base_with_none_base_less) {
    munits::Quantity m1 (munits::Mass, 10., "dag");
    munits::Quantity m2 (munits::Mass, 1., "kg");
    EXPECT_FALSE(m1 == m2);
    EXPECT_TRUE(m1 <= m2);
    EXPECT_FALSE(m1 >= m2);
    EXPECT_FALSE(m1 > m2);
    EXPECT_TRUE(m1 < m2);
    EXPECT_TRUE(m1 != m2);
}
TEST_F(TestQuantityBaseUnitComparison, test_comparing_none_base_with_none_base_greater) {
    munits::Quantity m1 (munits::Mass, 1000., "dag");
    munits::Quantity m2 (munits::Mass, 1., "kg");
    EXPECT_FALSE(m1 == m2);
    EXPECT_FALSE(m1 <= m2);
    EXPECT_TRUE(m1 >= m2);
    EXPECT_TRUE(m1 > m2);
    EXPECT_FALSE(m1 < m2);
    EXPECT_TRUE(m1 != m2);
}
TEST_F(TestQuantityBaseUnitComparison, test_comparing_time_none_base_with_none_base_equal) {
    munits::Quantity t1 (munits::Time, 1., "d");
    munits::Quantity t2  (munits::Time , 24., "h");
    EXPECT_TRUE(t1 == t2);
    EXPECT_TRUE(t1 <= t2);
    EXPECT_TRUE(t1 >= t2);
    EXPECT_FALSE(t1 > t2);
    EXPECT_FALSE(t1 < t2);
    EXPECT_FALSE(t1 != t2);
}
TEST_F(TestQuantityBaseUnitComparison, test_comparing_time_none_base_with_none_base_less) {
    munits::Quantity t1 (munits::Time, 1., "d");
    munits::Quantity t2 (munits::Time, 25., "h");
    EXPECT_FALSE(t1 == t2);
    EXPECT_TRUE(t1 <= t2);
    EXPECT_FALSE(t1 >= t2);
    EXPECT_FALSE(t1 > t2);
    EXPECT_TRUE(t1 < t2);
    EXPECT_TRUE(t1 != t2);
}
TEST_F(TestQuantityBaseUnitComparison, test_comparing_time_none_base_with_none_base_greater) {
    munits::Quantity t1 (munits::Time, 1., "d");
    munits::Quantity t2 (munits::Time, 23., "h");
    EXPECT_FALSE(t1 == t2);
    EXPECT_FALSE(t1 <= t2);
    EXPECT_TRUE(t1 >= t2);
    EXPECT_TRUE(t1 > t2);
    EXPECT_FALSE(t1 < t2);
    EXPECT_TRUE(t1 != t2);
}
TEST_F(TestQuantityBaseUnitComparison, test_comparing_base_with_base_temperature_equal) {
    munits::Quantity t1 (munits::Temperature, 273.15, "K");
    munits::Quantity t2 (munits::Temperature, 273.15, "K");
    EXPECT_TRUE(t1 == t2);
    EXPECT_TRUE(t1 <= t2);
    EXPECT_TRUE(t1 >= t2);
    EXPECT_FALSE(t1 < t2);
    EXPECT_FALSE(t1 > t2);
    EXPECT_FALSE(t1 != t2);
}
TEST_F(TestQuantityBaseUnitComparison, test_comparing_base_with_base_temperature_less) {
    munits::Quantity t1 (munits::Temperature, 0., "K");
    munits::Quantity t2 (munits::Temperature, 273.15, "K");
    EXPECT_FALSE(t1 == t2);
    EXPECT_TRUE(t1 <= t2);
    EXPECT_FALSE(t1 >= t2);
    EXPECT_TRUE(t1 < t2);
    EXPECT_FALSE(t1 > t2);
    EXPECT_TRUE(t1 != t2);
}
TEST_F(TestQuantityBaseUnitComparison, test_comparing_base_with_base_temperature_greater) {
    munits::Quantity t1 (munits::Temperature, 273.15, "K");
    munits::Quantity t2 (munits::Temperature, 0., "K");
    EXPECT_FALSE(t1 == t2);
    EXPECT_FALSE(t1 <= t2);
    EXPECT_TRUE(t1 >= t2);
    EXPECT_FALSE(t1 < t2);
    EXPECT_TRUE(t1 > t2);
    EXPECT_TRUE(t1 != t2);
}
//

//# Acceleration
//
TEST_F(TestQuantityDerivedUnitComparison, test_comparing_derived_with_derived_acceleration_equal) {
    munits::Quantity a1 (munits::Acceleration, 1, "m s-2");
    munits::Quantity a2 (munits::Acceleration, 1, "m s-2");
    EXPECT_TRUE(a1 == a2);
    EXPECT_TRUE(a1 <= a2);
    EXPECT_TRUE(a1 >= a2);
    EXPECT_FALSE(a1 > a2);
    EXPECT_FALSE(a1 < a2);
    EXPECT_FALSE(a1 != a2);
}
TEST_F(TestQuantityDerivedUnitComparison, test_comparing_derived_with_derived_acceleration_greater) {
    munits::Quantity a1 (munits::Acceleration, 2, "m s-2");
    munits::Quantity a2 (munits::Acceleration, 1, "m s-2");
    EXPECT_FALSE(a1 == a2);
    EXPECT_FALSE(a1 <= a2);
    EXPECT_TRUE(a1 >= a2);
    EXPECT_TRUE(a1 > a2);
    EXPECT_FALSE(a1 < a2);
    EXPECT_TRUE(a1 != a2);
}
TEST_F(TestQuantityDerivedUnitComparison, test_comparing_derived_with_derived_acceleration_less) {
    munits::Quantity a1 (munits::Acceleration, 1, "m s-2");
    munits::Quantity a2 (munits::Acceleration, 2, "m s-2");
    EXPECT_FALSE(a1 == a2);
    EXPECT_TRUE(a1 <= a2);
    EXPECT_FALSE(a1 >= a2);
    EXPECT_FALSE(a1 > a2);
    EXPECT_TRUE(a1 < a2);
    EXPECT_TRUE(a1 != a2);
}
//# FORCE

TEST_F(TestQuantityDerivedUnitComparison, test_comparing_derived_with_derived_force_equal) {
    munits::Quantity f1 (munits::Force, 1, "kg m s-2");
    munits::Quantity f2 (munits::Force, 1, "kg m s-2");
    EXPECT_TRUE(f1 == f2);
    EXPECT_TRUE(f1 <= f2);
    EXPECT_TRUE(f1 >= f2);
    EXPECT_FALSE(f1 > f2);
    EXPECT_FALSE(f1 < f2);
    EXPECT_FALSE(f1 != f2);
}
TEST_F(TestQuantityDerivedUnitComparison, test_comparing_derived_with_derived_force_greater) {
    munits::Quantity f1 (munits::Force, 2, "kg m s-2");
    munits::Quantity f2 (munits::Force, 1, "kg m s-2");
    EXPECT_FALSE(f1 == f2);
    EXPECT_FALSE(f1 <= f2);
    EXPECT_TRUE(f1 >= f2);
    EXPECT_TRUE(f1 > f2);
    EXPECT_FALSE(f1 < f2);
    EXPECT_TRUE(f1 != f2);
}
TEST_F(TestQuantityDerivedUnitComparison, test_comparing_derived_with_derived_force_less) {
    munits::Quantity f1 (munits::Force, 1, "kg m s-2");
    munits::Quantity f2 (munits::Force, 2, "kg m s-2");
    EXPECT_FALSE(f1 == f2);
    EXPECT_TRUE(f1 <= f2);
    EXPECT_FALSE(f1 >= f2);
    EXPECT_FALSE(f1 > f2);
    EXPECT_TRUE(f1 < f2);
    EXPECT_TRUE(f1 != f2);
}
//# MOLARCCONCENTRATION

TEST_F(TestQuantityDerivedUnitComparison, test_comparing_derived_with_derived_molar_concentration_equal) {
    munits::Quantity c1 (munits::MolarConcentration, 1, "mol m-3");
    munits::Quantity c2 (munits::MolarConcentration, 1, "mol m-3");
    EXPECT_TRUE(c1 == c2);
    EXPECT_TRUE(c1 <= c2);
    EXPECT_TRUE(c1 >= c2);
    EXPECT_FALSE(c1 > c2);
    EXPECT_FALSE(c1 < c2);
    EXPECT_FALSE(c1 != c2);
}
TEST_F(TestQuantityDerivedUnitComparison, test_comparing_derived_with_derived_molar_concentration_greater) {
    munits::Quantity c1 (munits::MolarConcentration, 2, "mol m-3");
    munits::Quantity c2 (munits::MolarConcentration, 1, "mol m-3");
    EXPECT_FALSE(c1 == c2);
    EXPECT_FALSE(c1 <= c2);
    EXPECT_TRUE(c1 >= c2);
    EXPECT_TRUE(c1 > c2);
    EXPECT_FALSE(c1 < c2);
    EXPECT_TRUE(c1 != c2);
}
TEST_F(TestQuantityDerivedUnitComparison, test_comparing_derived_with_derived_molar_concentration_less) {
    munits::Quantity c1 (munits::MolarConcentration, 1, "mol m-3");
    munits::Quantity c2 (munits::MolarConcentration, 2, "mol m-3");
    EXPECT_FALSE(c1 == c2);
    EXPECT_TRUE(c1 <= c2);
    EXPECT_FALSE(c1 >= c2);
    EXPECT_FALSE(c1 > c2);
    EXPECT_TRUE(c1 < c2);
    EXPECT_TRUE(c1 != c2);
}

#endif //MUSYS_QUANTITY_TEST_COMPARISON_HPP
