
#ifndef MUSYS_QUANTITY_TEST_H
#define MUSYS_QUANTITY_TEST_H

#include "gtest/gtest.h"
#include "../../src/quantity.h"

class TestQuantityBaseUnitConversionSI : public testing::Test{};

class TestQuantityBaseUnitConversionNoneSI : public testing::Test{};

class TestQuantityDerivedUnitConversion : public testing::Test{};

TEST_F(TestQuantityBaseUnitConversionSI, test_length_zero){
    munits::Quantity l (munits::Length, 0, "m");

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
    munits::Quantity l (munits::Length, 1, "m");

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
    munits::Quantity l (munits::Length, 2.33, "m");

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
    munits::Quantity l (munits::Mass, 0, "g");

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
    munits::Quantity l (munits::Mass, 1, "g");

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
    munits::Quantity l (munits::Mass, 2.33, "g");

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
    munits::Quantity t(munits::Time, 0.0, "s");

    // TODO: implement non prefixed conversions (min, d, h)
    EXPECT_EQ(t("ms"), 0);
    EXPECT_EQ(t("μs"), 0);
    EXPECT_EQ(t("ns"), 0);
    EXPECT_EQ(t("ps"), 0);
    EXPECT_EQ(t("fs"), 0);
    EXPECT_EQ(t("as"), 0);
    EXPECT_EQ(t("min"), 0);

}

TEST_F(TestQuantityBaseUnitConversionSI, test_time_one){

    munits::Quantity t(munits::Time, 1.0, "s");

    EXPECT_EQ(t("ms"), 1000.);
    EXPECT_EQ(t("μs"), 1e6);
    EXPECT_NEAR(t("ns"), 1e9, 1e-2);
    EXPECT_NEAR(t("ps"), 1e12, 1e-2);
    EXPECT_NEAR(t("fs"), 1e15, 1);
    EXPECT_NEAR(t("as"), 1e18, 128);

 }

TEST_F(TestQuantityBaseUnitConversionSI, test_time_233) {
    munits::Quantity t (munits::Time, 2.33, "s");

    EXPECT_EQ(t("ms"), 2330.);
    EXPECT_EQ(t("μs"), 2.33e6);
    EXPECT_EQ(t("ns"), 2.33e9);
    EXPECT_EQ(t("ps"), 2.33e12);
    EXPECT_EQ(t("fs"), 2.33e15);
    EXPECT_EQ(t("as"), 2.33e18);
}

TEST_F(TestQuantityBaseUnitConversionSI, test_electric_currency_zero) {
    munits::Quantity i(munits::ElectricCurrency, 0, "A");

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
    munits::Quantity i(munits::ElectricCurrency, 1, "A");

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

    munits::Quantity i (munits::ElectricCurrency, 2.33, "A");

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
   munits::Quantity n (munits::AmountOfSubstance, 1.0, "kmol");

    EXPECT_EQ(n("mol"), 1000.0);
}


