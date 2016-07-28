#ifndef MUSYS_QUANTITY_TEST_COMPARISON_HPP
#define MUSYS_QUANTITY_TEST_COMPARISON_HPP

#include "gtest/gtest.h"
#include "../../quantity.h"

class TestQuantityBaseUnitComparison: public testing::Test{};

//TEST_F(test_comparing_base_with_base_equal){
//m1 = munits.Mass(1., "g")
//m2 = munits.Mass(1., "g")
//self.assertTrue(m1 == m2)
//self.assertTrue(m1 <= m2)
//self.assertTrue(m1 >= m2)
//self.assertFalse(m1 > m2)
//self.assertFalse(m1 < m2)
//self.assertFalse(m1 != m2)
//
//TEST_F(test_comparing_base_with_base_greater){
//m1 = munits.Mass(2., "g")
//m2 = munits.Mass(1., "g")
//self.assertFalse(m1 == m2)
//self.assertFalse(m1 <= m2)
//self.assertTrue(m1 >= m2)
//self.assertTrue(m1 > m2)
//self.assertFalse(m1 < m2)
//self.assertTrue(m1 != m2)
//
//TEST_F(test_comparing_base_with_base_less){
//m1 = munits.Mass(1., "g")
//m2 = munits.Mass(2., "g")
//self.assertFalse(m1 == m2)
//self.assertTrue(m1 <= m2)
//self.assertFalse(m1 >= m2)
//self.assertFalse(m1 > m2)
//self.assertTrue(m1 < m2)
//self.assertTrue(m1 != m2)
//
//TEST_F(test_comparing_none_base_with_base_equal){
//l1 = munits.Length(1000., "mm")
//l2 = munits.Length(1., "m")
//self.assertTrue(l1 == l2)
//self.assertTrue(l1 <= l2)
//self.assertTrue(l1 >= l2)
//self.assertFalse(l1 > l2)
//self.assertFalse(l1 < l2)
//self.assertFalse(l1 != l2)
//
//TEST_F(test_comparing_none_base_with_base_greater){
//l1 = munits.Length(10000., "mm")
//l2 = munits.Length(1., "m")
//self.assertFalse(l1 == l2)
//self.assertFalse(l1 <= l2)
//self.assertTrue(l1 >= l2)
//self.assertTrue(l1 > l2)
//self.assertFalse(l1 < l2)
//self.assertTrue(l1 != l2)
//
//TEST_F(test_comparing_none_base_with_base_less){
//l1 = munits.Length(100., "mm")
//l2 = munits.Length(1., "m")
//self.assertFalse(l1 == l2)
//self.assertTrue(l1 <= l2)
//self.assertFalse(l1 >= l2)
//self.assertFalse(l1 > l2)
//self.assertTrue(l1 < l2)
//self.assertTrue(l1 != l2)
//
//TEST_F(test_comparing_none_base_with_none_base_equal){
//m1 = munits.Mass(100., "dag")
//m2 = munits.Mass(1., "kg")
//self.assertTrue(m1 == m2)
//self.assertTrue(m1 <= m2)
//self.assertTrue(m1 >= m2)
//self.assertFalse(m1 > m2)
//self.assertFalse(m1 < m2)
//self.assertFalse(m1 != m2)
//
//TEST_F(test_comparing_none_base_with_none_base_less){
//m1 = munits.Mass(10., "dag")
//m2 = munits.Mass(1., "kg")
//self.assertFalse(m1 == m2)
//self.assertTrue(m1 <= m2)
//self.assertFalse(m1 >= m2)
//self.assertFalse(m1 > m2)
//self.assertTrue(m1 < m2)
//self.assertTrue(m1 != m2)
//
//TEST_F(test_comparing_none_base_with_none_base_greater){
//m1 = munits.Mass(1000., "dag")
//m2 = munits.Mass(1., "kg")
//self.assertFalse(m1 == m2)
//self.assertFalse(m1 <= m2)
//self.assertTrue(m1 >= m2)
//self.assertTrue(m1 > m2)
//self.assertFalse(m1 < m2)
//self.assertTrue(m1 != m2)
//
//# TIME
//
//TEST_F(test_comparing_time_none_base_with_none_base_equal){
//t1 = munits.Time(1., "d")
//t2 = munits.Time(24., "h")
//self.assertTrue(t1 == t2)
//self.assertTrue(t1 <= t2)
//self.assertTrue(t1 >= t2)
//self.assertFalse(t1 > t2)
//self.assertFalse(t1 < t2)
//self.assertFalse(t1 != t2)
//
//TEST_F(test_comparing_time_none_base_with_none_base_less){
//t1 = munits.Time(1., "d")
//t2 = munits.Time(25., "h")
//self.assertFalse(t1 == t2)
//self.assertTrue(t1 <= t2)
//self.assertFalse(t1 >= t2)
//self.assertFalse(t1 > t2)
//self.assertTrue(t1 < t2)
//self.assertTrue(t1 != t2)
//
//TEST_F(test_comparing_time_none_base_with_none_base_greater){
//t1 = munits.Time(1., "d")
//t2 = munits.Time(23., "h")
//self.assertFalse(t1 == t2)
//self.assertFalse(t1 <= t2)
//self.assertTrue(t1 >= t2)
//self.assertTrue(t1 > t2)
//self.assertFalse(t1 < t2)
//self.assertTrue(t1 != t2)
//
//TEST_F(test_comparing_base_with_base_temperature_equal){
//t1 = munits.Temperature(273.15, "K")
//t2 = munits.Temperature(273.15, "K")
//self.assertTrue(t1 == t2)
//self.assertTrue(t1 <= t2)
//self.assertTrue(t1 >= t2)
//self.assertFalse(t1 < t2)
//self.assertFalse(t1 > t2)
//self.assertFalse(t1 != t2)
//
//TEST_F(test_comparing_base_with_base_temperature_less){
//t1 = munits.Temperature(0., "K")
//t2 = munits.Temperature(273.15, "K")
//self.assertFalse(t1 == t2)
//self.assertTrue(t1 <= t2)
//self.assertFalse(t1 >= t2)
//self.assertTrue(t1 < t2)
//self.assertFalse(t1 > t2)
//self.assertTrue(t1 != t2)
//
//TEST_F(test_comparing_base_with_base_temperature_greater){
//t1 = munits.Temperature(273.15, "K")
//t2 = munits.Temperature(0., "K")
//self.assertFalse(t1 == t2)
//self.assertFalse(t1 <= t2)
//self.assertTrue(t1 >= t2)
//self.assertFalse(t1 < t2)
//self.assertTrue(t1 > t2)
//self.assertTrue(t1 != t2)
//
//
//class TestQuantityDerivedUnitComparison(unittest.TestCase):
//# Acceleration
//
//TEST_F(test_comparing_derived_with_derived_acceleration_equal){
//a1 = munits.Acceleration(1, "m s-2")
//a2 = munits.Acceleration(1, "m s-2")
//
//self.assertTrue(a1 == a2)
//self.assertTrue(a1 <= a2)
//self.assertTrue(a1 >= a2)
//self.assertFalse(a1 > a2)
//self.assertFalse(a1 < a2)
//self.assertFalse(a1 != a2)
//
//TEST_F(test_comparing_derived_with_derived_acceleration_greater){
//a1 = munits.Acceleration(2, "m s-2")
//a2 = munits.Acceleration(1, "m s-2")
//
//self.assertFalse(a1 == a2)
//self.assertFalse(a1 <= a2)
//self.assertTrue(a1 >= a2)
//self.assertTrue(a1 > a2)
//self.assertFalse(a1 < a2)
//self.assertTrue(a1 != a2)
//
//TEST_F(test_comparing_derived_with_derived_acceleration_less){
//a1 = munits.Acceleration(1, "m s-2")
//a2 = munits.Acceleration(2, "m s-2")
//
//self.assertFalse(a1 == a2)
//self.assertTrue(a1 <= a2)
//self.assertFalse(a1 >= a2)
//self.assertFalse(a1 > a2)
//self.assertTrue(a1 < a2)
//self.assertTrue(a1 != a2)
//
//# FORCE
//
//TEST_F(test_comparing_derived_with_derived_force_equal){
//f1 = munits.Force(1, "kg m s-2")
//f2 = munits.Force(1, "kg m s-2")
//
//self.assertTrue(f1 == f2)
//self.assertTrue(f1 <= f2)
//self.assertTrue(f1 >= f2)
//self.assertFalse(f1 > f2)
//self.assertFalse(f1 < f2)
//self.assertFalse(f1 != f2)
//
//TEST_F(test_comparing_derived_with_derived_force_greater){
//f1 = munits.Force(2, "kg m s-2")
//f2 = munits.Force(1, "kg m s-2")
//
//self.assertFalse(f1 == f2)
//self.assertFalse(f1 <= f2)
//self.assertTrue(f1 >= f2)
//self.assertTrue(f1 > f2)
//self.assertFalse(f1 < f2)
//self.assertTrue(f1 != f2)
//
//TEST_F(test_comparing_derived_with_derived_force_less){
//f1 = munits.Force(1, "kg m s-2")
//f2 = munits.Force(2, "kg m s-2")
//
//self.assertFalse(f1 == f2)
//self.assertTrue(f1 <= f2)
//self.assertFalse(f1 >= f2)
//self.assertFalse(f1 > f2)
//self.assertTrue(f1 < f2)
//self.assertTrue(f1 != f2)
//
//# MOLARCCONCENTRATION
//
//TEST_F(test_comparing_derived_with_derived_molar_concentration_equal){
//c1 = munits.MolarConcentration(1, "mol m-3")
//c2 = munits.MolarConcentration(1, "mol m-3")
//
//self.assertTrue(c1 == c2)
//self.assertTrue(c1 <= c2)
//self.assertTrue(c1 >= c2)
//self.assertFalse(c1 > c2)
//self.assertFalse(c1 < c2)
//self.assertFalse(c1 != c2)
//
//TEST_F(test_comparing_derived_with_derived_molar_concentration_greater){
//c1 = munits.MolarConcentration(2, "mol m-3")
//c2 = munits.MolarConcentration(1, "mol m-3")
//
//self.assertFalse(c1 == c2)
//self.assertFalse(c1 <= c2)
//self.assertTrue(c1 >= c2)
//self.assertTrue(c1 > c2)
//self.assertFalse(c1 < c2)
//self.assertTrue(c1 != c2)
//
//TEST_F(test_comparing_derived_with_derived_molar_concentration_less){
//c1 = munits.MolarConcentration(1, "mol m-3")
//c2 = munits.MolarConcentration(2, "mol m-3")
//
//self.assertFalse(c1 == c2)
//self.assertTrue(c1 <= c2)
//self.assertFalse(c1 >= c2)
//self.assertFalse(c1 > c2)
//self.assertTrue(c1 < c2)
//self.assertTrue(c1 != c2)
//

#endif //MUSYS_QUANTITY_TEST_COMPARISON_HPP
