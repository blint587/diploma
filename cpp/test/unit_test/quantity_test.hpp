
#ifndef MUSYS_QUANTITY_TEST_H
#define MUSYS_QUANTITY_TEST_H

#include "gtest/gtest.h"
#include "../../quantity.h"

class TestQuantityBaseUnitConversionSI : public testing::Test{};

class TestQuantityBaseUnitConversionNoneSI : public testing::Test{};

TEST_F(TestQuantityBaseUnitConversionSI, test_length_zero){
    quantity::Quantity l (quantity::Quantity::Length, 0, "m");

    EXPECT_EQ(l("Em"), 0.);
    EXPECT_EQ(l("Pm"), 0.);
    EXPECT_EQ(l("Tm"), 0.);
    EXPECT_EQ(l("Gm"), 0.);
    EXPECT_EQ(l("Mm"), 0.);
    EXPECT_EQ(l("km"), 0.);
    EXPECT_EQ(l("hm"), 0.);
    EXPECT_EQ(l("dam"), 0.);
    EXPECT_EQ(l("m"), 0.);
    EXPECT_EQ(l("dm"), 0.);
    EXPECT_EQ(l("cm"), 0.);
    EXPECT_EQ(l("mm"), 0.);
    EXPECT_EQ(l("μm"), 0.);
    EXPECT_EQ(l("nm"), 0.);
    EXPECT_EQ(l("pm"), 0.);
    EXPECT_EQ(l("fm"), 0.);
    EXPECT_EQ(l("am"), 0.);
}

TEST_F(TestQuantityBaseUnitConversionSI, test_length_one){
    quantity::Quantity l (quantity::Quantity::Length, 1, "m");

    EXPECT_EQ(l("Em"), 1e-18);
    EXPECT_EQ(l("Pm"), 1e-15);
    EXPECT_EQ(l("Tm"), 1e-12);
    EXPECT_EQ(l("Gm"), 1e-9);
    EXPECT_EQ(l("Mm"), 1e-6);
    EXPECT_EQ(l("km"), 1e-3);
    EXPECT_EQ(l("hm"), 1e-2);
    EXPECT_EQ(l("dam"), 0.1);
    EXPECT_EQ(l("m"), 1);
    EXPECT_EQ(l("dm"), 10.);
    EXPECT_EQ(l("cm"), 100.);
    EXPECT_EQ(l("mm"), 1000.);
    EXPECT_EQ(l("μm"), 1e6);
    EXPECT_NEAR(l("nm"), 1e9, 1e-2);
    EXPECT_NEAR(l("pm"), 1e12, 1e-2);
    EXPECT_NEAR(l("fm"), 1e15, 1);
    EXPECT_NEAR(l("am"), 1e18, 128);
}

TEST_F(TestQuantityBaseUnitConversionSI, test_lengt233){
    quantity::Quantity l (quantity::Quantity::Length, 2.33, "m");

    EXPECT_NEAR(l("Em"), 2.33e-18, 4e-34);
    EXPECT_NEAR(l("Pm"), 2.33e-15, 4e-31);
    EXPECT_EQ(l("Tm"), 2.33e-12);
    EXPECT_EQ(l("Gm"), 2.33e-9);
    EXPECT_EQ(l("Mm"), 2.33e-6);
    EXPECT_EQ(l("km"), 2.33e-3);
    EXPECT_EQ(l("hm"), 2.33e-2);
    EXPECT_EQ(l("dam"), 2.33e-1);
    EXPECT_EQ(l("m"), 2.33);
    EXPECT_EQ(l("dm"), 23.3);
    EXPECT_EQ(l("cm"), 233.);
    EXPECT_EQ(l("mm"), 2330.);
    EXPECT_EQ(l("μm"), 2.33e6);
    EXPECT_NEAR(l("nm"), 2.33e9, 1e-2);
    EXPECT_NEAR(l("pm"), 2.33e12, 1e-2);
    EXPECT_NEAR(l("fm"), 2.33e15, 1);
    EXPECT_NEAR(l("am"), 2.33e18, 128);

}

TEST_F(TestQuantityBaseUnitConversionSI, test_mass_zero){
    quantity::Quantity l (quantity::Quantity::Mass, 0, "g");

    EXPECT_EQ(l("Eg"), 0.);
    EXPECT_EQ(l("Pg"), 0.);
    EXPECT_EQ(l("Tg"), 0.);
    EXPECT_EQ(l("Gg"), 0.);
    EXPECT_EQ(l("Mg"), 0.);
    EXPECT_EQ(l("kg"), 0.);
    EXPECT_EQ(l("hg"), 0.);
    EXPECT_EQ(l("dag"), 0.);
    EXPECT_EQ(l("g"), 0.);
    EXPECT_EQ(l("dg"), 0.);
    EXPECT_EQ(l("cg"), 0.);
    EXPECT_EQ(l("mg"), 0.);
    EXPECT_EQ(l("μg"), 0.);
    EXPECT_NEAR(l("ng"), 0., 1e-2);
    EXPECT_NEAR(l("pg"), 0., 1e-2);
    EXPECT_NEAR(l("fg"), 0., 1);
    EXPECT_NEAR(l("ag"), 0., 128);
}