// NONE SI

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_si_length_m_to_in_ft_mi) {
   munits::Quantity l (munits::Length, 1, "m");

    EXPECT_NEAR(l("inc"), 39.37, 1e-4);
    EXPECT_NEAR(l("ft"), 3.2808, 1e-4);
    EXPECT_NEAR(l("mi"), 0.000621, 1e-4);
    EXPECT_NEAR(l("yd"), 1.0940919037199124, 1e-4);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_si_length_m_to_in_ft_mi_233){
    munits::Quantity l(munits::Length, 2.33, "m");

    EXPECT_NEAR(l("inc"), 91.7322, 1e-4);
    EXPECT_NEAR(l("ft"), 7.6443, 1e-4);
    EXPECT_NEAR(l("mi"), 0.00144, 1e-4);
    EXPECT_NEAR(l("yd"), 2.5492341356673958, 1e-4);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_none_si_length_inch_to_ft_mi){
    munits::Quantity l(munits::Length, 1, "inc");

    EXPECT_NEAR(l("ft"), 0.0833, 1e-2);
    EXPECT_NEAR(l("mi"), 1.578e-5, 1e-2);
    EXPECT_NEAR(l("inc"), 1, 1e-2);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_none_si_length_inch_to_ft_mi_233){
    munits::Quantity l (munits::Length, 2.33, "inc");

    EXPECT_NEAR(l("ft"), 0.1941, 1e-4);
    EXPECT_NEAR(l("mi"), 3.677e-5, 1e-2);
    EXPECT_NEAR(l("inc"), 2.33, 1e-2);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_none_si_length_inch_in_to_prefix_m){
    munits::Quantity l (munits::Length, 1, "inc");

    EXPECT_EQ(l("Em"), 0.0254e-18);
    EXPECT_EQ(l("Pm"), 0.0254e-15);
    EXPECT_NEAR(l("Tm"), 0.0254e-12, 1e-6);
    EXPECT_EQ(l("Gm"), 0.0254e-9);
    EXPECT_EQ(l("Mm"), 0.0254e-6);
    EXPECT_EQ(l("km"), 0.0254e-3);
    EXPECT_EQ(l("hm"), 0.0254e-2);
    EXPECT_EQ(l("dam"), 0.0254e-1);
    EXPECT_EQ(l("m"), 0.0254);
    EXPECT_EQ(l("dm"), 0.0254e1);
    EXPECT_EQ(l("cm"), 0.0254e2);
    EXPECT_EQ(l("mm"), 0.0254e3);
    EXPECT_EQ(l("μm"), 0.0254e6);
    EXPECT_NEAR(l("nm"), 0.0254e9, 1e-6);
    EXPECT_EQ(l("pm"), 0.0254e12);
    EXPECT_NEAR(l("fm"), 0.0254e15, 1);
    EXPECT_NEAR(l("am"), 0.0254e18, 1000);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_non_si_length){
    munits::Quantity l (munits::Length, 1, "inc");
    EXPECT_NEAR(l("Eyd"), 2.77777778e-20, 1e-22);
    EXPECT_NEAR(l("Pyd"), 2.7789934354485774e-17, 1e-20);
    EXPECT_NEAR(l("Tyd"), 2.7789934354485771e-14, 1e-18);
    EXPECT_NEAR(l("Gyd"), 2.7789934354485776e-11, 1e-14);
    EXPECT_NEAR(l("Myd"), 2.7789934354485775e-8, 1e-13);
    EXPECT_NEAR(l("kyd"), 2.7789934354485775e-5, 1e-8);
    EXPECT_NEAR(l("hyd"), 2.7789934354485773e-4, 1e-7);
    EXPECT_NEAR(l("dayd"), 2.7789934354485778e-3, 1e-6);
    EXPECT_NEAR(l("yd"), 0.0277777778, 1e-4);
//    EXPECT_NEAR(l("dyd"), 0.0277899e1, 1e-20);
//    EXPECT_NEAR(l("cyd"), 0.0277899e2, 1e-20);
//    EXPECT_NEAR(l("myd"), 0.0277899e3, 1e-20);
//    EXPECT_NEAR(l("μyd"), 0.0277899e6, 1e-20);
//    EXPECT_NEAR(l("nyd"), 0.0277899e9, 1e-20);
//    EXPECT_NEAR(l("pyd"), 0.0277899e12, 1e-20);
//    EXPECT_NEAR(l("fyd"), 0.0277899e15, 1e-20);
//    EXPECT_NEAR(l("ayd"), 0.0277899e18, 1e-20);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_mass_g_to_oz_lb_t){
    munits::Quantity m (munits::Mass, 1, "g");

    EXPECT_NEAR(m("oz"), 0.0352, 1e-4);
    EXPECT_NEAR(m("lb"), 0.0022, 1e-4);
    EXPECT_EQ(m("t"), 1e-6);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_mass_g_to_oz_lb_t_233){
    munits::Quantity m (munits::Mass, 2.33, "g");

    EXPECT_NEAR(m("oz"), 0.0821, 1e-4);
    EXPECT_NEAR(m("lb"), 0.00513, 1e-4);
    EXPECT_EQ(m("t"), 2.33e-6);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_time_from_s_to_min){
   munits::Quantity t (munits::Time, 30, "s");
    EXPECT_EQ(t("min"), 0.5);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_time_from_min_to_s){
    munits::Quantity t (munits::Time, 1.0, "min");
    EXPECT_EQ(t("s"), 60);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_time_from_hour_to_s){
    munits::Quantity t (munits::Time, 1.0, "h");
    EXPECT_EQ(t("s"), 3600);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_time_from_s_to_hour){
    munits::Quantity t (munits::Time, 3600, "s");
    EXPECT_EQ(t("h"), 1);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_time_from_d_to_s){
    munits::Quantity t (munits::Time, 1.0, "d");
    EXPECT_EQ(t("s"), 86400.);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_time_from_s_to_d){
    munits::Quantity  t (munits::Time, 43200, "s");
    EXPECT_EQ(t("d"), 0.5);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_time_from_day_to_hour){
    munits::Quantity t (munits::Time, 1, "d");
    EXPECT_EQ(t("h"), 24);
}

TEST_F(TestQuantityBaseUnitConversionNoneSI, test_time_from_hour_to_day){
    munits::Quantity t (munits::Time, 48, "h");
    EXPECT_EQ(t("d"), 2);
}

TEST_F(TestQuantityBaseUnitConversionSI, test_temperature_from_K){
    munits::Quantity t (munits::Temperature, 0.0, "K");
    EXPECT_EQ(t("K"), 0.0);
    EXPECT_EQ(t("°C"), -273.15);
    EXPECT_EQ(t("°F"), -459.67);
}

