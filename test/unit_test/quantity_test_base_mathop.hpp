#ifndef MUSYS_QUANTITY_TEST_MATHOP_HPP
#define MUSYS_QUANTITY_TEST_MATHOP_HPP

#include "gtest/gtest.h"
#include "../../src/quantity.h"

class TestQuantityBaseUnitsMathOperation : public testing::Test{};

class TestQuantityBaseUnitsCreateDerivedViaMathOperation : public testing::Test{};




// Base unit math operation
TEST_F(TestQuantityBaseUnitsMathOperation, adding_mass_to_mass) {
    munits::Quantity m1 (munits::Mass, 1000., "g");
    munits::Quantity m2 (munits::Mass, 1., "kg");
    munits::Quantity m3 = m1 + m2;

    EXPECT_EQ(m3("g"), 2000.);
}
TEST_F(TestQuantityBaseUnitsMathOperation, multiplaying_length_to_length) {
    munits::Quantity m1 (munits::Length, 1000., "mm");
    munits::Quantity m2 (munits::Length, 1., "m");
    munits::Quantity m3 = m1 * m2;

    EXPECT_NEAR(m3("m2"), 1, 0.0001);
}
TEST_F(TestQuantityBaseUnitsMathOperation, subtract_mass_from_mass_flow){
    munits::Quantity m (munits::Mass, 1, "kg");
    munits::Quantity mp (munits::MassFlow, 2., "kg h-1");

    try{
        auto r = mp - m;
    }catch (std::logic_error & le){
        EXPECT_EQ(le.what(), std::string("Subtraction cannot be performed on different dimensions!"));
    }catch(...){
        FAIL() << "Expected logic error!";
    }
}
TEST_F(TestQuantityBaseUnitsMathOperation, add_volume_to_volumetric_flow){
    munits::Quantity v (munits::Volume, 1, "m3");
    munits::Quantity q (munits::VolumetricFlow, 2., "m3 h-1");

    try{
        auto r = v + q;
    }catch (std::logic_error & le){
        EXPECT_EQ(le.what(), std::string("Addition cannot be performed on different dimensions!"));
    }catch(...){
        FAIL() << "Expected logic error!";
    }
}

TEST_F(TestQuantityBaseUnitsMathOperation, multiplication_with_numeric_type_from_right){
    munits::Quantity m (munits::Mass, 1, "kg");
    auto r = m * 2;

    EXPECT_EQ(r.getMatrixIndex(), munits::Mass);

    EXPECT_EQ(r("kg"), 2.);
}
TEST_F(TestQuantityBaseUnitsMathOperation, multiplication_with_numeric_type_from_left){
    munits::Quantity m (munits::Mass, 1, "kg");
    auto r = 2 * m;

    EXPECT_EQ(r.getMatrixIndex(), munits::Mass);

    EXPECT_EQ(r("kg"), 2.);
}
TEST_F(TestQuantityBaseUnitsMathOperation, division_with_numeric_type_from_right){
    munits::Quantity m (munits::Mass, 1, "kg");
    auto r = m / 2.;

    EXPECT_EQ(r.getMatrixIndex(), munits::Mass);

    EXPECT_EQ(r("kg"), .5);
}
TEST_F(TestQuantityBaseUnitsMathOperation, division_with_zero){
    munits::Quantity m (munits::Mass, 1, "kg");
    try{
        auto r = m / 0;
    }catch (std::overflow_error & le){
        EXPECT_EQ(le.what(), std::string("Divide by zero!"));
    }catch(...){
        FAIL() << "Expected overflow_error";
    }
}
TEST_F(TestQuantityBaseUnitsMathOperation, division_with_zero_quantity){
    munits::Quantity m (munits::Mass, 1, "kg");
    munits::Quantity v (munits::Volume, 1, "m3");
    try{
        auto r = m / v;
    }catch (std::overflow_error & le){
        EXPECT_EQ(le.what(), std::string("Divide by zero!"));
    }catch(...){
        FAIL() << "Expected overflow_error";
    }
}
TEST_F(TestQuantityBaseUnitsMathOperation, _2rt_rootable){
    munits::Quantity a (munits::Area, 4.0, "m2");

    auto l = a.ntrt(2);

    EXPECT_EQ(l.getMatrixIndex(), munits::Length);

    EXPECT_EQ(l("m"), 2.0);
}
TEST_F(TestQuantityBaseUnitsMathOperation, _3rt_rootable){
    munits::Quantity a (munits::Volume, 8.0, "m3");

    auto l = a.ntrt(3);

    EXPECT_EQ(l.getMatrixIndex(), munits::Length);

    EXPECT_EQ(l("m"), 2.0);
}