TEST_F(TestQuantityBaseUnitConversionSI, test_mass_one){
    quantity::Quantity l (quantity::Quantity::Mass, 1, "g");

    EXPECT_EQ(l("Eg"), 1e-18);
    EXPECT_EQ(l("Pg"), 1e-15);
    EXPECT_EQ(l("Tg"), 1e-12);
    EXPECT_EQ(l("Gg"), 1e-9);
    EXPECT_EQ(l("Mg"), 1e-6);
    EXPECT_EQ(l("kg"), 1e-3);
    EXPECT_EQ(l("hg"), 1e-2);
    EXPECT_EQ(l("dag"), 0.1);
    EXPECT_EQ(l("g"), 1);
    EXPECT_EQ(l("dg"), 10.);
    EXPECT_EQ(l("cg"), 100.);
    EXPECT_EQ(l("mg"), 1000.);
    EXPECT_EQ(l("μg"), 1e6);
    EXPECT_NEAR(l("ng"), 1e9, 1e-2);
    EXPECT_NEAR(l("pg"), 1e12, 1e-2);
    EXPECT_NEAR(l("fg"), 1e15, 1);
    EXPECT_NEAR(l("ag"), 1e18, 128);
}

TEST_F(TestQuantityBaseUnitConversionSI, test_mass_233){
    quantity::Quantity l (quantity::Quantity::Mass, 2.33, "g");

    EXPECT_NEAR(l("Eg"), 2.33e-18, 4e-34);
    EXPECT_NEAR(l("Pg"), 2.33e-15, 4e-31);
    EXPECT_EQ(l("Tg"), 2.33e-12);
    EXPECT_EQ(l("Gg"), 2.33e-9);
    EXPECT_EQ(l("Mg"), 2.33e-6);
    EXPECT_EQ(l("kg"), 2.33e-3);
    EXPECT_EQ(l("hg"), 2.33e-2);
    EXPECT_EQ(l("dag"), 0.233);
    EXPECT_EQ(l("g"), 2.33);
    EXPECT_EQ(l("dg"), 23.3);
    EXPECT_EQ(l("cg"), 233.);
    EXPECT_EQ(l("mg"), 2330.);
    EXPECT_EQ(l("μg"), 2.33e6);
    EXPECT_NEAR(l("ng"), 2.33e9, 1e-2);
    EXPECT_NEAR(l("pg"), 2.33e12, 1e-2);
    EXPECT_NEAR(l("fg"), 2.33e15, 1);
    EXPECT_NEAR(l("ag"), 2.33e18, 128);
}

TEST_F(TestQuantityBaseUnitConversionSI, test_time_zero) {
    quantity::Quantity t(quantity::Quantity::Time, 0.0, "s");

    EXPECT_EQ(t("ms"), 0);
    EXPECT_EQ(t("μs"), 0);
    EXPECT_EQ(t("ns"), 0);
    EXPECT_EQ(t("ps"), 0);
    EXPECT_EQ(t("fs"), 0);
    EXPECT_EQ(t("as"), 0);

}

TEST_F(TestQuantityBaseUnitConversionSI, test_time_one){

    quantity::Quantity t(quantity::Quantity::Time, 1.0, "s");

    EXPECT_EQ(t("ms"), 1000.);
    EXPECT_EQ(t("μs"), 1e6);
    EXPECT_NEAR(t("ns"), 1e9, 1e-2);
    EXPECT_NEAR(t("ps"), 1e12, 1e-2);
    EXPECT_NEAR(t("fs"), 1e15, 1);
    EXPECT_NEAR(t("as"), 1e18, 128);

 }

TEST_F(TestQuantityBaseUnitConversionSI, test_time_233) {
    quantity::Quantity t (quantity::Quantity::Time, 2.33, "s");

    EXPECT_EQ(t("ms"), 2330.);
    EXPECT_EQ(t("μs"), 2.33e6);
    EXPECT_EQ(t("ns"), 2.33e9);
    EXPECT_EQ(t("ps"), 2.33e12);
    EXPECT_EQ(t("fs"), 2.33e15);
    EXPECT_EQ(t("as"), 2.33e18);
}

TEST_F(TestQuantityBaseUnitConversionSI, test_electric_currency_zero) {
    quantity::Quantity i(quantity::Quantity::ElectricCurrency, 0, "A");

    EXPECT_EQ(i("EA"), 0);
    EXPECT_EQ(i("PA"), 0);
    EXPECT_EQ(i("TA"), 0);
    EXPECT_EQ(i("GA"), 0);
    EXPECT_EQ(i("MA"), 0);
    EXPECT_EQ(i("kA"), 0);
    EXPECT_EQ(i("hA"), 0);
    EXPECT_EQ(i("daA"), 0);
    EXPECT_EQ(i("A"), 0);
    EXPECT_EQ(i("dA"), 0);
    EXPECT_EQ(i("cA"), 0);
    EXPECT_EQ(i("mA"), 0);
    EXPECT_EQ(i("μA"), 0);
    EXPECT_EQ(i("nA"), 0);
    EXPECT_EQ(i("pA"), 0);
    EXPECT_EQ(i("fA"), 0);
    EXPECT_EQ(i("aA"), 0);
}