TEST_F(TestQuantityBaseUnitConversionSI, test_temperature_from_K_233){
    munits::Quantity t (munits::Temperature, 2.33, "K");
    EXPECT_EQ(t("K"), 2.33);
    EXPECT_EQ(t("°C"), -270.82);
    EXPECT_EQ(t("°F"), -455.476);
}

TEST_F(TestQuantityBaseUnitConversionSI, test_temperature_from_C){
    munits::Quantity t (munits::Temperature, -40.0, "°C");
    EXPECT_EQ(t("°C"), -40.0);
    EXPECT_NEAR(t("K"), 233.15, 1e-9);
    EXPECT_NEAR(t("°F"), -40.0, 1e-9);
}

TEST_F(TestQuantityBaseUnitConversionSI, test_temperature_from_F){
    munits::Quantity t (munits::Temperature, -40.0, "°F");
    EXPECT_NEAR(t("K"), 233.15, 1e-9);
    EXPECT_NEAR(t("°C"), -40.0, 1e-9);
}

TEST_F(TestQuantityDerivedUnitConversion, test_convert_velocity_from_mps_to_kmph){
    munits::Quantity v (munits::Velocity, 1.0, "m s-1");
    EXPECT_EQ(v("km h-1"), 3.6);
}

TEST_F(TestQuantityDerivedUnitConversion, test_convert_velocity_from_kmph_to_kmph){
    munits::Quantity v (munits::Velocity, 3.6, "km h-1");
    EXPECT_EQ(v("km h-1"), 3.6);
}

TEST_F(TestQuantityDerivedUnitConversion, test_convert_velocity_from_kmph_to_mps){
    munits::Quantity v (munits::Velocity, 3.6, "km h-1");
    EXPECT_EQ(v("m s-1"), 1.);
}

TEST_F(TestQuantityDerivedUnitConversion, test_convert_velocity_from_miph_to_kmph){
    munits::Quantity v (munits::Velocity, 1., "mi h-1");
    EXPECT_EQ(v("km h-1"), 1.609344);
}

TEST_F(TestQuantityDerivedUnitConversion, test_convert_area_from_inch2_to_yd2){
    munits::Quantity a (munits::Area, 2.33, "inc2");
    EXPECT_NEAR(a("yd2"), 0.00179783951, 1e-4);
}

//TEST_F(TestQuantityDerivedUnitConversion, test_convert_area_from_m2_to_are){
//    munits::Quantity a (munits::Area, 200, "m2");
//    EXPECT_NEAR(a("are"), 2, 1e-3);
//}

//TEST_F(TestQuantityDerivedUnitConversion, test_convert_area_from_acre_to_are){
//    munits::Quantity a (munits::Area, 1, "ac");
//    EXPECT_NEAR(a("are"), 40.4684, 1e-4);
//}

TEST_F(TestQuantityDerivedUnitConversion, test_converting_volume_from_m3_to_in3){
    munits::Quantity v (munits::Volume, 1., "m3");
    EXPECT_NEAR(v("cm3"), 1000000., 1e-6);
    EXPECT_NEAR(v("gal"), 264.1720526372959086633370175, 1e-6);
    EXPECT_NEAR(v("inc3"), 61023.74409473228395275688189, 1e-6);
//    EXPECT_NEAR(v("oz"), 33814.0227, 1e-6);
}

TEST_F(TestQuantityDerivedUnitConversion, test_converting_volumetric_flow_from_m3ph_to){
    munits::Quantity v (munits::VolumetricFlow, 1.0, "m3 h-1");
    EXPECT_NEAR(v("m3 d-1"), 24.0, 1e-6);
    EXPECT_NEAR(v("gal min-1"), 4.402867543954931811055616958, 1e-6);
    EXPECT_NEAR(v("l s-1"), 0.2777777777777777777777777778, 1e-6);
}

TEST_F(TestQuantityDerivedUnitConversion, test_converting_acceleration){
    munits::Quantity a (munits::Acceleration, 1.0, "m s-2");
    EXPECT_EQ(a("inc s-2"), 39.37007874015748031496062992);
    EXPECT_EQ(a("inc ms-2"), 0.00003937007874015748031496062992);
}

TEST_F(TestQuantityDerivedUnitConversion, test_convert_force){
    munits::Quantity f (munits::Force, 1.0, "kg m s-2");
    EXPECT_EQ(f("lb yd s-2"), 2.412061728866277343179999663);
}

TEST_F(TestQuantityDerivedUnitConversion, test_convert_concentration){
    munits::Quantity c (munits::Concentration, 1., "mg l-1");
    EXPECT_NEAR(c("mg dm-3"), 1.0, 1e-6);
    EXPECT_NEAR(c("g m-3"), 1.0, 1e-6);
}

#endif //MUSYS_QUANTITY_TEST_H
