
#ifndef MUSYS_QUANTITY_TEST_H
#define MUSYS_QUANTITY_TEST_H

#include "gtest/gtest.h"
#include "../../quantity.h"

class TestQuantityBaseUnitConversion : public testing::Test{};

TEST_F(TestQuantityBaseUnitConversion, test_length_zero){
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
TEST_F(TestQuantityBaseUnitConversion, test_length_one){
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

TEST_F(TestQuantityBaseUnitConversion, test_lengt233){
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

TEST_F(TestQuantityBaseUnitConversion, test_mass_zero){
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
TEST_F(TestQuantityBaseUnitConversion, test_mass_one){
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
TEST_F(TestQuantityBaseUnitConversion, test_mass_233){
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

#endif //MUSYS_QUANTITY_TEST_H