TEST_F(TestQuantityBaseUnitConversionSI, test_electric_currency_one) {
    quantity::Quantity i(quantity::Quantity::ElectricCurrency, 1, "A");

    EXPECT_EQ(i("EA"), 1e-18);
    EXPECT_EQ(i("PA"), 1e-15);
    EXPECT_EQ(i("TA"), 1e-12);
    EXPECT_EQ(i("GA"), 1e-9);
    EXPECT_EQ(i("MA"), 1e-6);
    EXPECT_EQ(i("kA"), 1e-3);
    EXPECT_EQ(i("hA"), 1e-2);
    EXPECT_EQ(i("daA"), 1e-1);
    EXPECT_EQ(i("A"), 1.);
    EXPECT_EQ(i("dA"), 10.);
    EXPECT_EQ(i("cA"), 100.);
    EXPECT_EQ(i("mA"), 1000.);
    EXPECT_EQ(i("μA"), 1e6);
    EXPECT_NEAR(i("nA"), 1e9, 1e-2);
    EXPECT_NEAR(i("pA"), 1e12, 1e-2);
    EXPECT_NEAR(i("fA"), 1e15, 1);
    EXPECT_NEAR(i("aA"), 1e18, 128);
}

TEST_F(TestQuantityBaseUnitConversionSI, test_electric_currency_233){

    quantity::Quantity i (quantity::Quantity::ElectricCurrency, 2.33, "A");

    EXPECT_NEAR(i("EA"), 2.33e-18, 4e-34);
    EXPECT_NEAR(i("PA"), 2.33e-15, 4e-31);
    EXPECT_EQ(i("TA"), 2.33e-12);
    EXPECT_EQ(i("GA"), 2.33e-9);
    EXPECT_EQ(i("MA"), 2.33e-6);
    EXPECT_EQ(i("kA"), 2.33e-3);
    EXPECT_EQ(i("hA"), 2.33e-2);
    EXPECT_EQ(i("daA"), 2.33e-1);
    EXPECT_EQ(i("A"), 2.33);
    EXPECT_EQ(i("dA"), 23.3);
    EXPECT_EQ(i("cA"), 233.);
    EXPECT_EQ(i("mA"), 2330.);
    EXPECT_EQ(i("μA"), 2.33e6);
    EXPECT_EQ(i("nA"), 2.33e9);
    EXPECT_EQ(i("pA"), 2.33e12);
    EXPECT_EQ(i("fA"), 2.33e15);
    EXPECT_EQ(i("aA"), 2.33e18);
}

TEST_F(TestQuantityBaseUnitConversionSI, test_aos_one){
   quantity::Quantity n (quantity::Quantity::AmountOfSubstance, 1.0, "kmol");

    EXPECT_EQ(n("mol"), 1000.0);
}

// NONE SI


