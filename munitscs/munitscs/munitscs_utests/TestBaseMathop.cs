using System;
using NUnit.Framework;
using munitscs;

namespace munitscs_utests
{
    [TestFixture]
    public class TestBaseMathop
    {
        [Test]
        public void adding_mass_to_mass()
        {
            Quantity m1 = new Quantity(Metrics.Mass, 1000d, "g");
            Quantity m2 = new Quantity(Metrics.Mass, 1d, "kg");
            Quantity m3 = m1 + m2;

            Assert.AreEqual(m3.Get("g"), 2000d);
        }

    [Test]
     public void multiplaying_length_to_length() {
        Quantity m1 = new Quantity(Metrics.Length, 1000d, "mm");
        Quantity m2 = new Quantity(Metrics.Length, 1000d, "mm"); 
        Quantity m3 = m1 * m2;
    
        Assert.AreEqual(m3.Get("m2"), 1, 0.0001);
    }

    [Test]
     public void multiplication_with_numeric_type_from_right(){
        Quantity m = new Quantity(Metrics.Mass, 1, "kg");
        Quantity r = m * 2;
    
//        Assert.AreEqual(r.getMatrixIndex(), Metrics.Mass);
    
        Assert.AreEqual(r.Get("kg"), 2d);
    }
    [Test]
     public void multiplication_with_numeric_type_from_left(){
        Quantity m = new Quantity(Metrics.Mass, 1, "kg");
        Quantity r = 2 * m;
    
//        Assert.AreEqual(r.getMatrixIndex(), Metrics.Mass);
    
        Assert.AreEqual(r.Get("kg"), 2d);
    }
    [Test]
    public void division_with_numeric_type_from_right(){
    Quantity m = new Quantity(Metrics.Mass, 1, "kg");
    Quantity r = m / 2d;
    
//    Assert.AreEqual(r.getMatrixIndex(), Metrics.Mass);
    
    Assert.AreEqual(r.Get("kg"), .5);
    }
    [Test]
     public void _2rt_rootable(){
        Quantity a = new Quantity(Metrics.Area, 4.0, "m2");
        Quantity l = a.Root(2);
    
//        Assert.AreEqual(l.getMatrixIndex(), Metrics.Length);
    
        Assert.AreEqual(l.Get("m"), 2.0);
    }
    [Test]
    public void _3rt_rootable(){
        Quantity a = new Quantity(Metrics.Volume, 8.0, "m3");
        
        Quantity l = a.Root(3);
        
    //    Assert.AreEqual(l.getMatrixIndex(), Metrics.Length);
        
        Assert.AreEqual(l.Get("m"), 2.0);
    }
    