TEST_F(TestQuantityBaseUnitsMathOperation, _3rt_not_rootable){
    munits::Quantity a (munits::Velocity, 8.0, "m s-1");

    try {
        auto l = a.ntrt(3);
        FAIL() << "Exception was not raised";
    }catch (std::logic_error & le){
        EXPECT_EQ(le.what(), std::string("Cannot perform 3th root on 8 m s-1!"));
    }catch(...){
        FAIL() << "Expected logic_error";
    }
}

//Create derived via math operation

TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, creat_acceleration_from_l_t_zero_1) {
    munits::Quantity l (munits::Length, 0, "m");
    munits::Quantity t (munits::Time, 1, "s");
    munits::Quantity a1 = l / (t * t);

    EXPECT_EQ(a1.getMatrixIndex(), munits::Acceleration);

    EXPECT_EQ(a1("m s-2"), 0.);

}

TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_acceleration_from_l_t_none_zero_2){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity t (munits::Time, 2.33, "s");
    munits::Quantity a2 = l / t.mpow( 2);

    EXPECT_EQ(a2.getMatrixIndex(), munits::Acceleration);

    EXPECT_NEAR(a2("m s-2"), 0.4229, 1e-2);
}

TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation,  create_acceleration_from_l_t_none_zero_3){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity t (munits::Time, 2.33, "s");
    munits::Quantity a3 = l / t / t;

    EXPECT_EQ(a3.getMatrixIndex(), munits::Acceleration);

    EXPECT_NEAR(a3("m s-2"), 0.4229, 1e-2);
}


TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_acceleration_from_l_t_zero_2) {
    munits::Quantity l (munits::Length, 0, "m");
    munits::Quantity t (munits::Time, 1, "s");
    munits::Quantity a2 = l / t.mpow(2);

    EXPECT_EQ(a2.getMatrixIndex(), munits::Acceleration);

    EXPECT_EQ(a2("m s-2"), 0.);

}
TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_acceleration_from_l_t_zero_3) {
    munits::Quantity l (munits::Length, 0, "m");
    munits::Quantity t (munits::Time, 1, "s");
    munits::Quantity a3 = l / t / t;

    EXPECT_EQ(a3.getMatrixIndex(), munits::Acceleration);

    EXPECT_EQ(a3("m s-2"), 0.);
}
TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_acceleration_from_l_t_1) {
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity t (munits::Time, 1, "s");

    munits::Quantity a1 = l / (t * t);

    EXPECT_EQ(a1.getMatrixIndex(), munits::Acceleration);

    EXPECT_EQ(a1("m s-2"), 1.);
}
TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_acceleration_from_l_t_2) {
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity t (munits::Time, 1, "s");

    munits::Quantity a2 = l / t.mpow(2);

    EXPECT_EQ(a2.getMatrixIndex(), munits::Acceleration);

    EXPECT_EQ(a2("m s-2"), 1.);
}
TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_acceleration_from_l_t_3) {
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity t (munits::Time, 1, "s");

    munits::Quantity a3 = l / t / t;

    EXPECT_EQ(a3.getMatrixIndex(), munits::Acceleration);

    EXPECT_EQ(a3("m s-2"), 1.);
}
TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_acceleration_from_l_t_none_zero_1){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity t (munits::Time, 2.33, "s");
    munits::Quantity a1 = l / (t * t);

    EXPECT_EQ(a1.getMatrixIndex(), munits::Acceleration);

    EXPECT_NEAR(a1("m s-2"), 0.4229, 1e-2);
}

TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_volumetricflow_one_1){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity v1 = l * l * l;
    munits::Quantity t (munits::Time, 1, "h");

    munits::Quantity vf1 = v1 / t;

    EXPECT_EQ(vf1.getMatrixIndex(), munits::VolumetricFlow);

    EXPECT_EQ(vf1("m3 h-1"),1.);
}

TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_volumetricflow_one_2){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity v2 = l.mpow(3);
    munits::Quantity t (munits::Time, 1, "h");

    munits::Quantity vf2 = v2 / t;

    EXPECT_EQ(vf2.getMatrixIndex(), munits::VolumetricFlow);

    EXPECT_EQ(vf2("m3 h-1"),1.);
}

TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_volumetricflow_one_3){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity t (munits::Time, 1, "h");

    munits::Quantity vf3 = l * l * l / t;

    EXPECT_EQ(vf3.getMatrixIndex(), munits::VolumetricFlow);

    EXPECT_EQ(vf3("m3 h-1"),1.);
}

TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_volumetricflow_233_1){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity l1 = l * l * l;
    munits::Quantity t (munits::Time, 2.33, "h");
    munits::Quantity vf1 = l1 / t;

    EXPECT_EQ(vf1.getMatrixIndex(), munits::VolumetricFlow);

    EXPECT_NEAR(vf1("m3 h-1"), 5.4289, 1e-3);
}

TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_molar_concentration_from_n_l_v_zero_1){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity n (munits::AmountOfSubstance, 0, "mol");
    munits::Quantity mc1 = n / (l * l * l);

    EXPECT_EQ(mc1.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc1("mol m-3"), 0.);
}
TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_molar_concentration_from_n_l_v_zero_2){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity n (munits::AmountOfSubstance, 0, "mol");
    munits::Quantity mc2 = n / l.mpow(3);

    EXPECT_EQ(mc2.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc2("mol m-3"), 0.);
}
TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_molar_concentration_from_n_l_v_zero_3){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity n (munits::AmountOfSubstance, 0, "mol");
    munits::Quantity mc3 = n / l / l / l;

    EXPECT_EQ(mc3.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc3("mol m-3"), 0.);
}

TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_molar_concentration_from_n_l_v_1){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc1 = n / (l * l * l);

    EXPECT_EQ(mc1.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc1("mol m-3"), 1.);
}
TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, creat_molar_concentration_from_n_l_v_2){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc2 = n / l.mpow(3);

    EXPECT_EQ(mc2.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc2("mol m-3"), 1.);
}
TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_molar_concentration_from_n_l_v_3){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc3 = n / l / l / l;

    EXPECT_EQ(mc3.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_EQ(mc3("mol m-3"), 1.);
}

TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_molar_concentration_from_n_l_v_233_1){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc1 = n / (l * l * l);

    EXPECT_EQ(mc1.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_NEAR(mc1("mol m-3"), 0.0790, 1e-3);
}
TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, crete_molar_concentration_from_n_l_v_233_2){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc2 = n / l.mpow(3);

    EXPECT_EQ(mc2.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_NEAR(mc2("mol m-3"), 0.0790, 1e-3);
}
TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_molar_concentration_from_n_l_v_233_3){
    munits::Quantity l (munits::Length, 2.33, "m");
    munits::Quantity n (munits::AmountOfSubstance, 1, "mol");
    munits::Quantity mc3 = n / l / l / l;

    EXPECT_EQ(mc3.getMatrixIndex(), munits::MolarConcentration);

    EXPECT_NEAR(mc3("mol m-3"), 0.0790, 1e-3);
}

TEST_F(TestQuantityBaseUnitsCreateDerivedViaMathOperation, create_power_base_units){
    munits::Quantity l (munits::Length, 1, "m");
    munits::Quantity m (munits::Mass, 2.33, "kg");
    munits::Quantity t (munits::Time, 1, "s");
    munits::Quantity p = m * l * l / t /t /t ;

    EXPECT_EQ(p.getMatrixIndex(), munits::Power);

    EXPECT_NEAR(p("W"), 2.33, 1e-3);
}




#endif //MUSYS_QUANTITY_TEST_MATHOP_HPP