TEST_F(TestQuantityBaseUnitConversionNoneSI, test_si_length_m_to_in_ft_mi) {
   quantity::Quantity l (quantity::Quantity::Length, 1, "m");

    EXPECT_NEAR(l("in"), 39.37, 1e-4);
    EXPECT_NEAR(l("ft"), 3.2808, 1e-4);
    EXPECT_NEAR(l("mi"), 0.000621, 1e-4);
}
//def test_si_length_m_to_in_ft_mi_233(self):
//l = quantity.Length(2.33, "m")
//
//EXPECT_NEAR(l("in"), "91.7322"), delta=1e-4)
//EXPECT_NEAR(l("ft"), "7.6443"), delta=1e-4)
//EXPECT_NEAR(l("mi"), "0.00144"), delta=1e-4)
//
//def test_none_si_length_inch_to_ft_mi(self):
//l = quantity.Length(1, "in")
//
//EXPECT_NEAR(l("ft"), "0.0833"), delta=1e-2)
//EXPECT_NEAR(l("mi"), "1.578e-5"), delta=1e-2)
//EXPECT_NEAR(l("in"), "1"), delta=1e-2)
//
//def test_none_si_length_inch_to_ft_mi_233(self):
//l = quantity.Length(2.33, "in")
//
//EXPECT_NEAR(l("ft"), "0.1941"), delta=1e-4)
//EXPECT_NEAR(l("mi"), "3.677e-5"), delta=1e-2)
//EXPECT_NEAR(l("in"), "2.33"), delta=1e-2)
//
//def test_none_si_length_inch_in_to_prefix_m(self):
//l = quantity.Length(1, "in")
//
//EXPECT_EQ(l("Em"), "0.0254e-18"))
//EXPECT_EQ(l("Pm"), "0.0254e-15"))
//EXPECT_NEAR(l("Tm"), "0.0254e-12"), delta=1e-6)
//EXPECT_EQ(l("Gm"), "0.0254e-9"))
//EXPECT_EQ(l("Mm"), "0.0254e-6"))
//EXPECT_EQ(l("km"), "0.0254e-3"))
//EXPECT_EQ(l("hm"), "0.0254e-2"))
//EXPECT_EQ(l("dam"), "0.0254e-1"))
//EXPECT_EQ(l("m"), "0.0254"))
//EXPECT_EQ(l("dm"), "0.0254e1"))
//EXPECT_EQ(l("cm"), "0.0254e2"))
//EXPECT_EQ(l("mm"), "0.0254e3"))
//EXPECT_EQ(l("μm"), "0.0254e6"))
//EXPECT_NEAR(l("nm"), "0.0254e9"), delta=1e-6)
//EXPECT_EQ(l("pm"), "0.0254e12"))
//EXPECT_NEAR(l("fm"), "0.0254e15"), delta=1)
//# EXPECT_NEAR(l("am"), "0.0254e18"), delta=1000)
//
//@unittest.skip("inch to prefix_yard")
//def test_non_si_length(self):
//l = quantity.Length(1, "in")
//EXPECT_EQ(l("Eyd"), "0.02778993435448577680525164114e-18"))
//EXPECT_EQ(l("Pyd"), "0.02778993435448577680525164114e-15"))
//EXPECT_EQ(l("Tyd"), "0.02778993435448577680525164114e-12"))
//EXPECT_EQ(l("Gyd"), "0.02778993435448577680525164114e-9"))
//EXPECT_EQ(l("Myd"), "0.02778993435448577680525164114e-6"))
//EXPECT_EQ(l("kyd"), "0.02778993435448577680525164114e-3"))
//EXPECT_EQ(l("hyd"), "0.02778993435448577680525164114e-2"))
//EXPECT_EQ(l("dayd"), "0.02778993435448577680525164114e-1"))
//EXPECT_EQ(l("yd"), "0.02778993435448577680525164114"))
//EXPECT_EQ(l("dyd"), "0.02778993435448577680525164114e1"))
//EXPECT_EQ(l("cyd"), "0.02778993435448577680525164114e2"))
//EXPECT_EQ(l("myd"), "0.02778993435448577680525164114e3"))
//EXPECT_EQ(l("μyd"), "0.02778993435448577680525164114e6"))
//EXPECT_EQ(l("nyd"), "0.02778993435448577680525164114e9"))
//EXPECT_EQ(l("pyd"), "0.02778993435448577680525164114e12"))
//EXPECT_EQ(l("fyd"), "0.02778993435448577680525164114e15"))
//EXPECT_EQ(l("ayd"), "0.02778993435448577680525164114e18"))
//
//def test_mass_g_to_oz_lb_t(self):
//m = quantity.Mass(1, "g")
//
//EXPECT_NEAR(m("oz"), "0.0352"), delta=1e-4)
//EXPECT_NEAR(m("lb"), "0.0022"), delta=1e-4)
//EXPECT_EQ(m("t"), "1e-6"))
//
//def test_mass_g_to_oz_lb_t_233(self):
//m = quantity.Mass(2.33, "g")
//
//EXPECT_NEAR(m("oz"), "0.0821"), delta=1e-4)
//EXPECT_NEAR(m("lb"), "0.00513"), delta=1e-4)
//EXPECT_EQ(m("t"), "2.33e-6"))
//
//def test_time_from_s_to_min(self):
//t = quantity.Time(30, "s")
//EXPECT_EQ(t("min"), "0.5"))
//
//def test_time_from_min_to_s(self):
//t = quantity.Time(1.0, "min")
//EXPECT_EQ(t("s"), "60"))
//
//def test_time_from_hour_to_s(self):
//t = quantity.Time(1.0, "h")
//EXPECT_EQ(t("s"), "3600"))
//
//def test_time_from_s_to_hour(self):
//t = quantity.Time(3600, "s")
//EXPECT_EQ(t("h"), "1"))
//
//def test_time_from_d_to_s(self):
//t = quantity.Time(1.0, "d")
//EXPECT_EQ(t("s"), "86400."))
//
//def test_time_from_s_to_d(self):
//t = quantity.Time(43200, "s")
//EXPECT_EQ(t("d"), "0.5"))
//
//def test_time_from_day_to_hour(self):
//t = quantity.Time(1, "d")
//EXPECT_EQ(t("h"), "24"))
//
//def test_time_from_hour_to_day(self):
//t = quantity.Time(48, "h")
//EXPECT_EQ(t("d"), "2"))
//