    [Test]
     public void _3rt_not_rootable(){
        Quantity a = new Quantity(Metrics.Velocity, 8.0, "m s-1");
        Assert.Throws<System.Runtime.InteropServices.SEHException>(() => a.Root(3));
    }
    //
    ////Create derived via math operation
    //
    //[Test]
    // public void creat_acceleration_from_l_t_zero_1) {
    //    Quantity l = new Quantity(Metrics.Length, 0, "m");
    //    Quantity t = new Quantity(Metrics.Time, 1, "s");
    //    Quantity a1 = l / (t * t);
    //
    //    Assert.AreEqual(a1.getMatrixIndex(), Metrics.Acceleration);
    //
    //    Assert.AreEqual(a1("m s-2"), 0d);
    //
    //}
    //
    //[Test]
    // public void create_acceleration_from_l_t_none_zero_2){
    //    Quantity l = new Quantity(Metrics.Length, 2.33, "m");
    //    Quantity t = new Quantity(Metrics.Time, 2.33, "s");
    //    Quantity a2 = l / pow(t, 2);
    //
    //    Assert.AreEqual(a2.getMatrixIndex(), Metrics.Acceleration);
    //
    //    EXPECT_NEAR(a2("m s-2"), 0.4229, 1e-2);
    //}
    //
    //[Test]
    // public void  create_acceleration_from_l_t_none_zero_3){
    //    Quantity l = new Quantity(Metrics.Length, 2.33, "m");
    //    Quantity t = new Quantity(Metrics.Time, 2.33, "s");
    //    Quantity a3 = l / t / t;
    //
    //    Assert.AreEqual(a3.getMatrixIndex(), Metrics.Acceleration);
    //
    //    EXPECT_NEAR(a3("m s-2"), 0.4229, 1e-2);
    //}
    //
    //
    //[Test]
    // public void create_acceleration_from_l_t_zero_2) {
    //    Quantity l = new Quantity(Metrics.Length, 0, "m");
    //    Quantity t = new Quantity(Metrics.Time, 1, "s");
    //    Quantity a2 = l /  pow(t, 2);
    //
    //    Assert.AreEqual(a2.getMatrixIndex(), Metrics.Acceleration);
    //
    //    Assert.AreEqual(a2("m s-2"), 0d);
    //
    //}
    //[Test]
    // public void create_acceleration_from_l_t_zero_3) {
    //    Quantity l = new Quantity(Metrics.Length, 0, "m");
    //    Quantity t = new Quantity(Metrics.Time, 1, "s");
    //    Quantity a3 = l / t / t;
    //
    //    Assert.AreEqual(a3.getMatrixIndex(), Metrics.Acceleration);
    //
    //    Assert.AreEqual(a3("m s-2"), 0d);
    //}
    //[Test]
    // public void create_acceleration_from_l_t_1) {
    //    Quantity l = new Quantity(Metrics.Length, 1, "m");
    //    Quantity t = new Quantity(Metrics.Time, 1, "s");
    //
    //    Quantity a1 = l / (t * t);
    //
    //    Assert.AreEqual(a1.getMatrixIndex(), Metrics.Acceleration);
    //
    //    Assert.AreEqual(a1("m s-2"), 1d);
    //}
    //[Test]
    // public void create_acceleration_from_l_t_2) {
    //    Quantity l = new Quantity(Metrics.Length, 1, "m");
    //    Quantity t = new Quantity(Metrics.Time, 1, "s");
    //
    //    Quantity a2 = l / pow(t, 2);
    //
    //    Assert.AreEqual(a2.getMatrixIndex(), Metrics.Acceleration);
    //
    //    Assert.AreEqual(a2("m s-2"), 1d);
    //}
    //[Test]
    // public void create_acceleration_from_l_t_3) {
    //    Quantity l = new Quantity(Metrics.Length, 1, "m");
    //    Quantity t = new Quantity(Metrics.Time, 1, "s");
    //
    //    Quantity a3 = l / t / t;
    //
    //    Assert.AreEqual(a3.getMatrixIndex(), Metrics.Acceleration);
    //
    //    Assert.AreEqual(a3("m s-2"), 1d);
    //}
    //[Test]
    // public void create_acceleration_from_l_t_none_zero_1){
    //    Quantity l = new Quantity(Metrics.Length, 2.33, "m");
    //    Quantity t = new Quantity(Metrics.Time, 2.33, "s");
    //    Quantity a1 = l / (t * t);
    //
    //    Assert.AreEqual(a1.getMatrixIndex(), Metrics.Acceleration);
    //
    //    EXPECT_NEAR(a1("m s-2"), 0.4229, 1e-2);
    //}
    //
    //[Test]
    // public void create_volumetricflow_one_1){
    //    Quantity l = new Quantity(Metrics.Length, 1, "m");
    //    Quantity v1 = l * l * l;
    //    Quantity t = new Quantity(Metrics.Time, 1, "h");
    //
    //    Quantity vf1 = v1 / t;
    //
    //    Assert.AreEqual(vf1.getMatrixIndex(), Metrics.VolumetricFlow);
    //
    //    Assert.AreEqual(vf1("m3 h-1"),1.);
    //}
    //
    //[Test]
    // public void create_volumetricflow_one_2){
    //    Quantity l = new Quantity(Metrics.Length, 1, "m");
    //    Quantity v2 = Metrics.pow(l, 3);
    //    Quantity t = new Quantity(Metrics.Time, 1, "h");
    //
    //    Quantity vf2 = v2 / t;
    //
    //    Assert.AreEqual(vf2.getMatrixIndex(), Metrics.VolumetricFlow);
    //
    //    Assert.AreEqual(vf2("m3 h-1"),1d);
    //}
    //
    //[Test]
    // public void create_volumetricflow_one_3){
    //    Quantity l = new Quantity(Metrics.Length, 1, "m");
    //    Quantity t = new Quantity(Metrics.Time, 1, "h");
    //
    //    Quantity vf3 = l * l * l / t;
    //
    //    Assert.AreEqual(vf3.getMatrixIndex(), Metrics.VolumetricFlow);
    //
    //    Assert.AreEqual(vf3("m3 h-1"),1d);
    //}
    //
    //[Test]
    // public void create_volumetricflow_233_1){
    //    Quantity l = new Quantity(Metrics.Length, 2.33, "m");
    //    Quantity l1 = l * l * l;
    //    Quantity t = new Quantity(Metrics.Time, 2.33, "h");
    //    Quantity vf1 = l1 / t;
    //
    //    Assert.AreEqual(vf1.getMatrixIndex(), Metrics.VolumetricFlow);
    //
    //    EXPECT_NEAR(vf1("m3 h-1"), 5.4289, 1e-3);
    //}
    //
    //[Test]
    // public void create_molar_concentration_from_n_l_v_zero_1){
    //    Quantity l = new Quantity(Metrics.Length, 1, "m");
    //    Quantity n = new Quantity(Metrics.AmountOfSubstance, 0, "mol");
    //    Quantity mc1 = n / (l * l * l);
    //
    //    Assert.AreEqual(mc1.getMatrixIndex(), Metrics.MolarConcentration);
    //
    //    Assert.AreEqual(mc1("mol m-3"), 0d);
    //}
    //[Test]
    // public void create_molar_concentration_from_n_l_v_zero_2){
    //    Quantity l = new Quantity(Metrics.Length, 1, "m");
    //    Quantity n = new Quantity(Metrics.AmountOfSubstance, 0, "mol");
    //    Quantity mc2 = n / Metrics.pow(l, 3);
    //
    //    Assert.AreEqual(mc2.getMatrixIndex(), Metrics.MolarConcentration);
    //
    //    Assert.AreEqual(mc2("mol m-3"), 0d);
    //}
    //[Test]
    // public void create_molar_concentration_from_n_l_v_zero_3){
    //    Quantity l = new Quantity(Metrics.Length, 1, "m");
    //    Quantity n = new Quantity(Metrics.AmountOfSubstance, 0, "mol");
    //    Quantity mc3 = n / l / l / l;
    //
    //    Assert.AreEqual(mc3.getMatrixIndex(), Metrics.MolarConcentration);
    //
    //    Assert.AreEqual(mc3("mol m-3"), 0d);
    //}
    //
    //[Test]
    // public void create_molar_concentration_from_n_l_v_1){
    //    Quantity l = new Quantity(Metrics.Length, 1, "m");
    //    Quantity n = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
    //    Quantity mc1 = n / (l * l * l);
    //
    //    Assert.AreEqual(mc1.getMatrixIndex(), Metrics.MolarConcentration);
    //
    //    Assert.AreEqual(mc1("mol m-3"), 1d);
    //}
    //[Test]
    // public void creat_molar_concentration_from_n_l_v_2){
    //    Quantity l = new Quantity(Metrics.Length, 1, "m");
    //    Quantity n = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
    //    Quantity mc2 = n / Metrics.pow(l,3);
    //
    //    Assert.AreEqual(mc2.getMatrixIndex(), Metrics.MolarConcentration);
    //
    //    Assert.AreEqual(mc2("mol m-3"), 1d);
    //}
    //[Test]
    // public void create_molar_concentration_from_n_l_v_3){
    //    Quantity l = new Quantity(Metrics.Length, 1, "m");
    //    Quantity n = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
    //    Quantity mc3 = n / l / l / l;
    //
    //    Assert.AreEqual(mc3.getMatrixIndex(), Metrics.MolarConcentration);
    //
    //    Assert.AreEqual(mc3("mol m-3"), 1d);
    //}
    //
    //[Test]
    // public void create_molar_concentration_from_n_l_v_233_1){
    //    Quantity l = new Quantity(Metrics.Length, 2.33, "m");
    //    Quantity n = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
    //    Quantity mc1 = n / (l * l * l);
    //
    //    Assert.AreEqual(mc1.getMatrixIndex(), Metrics.MolarConcentration);
    //
    //    EXPECT_NEAR(mc1("mol m-3"), 0.0790, 1e-3);
    //}
    //[Test]
    // public void crete_molar_concentration_from_n_l_v_233_2){
    //    Quantity l = new Quantity(Metrics.Length, 2.33, "m");
    //    Quantity n = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
    //    Quantity mc2 = n / Metrics.pow(l, 3);
    //
    //    Assert.AreEqual(mc2.getMatrixIndex(), Metrics.MolarConcentration);
    //
    //    EXPECT_NEAR(mc2("mol m-3"), 0.0790, 1e-3);
    //}
    //[Test]
    // public void create_molar_concentration_from_n_l_v_233_3){
    //    Quantity l = new Quantity(Metrics.Length, 2.33, "m");
    //    Quantity n = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
    //    Quantity mc3 = n / l / l / l;
    //
    //    Assert.AreEqual(mc3.getMatrixIndex(), Metrics.MolarConcentration);
    //
    //    EXPECT_NEAR(mc3("mol m-3"), 0.0790, 1e-3);
    //}
    //
    //[Test]
    // public void create_power_base_units){
    //    Quantity l = new Quantity(Metrics.Length, 1, "m");
    //    Quantity m = new Quantity(Metrics.Mass, 2.33, "kg");
    //    Quantity t = new Quantity(Metrics.Time, 1, "s");
    //    Quantity p = m * l * l / t /t /t ;
    //
    //    Assert.AreEqual(p.getMatrixIndex(), Metrics.Power);
    //
    //    EXPECT_NEAR(p("W"), 2.33, 1e-3);
    //}
    //
    //        
        
    }
}