//
//def test_temperature_from_K(self):
//t = quantity.Temperature(0.0, "K")
//EXPECT_EQ(t("K"), "0.0"))
//EXPECT_EQ(t("°C"), "-273.15"))
//EXPECT_EQ(t("°F"), "-459.67"))
//
//def test_temperature_from_K_233(self):
//t = quantity.Temperature(2.33, "K")
//EXPECT_EQ(t("K"), "2.33"))
//EXPECT_EQ(t("°C"), "-270.82"))
//EXPECT_EQ(t("°F"), "-455.476"))
//
//def test_temperature_from_C(self):
//t = quantity.Temperature(-40.0, "°C")
//EXPECT_EQ(t("°C"), "-40.0"))
//EXPECT_NEAR(t("K"), "233.15"), delta=1e-9)
//EXPECT_NEAR(t("°F"), "-40.0"), delta=1e-9)
//
//def test_temperature_from_F(self):
//t = quantity.Temperature(-40.0, "°F")
//EXPECT_NEAR(t("K"), "233.15"), delta=1e-9)
//EXPECT_NEAR(t("°C"), "-40.0"), delta=1e-9)
//
//
//class TestQuantityBaseUnitComparison(unittest.TestCase):
//def test_comparing_base_with_base_equal(self):
//m1 = quantity.Mass(1., "g")
//m2 = quantity.Mass(1., "g")
//self.assertTrue(m1 == m2)
//self.assertTrue(m1 <= m2)
//self.assertTrue(m1 >= m2)
//self.assertFalse(m1 > m2)
//self.assertFalse(m1 < m2)
//self.assertFalse(m1 != m2)
//
//def test_comparing_base_with_base_greater(self):
//m1 = quantity.Mass(2., "g")
//m2 = quantity.Mass(1., "g")
//self.assertFalse(m1 == m2)
//self.assertFalse(m1 <= m2)
//self.assertTrue(m1 >= m2)
//self.assertTrue(m1 > m2)
//self.assertFalse(m1 < m2)
//self.assertTrue(m1 != m2)
//
//def test_comparing_base_with_base_less(self):
//m1 = quantity.Mass(1., "g")
//m2 = quantity.Mass(2., "g")
//self.assertFalse(m1 == m2)
//self.assertTrue(m1 <= m2)
//self.assertFalse(m1 >= m2)
//self.assertFalse(m1 > m2)
//self.assertTrue(m1 < m2)
//self.assertTrue(m1 != m2)
//
//def test_comparing_none_base_with_base_equal(self):
//l1 = quantity.Length(1000., "mm")
//l2 = quantity.Length(1., "m")
//self.assertTrue(l1 == l2)
//self.assertTrue(l1 <= l2)
//self.assertTrue(l1 >= l2)
//self.assertFalse(l1 > l2)
//self.assertFalse(l1 < l2)
//self.assertFalse(l1 != l2)
//
//def test_comparing_none_base_with_base_greater(self):
//l1 = quantity.Length(10000., "mm")
//l2 = quantity.Length(1., "m")
//self.assertFalse(l1 == l2)
//self.assertFalse(l1 <= l2)
//self.assertTrue(l1 >= l2)
//self.assertTrue(l1 > l2)
//self.assertFalse(l1 < l2)
//self.assertTrue(l1 != l2)
//
//def test_comparing_none_base_with_base_less(self):
//l1 = quantity.Length(100., "mm")
//l2 = quantity.Length(1., "m")
//self.assertFalse(l1 == l2)
//self.assertTrue(l1 <= l2)
//self.assertFalse(l1 >= l2)
//self.assertFalse(l1 > l2)
//self.assertTrue(l1 < l2)
//self.assertTrue(l1 != l2)
//
//def test_comparing_none_base_with_none_base_equal(self):
//m1 = quantity.Mass(100., "dag")
//m2 = quantity.Mass(1., "kg")
//self.assertTrue(m1 == m2)
//self.assertTrue(m1 <= m2)
//self.assertTrue(m1 >= m2)
//self.assertFalse(m1 > m2)
//self.assertFalse(m1 < m2)
//self.assertFalse(m1 != m2)
//
//def test_comparing_none_base_with_none_base_less(self):
//m1 = quantity.Mass(10., "dag")
//m2 = quantity.Mass(1., "kg")
//self.assertFalse(m1 == m2)
//self.assertTrue(m1 <= m2)
//self.assertFalse(m1 >= m2)
//self.assertFalse(m1 > m2)
//self.assertTrue(m1 < m2)
//self.assertTrue(m1 != m2)
//
//def test_comparing_none_base_with_none_base_greater(self):
//m1 = quantity.Mass(1000., "dag")
//m2 = quantity.Mass(1., "kg")
//self.assertFalse(m1 == m2)
//self.assertFalse(m1 <= m2)
//self.assertTrue(m1 >= m2)
//self.assertTrue(m1 > m2)
//self.assertFalse(m1 < m2)
//self.assertTrue(m1 != m2)
//
//# TIME
//
//def test_comparing_time_none_base_with_none_base_equal(self):
//t1 = quantity.Time(1., "d")
//t2 = quantity.Time(24., "h")
//self.assertTrue(t1 == t2)
//self.assertTrue(t1 <= t2)
//self.assertTrue(t1 >= t2)
//self.assertFalse(t1 > t2)
//self.assertFalse(t1 < t2)
//self.assertFalse(t1 != t2)
//
//def test_comparing_time_none_base_with_none_base_less(self):
//t1 = quantity.Time(1., "d")
//t2 = quantity.Time(25., "h")
//self.assertFalse(t1 == t2)
//self.assertTrue(t1 <= t2)
//self.assertFalse(t1 >= t2)
//self.assertFalse(t1 > t2)
//self.assertTrue(t1 < t2)
//self.assertTrue(t1 != t2)
//
//def test_comparing_time_none_base_with_none_base_greater(self):
//t1 = quantity.Time(1., "d")
//t2 = quantity.Time(23., "h")
//self.assertFalse(t1 == t2)
//self.assertFalse(t1 <= t2)
//self.assertTrue(t1 >= t2)
//self.assertTrue(t1 > t2)
//self.assertFalse(t1 < t2)
//self.assertTrue(t1 != t2)
//
//def test_comparing_base_with_base_temperature_equal(self):
//t1 = quantity.Temperature(273.15, "K")
//t2 = quantity.Temperature(273.15, "K")
//self.assertTrue(t1 == t2)
//self.assertTrue(t1 <= t2)
//self.assertTrue(t1 >= t2)
//self.assertFalse(t1 < t2)
//self.assertFalse(t1 > t2)
//self.assertFalse(t1 != t2)
//
//def test_comparing_base_with_base_temperature_less(self):
//t1 = quantity.Temperature(0., "K")
//t2 = quantity.Temperature(273.15, "K")
//self.assertFalse(t1 == t2)
//self.assertTrue(t1 <= t2)
//self.assertFalse(t1 >= t2)
//self.assertTrue(t1 < t2)
//self.assertFalse(t1 > t2)
//self.assertTrue(t1 != t2)
//
//def test_comparing_base_with_base_temperature_greater(self):
//t1 = quantity.Temperature(273.15, "K")
//t2 = quantity.Temperature(0., "K")
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
//def test_comparing_derived_with_derived_acceleration_equal(self):
//a1 = quantity.Acceleration(1, "m s-2")
//a2 = quantity.Acceleration(1, "m s-2")
//
//self.assertTrue(a1 == a2)
//self.assertTrue(a1 <= a2)
//self.assertTrue(a1 >= a2)
//self.assertFalse(a1 > a2)
//self.assertFalse(a1 < a2)
//self.assertFalse(a1 != a2)
//
//def test_comparing_derived_with_derived_acceleration_greater(self):
//a1 = quantity.Acceleration(2, "m s-2")
//a2 = quantity.Acceleration(1, "m s-2")
//
//self.assertFalse(a1 == a2)
//self.assertFalse(a1 <= a2)
//self.assertTrue(a1 >= a2)
//self.assertTrue(a1 > a2)
//self.assertFalse(a1 < a2)
//self.assertTrue(a1 != a2)
//
//def test_comparing_derived_with_derived_acceleration_less(self):
//a1 = quantity.Acceleration(1, "m s-2")
//a2 = quantity.Acceleration(2, "m s-2")
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
//def test_comparing_derived_with_derived_force_equal(self):
//f1 = quantity.Force(1, "kg m s-2")
//f2 = quantity.Force(1, "kg m s-2")
//
//self.assertTrue(f1 == f2)
//self.assertTrue(f1 <= f2)
//self.assertTrue(f1 >= f2)
//self.assertFalse(f1 > f2)
//self.assertFalse(f1 < f2)
//self.assertFalse(f1 != f2)
//
//def test_comparing_derived_with_derived_force_greater(self):
//f1 = quantity.Force(2, "kg m s-2")
//f2 = quantity.Force(1, "kg m s-2")
//
//self.assertFalse(f1 == f2)
//self.assertFalse(f1 <= f2)
//self.assertTrue(f1 >= f2)
//self.assertTrue(f1 > f2)
//self.assertFalse(f1 < f2)
//self.assertTrue(f1 != f2)
//
//def test_comparing_derived_with_derived_force_less(self):
//f1 = quantity.Force(1, "kg m s-2")
//f2 = quantity.Force(2, "kg m s-2")
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
//def test_comparing_derived_with_derived_molar_concentration_equal(self):
//c1 = quantity.MolarConcentration(1, "mol m-3")
//c2 = quantity.MolarConcentration(1, "mol m-3")
//
//self.assertTrue(c1 == c2)
//self.assertTrue(c1 <= c2)
//self.assertTrue(c1 >= c2)
//self.assertFalse(c1 > c2)
//self.assertFalse(c1 < c2)
//self.assertFalse(c1 != c2)
//
//def test_comparing_derived_with_derived_molar_concentration_greater(self):
//c1 = quantity.MolarConcentration(2, "mol m-3")
//c2 = quantity.MolarConcentration(1, "mol m-3")
//
//self.assertFalse(c1 == c2)
//self.assertFalse(c1 <= c2)
//self.assertTrue(c1 >= c2)
//self.assertTrue(c1 > c2)
//self.assertFalse(c1 < c2)
//self.assertTrue(c1 != c2)
//
//def test_comparing_derived_with_derived_molar_concentration_less(self):
//c1 = quantity.MolarConcentration(1, "mol m-3")
//c2 = quantity.MolarConcentration(2, "mol m-3")
//
//self.assertFalse(c1 == c2)
//self.assertTrue(c1 <= c2)
//self.assertFalse(c1 >= c2)
//self.assertFalse(c1 > c2)
//self.assertTrue(c1 < c2)
//self.assertTrue(c1 != c2)
//
//
//class TestQuantityValidUnit(unittest.TestCase):
//def test_valid_mass_unit(self):
//self.assertTrue(quantity.Mass.is_valid_unit("kg"))
//
//def test_invalid_mass_unit(self):
//self.assertFalse(quantity.Mass.is_valid_unit("tg"))
//
//def test_valid_time_unit_second(self):
//self.assertTrue(quantity.Time.is_valid_unit("s"))
//
//def test_invalid_time_unit_second(self):
//self.assertFalse(quantity.Time.is_valid_unit("ts"))
//
//def test_valid_temperature_unit(self):
//self.assertTrue(quantity.Temperature.is_valid_unit("°C"))
//
//
//class TestQuantityAddition(unittest.TestCase):
//def test_adding_mass_to_mass(self):
//m1 = quantity.Mass(1000., "g")
//m2 = quantity.Mass(1., "kg")
//m3 = m1 + m2
//
//EXPECT_EQ(m3.value, 2000.)
//EXPECT_EQ(m3.unit, "g")
//self.assertFalse(id(m1) == id(m3))
//self.assertFalse(id(m2) == id(m3))
//
//
//class TestQuantityDerivedUnitsConversion(unittest.TestCase):
//def test_convert_velocity_from_mps_to_kmph(self):
//v = quantity.Velocity(1.0, "m s-1")
//EXPECT_EQ(v("km h-1"), "3.6"))
//
//def test_convert_velocity_from_kmph_to_kmph(self):
//v = quantity.Velocity(3.6, "km h-1")
//EXPECT_EQ(v("km h-1"), "3.6"))
//
//def test_convert_velocity_from_kmph_to_mps(self):
//v = quantity.Velocity(3.6, "km h-1")
//EXPECT_EQ(v("m s-1"), "1."))
//
//def test_convert_velocity_from_miph_to_kmph(self):
//v = quantity.Velocity(1., "mi h-1")
//EXPECT_EQ(v("km h-1"), "1.609344"))
//
//def test_convert_area_from_inch2_to_yd2(self):
//a = quantity.Area(2.33, "in2")
//EXPECT_NEAR(a("yd2"), "0.00179783951"), delta=1e-3)
//
//def test_convert_area_from_m2_to_are(self):
//a = quantity.Area(200, "m2")
//EXPECT_NEAR(a("are"), "2"), delta=1e-3)
//
//def test_convert_area_from_acre_to_are(self):
//a = quantity.Area(1, "ac")
//EXPECT_NEAR(a("are"), "40.4684"), delta=1e-3)
//
//def test_converting_volume_from_m3_to_in3(self):
//v = quantity.Volume(1, "m3")
//EXPECT_NEAR(v("cm3"), "1000000."), delta=1e-6)
//EXPECT_NEAR(v("gal"), "264.1720526372959086633370175"), delta=1e-6)
//EXPECT_NEAR(v("in3"), "61023.74409473228395275688189"), delta=1e-6)
//
//def test_converting_volumetric_flow_from_m3ph_to(self):
//v = quantity.VolumetricFlow(1.0, "m3 h-1")
//EXPECT_NEAR(v("m3 d-1"), "24.0"), delta=1e-6)
//EXPECT_NEAR(v("gal min-1"), "4.402867543954931811055616958"), delta=1e-6)
//EXPECT_NEAR(v("l s-1"), "0.2777777777777777777777777778"), delta=1e-6)
//
//def test_converting_acceleration(self):
//a = quantity.Acceleration(1.0, "m s-2")
//EXPECT_EQ(a("in s-2"), "39.37007874015748031496062992"))
//EXPECT_EQ(a("in ms-2"), "0.00003937007874015748031496062992"))
//
//def test_convert_force(self):
//f = quantity.Force(1.0, "kg m s-2")
//EXPECT_EQ(f("lb yd s-2"), "2.412061728866277343179999663"))
//
//def test_convert_concentration(self):
//c = quantity.Concentration(1., "mg l-1")
//EXPECT_NEAR(c("mg dm-3"), "1.0"), delta=1e-6)
//EXPECT_NEAR(c("g m-3"), "1.0"), delta=1e-6)
//
//
//class test_derived_units_from_base_units(unittest.TestCase):
//def test_acceleration_from_l_t_zero(self):
//l = quantity.Length(0, "m")
//t = quantity.Time(1, "s")
//a1 = l / (t * t)
//a2 = l / (t ** 2)
//a3 = l / t / t
//
//self.assertIsInstance(a1, quantity.Acceleration)
//self.assertIsInstance(a2, quantity.Acceleration)
//self.assertIsInstance(a3, quantity.Acceleration)
//
//def test_acceleration_from_l_t(self):
//l = quantity.Length(1, "m")
//t = quantity.Time(1, "s")
//a1 = l / (t * t)
//a2 = l / (t ** 2)
//a3 = l / t / t
//
//self.assertIsInstance(a1, quantity.Acceleration)
//self.assertIsInstance(a2, quantity.Acceleration)
//self.assertIsInstance(a3, quantity.Acceleration)
//
//def test_acceleration_from_l_t_none_zero(self):
//l = quantity.Length(2.33, "m")
//t = quantity.Time(2.33, "s")
//a1 = l / (t * t)
//a2 = l / (t ** 2)
//a3 = l / t / t
//
//EXPECT_NEAR(a1("m s-2"), "0.4229"), delta=1e-2)
//EXPECT_NEAR(a2("m s-2"), "0.4229"), delta=1e-2)
//EXPECT_NEAR(a3("m s-2"), "0.4229"), delta=1e-2)
//
//def test_force_from_m_a_zero(self):
//m = quantity.Mass(0, "g")
//a = quantity.Acceleration(0, "m s-2")
//f1 = m * a
//self.assertIsInstance(f1, quantity.Force)
//EXPECT_EQ(f1("kg m s-2"), "0."))
//
//def test_force_from_m_a(self):
//m = quantity.Mass(1, "kg")
//a = quantity.Acceleration(1, "m s-2")
//f1 = m * a
//EXPECT_EQ(f1("kg m s-2"), "1"))
//
//def test_force_from_m_a_233(self):
//m = quantity.Mass(2.33, "kg")
//a = quantity.Acceleration(1, "m s-2")
//f1 = m * a
//EXPECT_EQ(f1("kg m s-2"), "2.33"))
//
//def test_volumetricflow_zero(self):
//v = quantity.Volume(0, "m3")
//t = quantity.Time(1, "h")
//vf = v / t
//self.assertIsInstance(vf, quantity.VolumetricFlow)
//EXPECT_EQ(vf("m3 h-1"), "0."))
//
//def test_volumetricflow_(self):
//l = quantity.Length(1, "m")
//v1 = l * l * l
//v2 = l ** 3
//t = quantity.Time(1, "h")
//vf1 = v1 / t
//vf2 = v2 / t
//vf3 = l * l * l / t
//self.assertIsInstance(vf1, quantity.VolumetricFlow)
//EXPECT_EQ(vf1("m3 h-1"), "1."))
//
//self.assertIsInstance(vf2, quantity.VolumetricFlow)
//EXPECT_EQ(vf2("m3 h-1"), "1."))
//
//self.assertIsInstance(vf3, quantity.VolumetricFlow)
//EXPECT_EQ(vf3("m3 h-1"), "1."))
//
//def test_volumetricflow_233(self):
//l = quantity.Length(2.33, "m")
//v = quantity.Volume(12.649, "m3")
//l1 = l * l * l
//t = quantity.Time(2.33, "h")
//vf1 = l1 / t
//vf2 = v / t
//self.assertIsInstance(vf1, quantity.VolumetricFlow)
//EXPECT_NEAR(vf1("m3 h-1"), "5.4289"), delta=1e-6)
//
//self.assertIsInstance(vf2, quantity.VolumetricFlow)
//EXPECT_NEAR(vf2("m3 h-1"), "5.4289"), delta=1e-3)
//
//
//def test_molar_concentration_from_n_l_v_zero(self):
//l = quantity.Length(1, "m")
//v = quantity.Volume(1, "m3")
//n = quantity.AmountOfSubstance(0, "mol")
//mc1 = n / (l * l * l)
//mc2 = n / (l ** 3)
//mc3 = n / l / l / l
//mc4 = n / v
//
//self.assertIsInstance(mc1, quantity.MolarConcentration)
//self.assertIsInstance(mc2, quantity.MolarConcentration)
//self.assertIsInstance(mc3, quantity.MolarConcentration)
//self.assertIsInstance(mc4, quantity.MolarConcentration)
//
//EXPECT_EQ(mc1("mol m-3"), "0."))
//EXPECT_EQ(mc2("mol m-3"), "0."))
//EXPECT_EQ(mc3("mol m-3"), "0."))
//EXPECT_EQ(mc4("mol m-3"), "0."))
//
//
//def test_molar_concentration_from_n_l_v(self):
//l = quantity.Length(1, "m")
//v = quantity.Volume(1, "m3")
//n = quantity.AmountOfSubstance(1, "mol")
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
//def test_molar_concentration_from_n_l_v_233(self):
//l = quantity.Length(2.33, "m")
//v = quantity.Volume(12.649, "m3")
//n = quantity.AmountOfSubstance(1, "mol")
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
//
//
#endif //MUSYS_QUANTITY_TEST_H
