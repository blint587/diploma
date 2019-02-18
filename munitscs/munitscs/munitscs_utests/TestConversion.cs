using System;
using munitscs;
using NUnit.Framework;


namespace munitscs_utests
{
    [TestFixture]
    public class TestConversion
    {
        
    [Test]
    public void test_length_zero(){
        Quantity l = new Quantity(Metrics.Length, 0, "m");
    
        Assert.AreEqual(l.Get("Em"), 0d);
        Assert.AreEqual(l.Get("Pm"), 0d);
        Assert.AreEqual(l.Get("Tm"), 0d);
        Assert.AreEqual(l.Get("Gm"), 0d);
        Assert.AreEqual(l.Get("Mm"), 0d);
        Assert.AreEqual(l.Get("km"), 0d);
        Assert.AreEqual(l.Get("hm"), 0d);
        Assert.AreEqual(l.Get("dam"), 0d);
        Assert.AreEqual(l.Get("m"), 0d);
        Assert.AreEqual(l.Get("dm"), 0d);
        Assert.AreEqual(l.Get("cm"), 0d);
        Assert.AreEqual(l.Get("mm"), 0d);
        Assert.AreEqual(l.Get("μm"), 0d);
        Assert.AreEqual(l.Get("nm"), 0d);
        Assert.AreEqual(l.Get("pm"), 0d);
        Assert.AreEqual(l.Get("fm"), 0d);
        Assert.AreEqual(l.Get("am"), 0d);
    }
    
    [Test]
    public void test_length_one(){
        Quantity l = new Quantity(Metrics.Length, 1, "m");
    
        Assert.AreEqual(l.Get("Em"), 1e-18);
        Assert.AreEqual(l.Get("Pm"), 1e-15);
        Assert.AreEqual(l.Get("Tm"), 1e-12);
        Assert.AreEqual(l.Get("Gm"), 1e-9);
        Assert.AreEqual(l.Get("Mm"), 1e-6);
        Assert.AreEqual(l.Get("km"), 1e-3);
        Assert.AreEqual(l.Get("hm"), 1e-2);
        Assert.AreEqual(l.Get("dam"), 0.1);
        Assert.AreEqual(l.Get("m"), 1);
        Assert.AreEqual(l.Get("dm"), 10d);
        Assert.AreEqual(l.Get("cm"), 100d, 1e-2);
        Assert.AreEqual(l.Get("mm"), 1000d, 1e-2);
        Assert.AreEqual(l.Get("μm"), 1e6, 1);
        Assert.AreEqual(l.Get("nm"), 1e9, 1e-2);
        Assert.AreEqual(l.Get("pm"), 1e12, 1e-2);
        Assert.AreEqual(l.Get("fm"), 1e15, 1.7);
        Assert.AreEqual(l.Get("am"), 1e18, 1792);
    }
    
    [Test]
    public void test_lengt233(){
        Quantity l = new Quantity(Metrics.Length, 2.33, "m");
    
        Assert.AreEqual(l.Get("Em"), 2.33e-18, 4e-34);
        Assert.AreEqual(l.Get("Pm"), 2.33e-15, 4e-31);
        Assert.AreEqual(l.Get("Tm"), 2.33e-12);
        Assert.AreEqual(l.Get("Gm"), 2.33e-9);
        Assert.AreEqual(l.Get("Mm"), 2.33e-6);
        Assert.AreEqual(l.Get("km"), 2.33e-3);
        Assert.AreEqual(l.Get("hm"), 2.33e-2);
        Assert.AreEqual(l.Get("dam"), 2.33e-1);
        Assert.AreEqual(l.Get("m"), 2.33);
        Assert.AreEqual(l.Get("dm"), 23.3);
        Assert.AreEqual(l.Get("cm"), 233d, 0.01);
        Assert.AreEqual(l.Get("mm"), 2330d, 0.01);
        Assert.AreEqual(l.Get("μm"), 2.33e6, 0.01);
        Assert.AreEqual(l.Get("nm"), 2.33e9, 1e-2);
        Assert.AreEqual(l.Get("pm"), 2.33e12, 1e-2);
        Assert.AreEqual(l.Get("fm"), 2.33e15, 3.5);
        Assert.AreEqual(l.Get("am"), 2.33e18, 4096);
    
    }
    
    [Test]
    public void test_mass_zero(){
        Quantity l = new Quantity(Metrics.Mass, 0, "g");
    
        Assert.AreEqual(l.Get("Eg"), 0d);
        Assert.AreEqual(l.Get("Pg"), 0d);
        Assert.AreEqual(l.Get("Tg"), 0d);
        Assert.AreEqual(l.Get("Gg"), 0d);
        Assert.AreEqual(l.Get("Mg"), 0d);
        Assert.AreEqual(l.Get("kg"), 0d);
        Assert.AreEqual(l.Get("hg"), 0d);
        Assert.AreEqual(l.Get("dag"), 0d);
        Assert.AreEqual(l.Get("g"), 0d);
        Assert.AreEqual(l.Get("dg"), 0d);
        Assert.AreEqual(l.Get("cg"), 0d);
        Assert.AreEqual(l.Get("mg"), 0d);
        Assert.AreEqual(l.Get("μg"), 0d);
        Assert.AreEqual(l.Get("ng"), 0d, 1e-2);
        Assert.AreEqual(l.Get("pg"), 0d, 1e-2);
        Assert.AreEqual(l.Get("fg"), 0d, 1);
        Assert.AreEqual(l.Get("ag"), 0d, 128);
    }
    
    [Test]
    public void test_mass_one(){
        Quantity l = new Quantity(Metrics.Mass, 1, "g");
    
        Assert.AreEqual(l.Get("Eg"), 1e-18);
        Assert.AreEqual(l.Get("Pg"), 1e-15);
        Assert.AreEqual(l.Get("Tg"), 1e-12);
        Assert.AreEqual(l.Get("Gg"), 1e-9);
        Assert.AreEqual(l.Get("Mg"), 1e-6);
        Assert.AreEqual(l.Get("kg"), 1e-3);
        Assert.AreEqual(l.Get("hg"), 1e-2);
        Assert.AreEqual(l.Get("dag"), 0.1);
        Assert.AreEqual(l.Get("g"), 1);
        Assert.AreEqual(l.Get("dg"), 10d);
        Assert.AreEqual(l.Get("cg"), 100d, 0.01);
        Assert.AreEqual(l.Get("mg"), 1000d, 0.01);
        Assert.AreEqual(l.Get("μg"), 1e6, 0.01);
        Assert.AreEqual(l.Get("ng"), 1e9, 1e-2);
        Assert.AreEqual(l.Get("pg"), 1e12, 1e-2);
        Assert.AreEqual(l.Get("fg"), 1e15, 1.625);
        Assert.AreEqual(l.Get("ag"), 1e18, 1792);
    }
    
    [Test]
    public void test_mass_233(){
        Quantity l = new Quantity(Metrics.Mass, 2.33, "g");
    
        Assert.AreEqual(l.Get("Eg"), 2.33e-18, 4e-34);
        Assert.AreEqual(l.Get("Pg"), 2.33e-15, 4e-31);
        Assert.AreEqual(l.Get("Tg"), 2.33e-12);
        Assert.AreEqual(l.Get("Gg"), 2.33e-9);
        Assert.AreEqual(l.Get("Mg"), 2.33e-6);
        Assert.AreEqual(l.Get("kg"), 2.33e-3);
        Assert.AreEqual(l.Get("hg"), 2.33e-2);
        Assert.AreEqual(l.Get("dag"), 0.233);
        Assert.AreEqual(l.Get("g"), 2.33);
        Assert.AreEqual(l.Get("dg"), 23.3);
        Assert.AreEqual(l.Get("cg"), 233d, 0.01);
        Assert.AreEqual(l.Get("mg"), 2330d, 0.01);
        Assert.AreEqual(l.Get("μg"), 2.33e6, 0.01);
        Assert.AreEqual(l.Get("ng"), 2.33e9, 1e-2);
        Assert.AreEqual(l.Get("pg"), 2.33e12, 1e-2);
        Assert.AreEqual(l.Get("fg"), 2.33e15, 3.5);
        Assert.AreEqual(l.Get("ag"), 2.33e18, 4096);
    }
    
    [Test]
    public void test_time_zero() {
        Quantity t = new Quantity(Metrics.Time, 0.0, "s");
    
        Assert.AreEqual(t.Get("ms"), 0);
        Assert.AreEqual(t.Get("μs"), 0);
        Assert.AreEqual(t.Get("ns"), 0);
        Assert.AreEqual(t.Get("ps"), 0);
        Assert.AreEqual(t.Get("fs"), 0);
        Assert.AreEqual(t.Get("as"), 0);
        Assert.AreEqual(t.Get("min"), 0);
        Assert.AreEqual(t.Get("d"), 0);
        Assert.AreEqual(t.Get("h"), 0);
    
    }
    
    [Test]
    public void test_time_one(){
    
        Quantity t = new Quantity(Metrics.Time, 1.0, "s");
    
        Assert.AreEqual(t.Get("ms"), 1000d, 0.01);
        Assert.AreEqual(t.Get("μs"), 1e6, 0.01);
        Assert.AreEqual(t.Get("ns"), 1e9, 1e-2);
        Assert.AreEqual(t.Get("ps"), 1e12, 1e-2);
        Assert.AreEqual(t.Get("fs"), 1e15, 1.625);
        Assert.AreEqual(t.Get("as"), 1e18, 1793);
        Assert.AreEqual(t.Get("min"), 1d/60);
        Assert.AreEqual(t.Get("h"), 1d/60/60);
        Assert.AreEqual(t.Get("d"), 1d/60/60/24);
    
     }
    
    [Test]
    public void test_time_233() {
        Quantity t = new Quantity(Metrics.Time, 2.33, "s");
    
        Assert.AreEqual(t.Get("ms"), 2330d, 0.01);
        Assert.AreEqual(t.Get("μs"), 2.33e6, 0.01);
        Assert.AreEqual(t.Get("ns"), 2.33e9, 0.01);
        Assert.AreEqual(t.Get("ps"), 2.33e12, 0.01);
        Assert.AreEqual(t.Get("fs"), 2.33e15, 3.5);
        Assert.AreEqual(t.Get("as"), 2.33e18, 4096);
        Assert.AreEqual(t.Get("min"), 2.33/60, 1e-17);
        Assert.AreEqual(t.Get("h"), 2.33/60/60, 1e-17);
        Assert.AreEqual(t.Get("d"), 2.33/60/60/24, 1e-17);
    
    }
    
    [Test]
    public void test_electric_currency_zero() {
        Quantity i = new Quantity(Metrics.ElectricCurrency, 0, "A");
    
        Assert.AreEqual(i.Get("EA"), 0);
        Assert.AreEqual(i.Get("PA"), 0);
        Assert.AreEqual(i.Get("TA"), 0);
        Assert.AreEqual(i.Get("GA"), 0);
        Assert.AreEqual(i.Get("MA"), 0);
        Assert.AreEqual(i.Get("kA"), 0);
        Assert.AreEqual(i.Get("hA"), 0);
        Assert.AreEqual(i.Get("daA"), 0);
        Assert.AreEqual(i.Get("A"), 0);
        Assert.AreEqual(i.Get("dA"), 0);
        Assert.AreEqual(i.Get("cA"), 0);
        Assert.AreEqual(i.Get("mA"), 0);
        Assert.AreEqual(i.Get("μA"), 0);
        Assert.AreEqual(i.Get("nA"), 0);
        Assert.AreEqual(i.Get("pA"), 0);
        Assert.AreEqual(i.Get("fA"), 0);
        Assert.AreEqual(i.Get("aA"), 0);
    }
    
    [Test]
    public void test_electric_currency_one() {
        Quantity i = new Quantity(Metrics.ElectricCurrency, 1, "A");
    
        Assert.AreEqual(i.Get("EA"), 1e-18);
        Assert.AreEqual(i.Get("PA"), 1e-15);
        Assert.AreEqual(i.Get("TA"), 1e-12);
        Assert.AreEqual(i.Get("GA"), 1e-9);
        Assert.AreEqual(i.Get("MA"), 1e-6);
        Assert.AreEqual(i.Get("kA"), 1e-3);
        Assert.AreEqual(i.Get("hA"), 1e-2);
        Assert.AreEqual(i.Get("daA"), 1e-1);
        Assert.AreEqual(i.Get("A"), 1d);
        Assert.AreEqual(i.Get("dA"), 10d);
        Assert.AreEqual(i.Get("cA"), 100d, 1e-2);
        Assert.AreEqual(i.Get("mA"), 1000d, 1e-2);
        Assert.AreEqual(i.Get("μA"), 1e6, 1e-2);
        Assert.AreEqual(i.Get("nA"), 1e9, 1e-2);
        Assert.AreEqual(i.Get("pA"), 1e12, 1e-2);
        Assert.AreEqual(i.Get("fA"), 1e15, 1.625);
        Assert.AreEqual(i.Get("aA"), 1e18, 1792);
    }
    
    [Test]
    public void test_electric_currency_233(){
    
        Quantity i = new Quantity(Metrics.ElectricCurrency, 2.33, "A");
    
        Assert.AreEqual(i.Get("EA"), 2.33e-18, 4e-34);
        Assert.AreEqual(i.Get("PA"), 2.33e-15, 4e-31);
        Assert.AreEqual(i.Get("TA"), 2.33e-12);
        Assert.AreEqual(i.Get("GA"), 2.33e-9);
        Assert.AreEqual(i.Get("MA"), 2.33e-6);
        Assert.AreEqual(i.Get("kA"), 2.33e-3);
        Assert.AreEqual(i.Get("hA"), 2.33e-2);
        Assert.AreEqual(i.Get("daA"), 2.33e-1);
        Assert.AreEqual(i.Get("A"), 2.33);
        Assert.AreEqual(i.Get("dA"), 23.3);
        Assert.AreEqual(i.Get("cA"), 233d, 1e-2);
        Assert.AreEqual(i.Get("mA"), 2330d, 1e-2);
        Assert.AreEqual(i.Get("μA"), 2.33e6, 1e-2);
        Assert.AreEqual(i.Get("nA"), 2.33e9, 1e-2);
        Assert.AreEqual(i.Get("pA"), 2.33e12, 1e-2);
        Assert.AreEqual(i.Get("fA"), 2.33e15, 3.5);
        Assert.AreEqual(i.Get("aA"), 2.33e18, 4096);
    }
    
    [Test]
    public void test_aos_one(){
       Quantity n = new Quantity(Metrics.AmountOfSubstance, 1.0, "kmol");
    
        Assert.AreEqual(n.Get("mol"), 1000.0);
    }
    
    
    // NONE SI
    
    [Test]
    public void test_si_length_m_to_in_ft_mi() {
       Quantity l = new Quantity(Metrics.Length, 1, "m");
    
        Assert.AreEqual(l.Get("inc"), 39.37, 1e-4);
        Assert.AreEqual(l.Get("ft"), 3.2808, 1e-4);
        Assert.AreEqual(l.Get("mi"), 0.000621, 1e-4);
        Assert.AreEqual(l.Get("yd"), 1.0940919037199124, 1e-4);
    }
    
    [Test]
    public void test_si_length_m_to_in_ft_mi_233(){
        Quantity l = new Quantity(Metrics.Length, 2.33, "m");
    
        Assert.AreEqual(l.Get("inc"), 91.7322, 1e-4);
        Assert.AreEqual(l.Get("ft"), 7.6443, 1e-4);
        Assert.AreEqual(l.Get("mi"), 0.00144, 1e-4);
        Assert.AreEqual(l.Get("yd"), 2.5492341356673958, 1e-4);
    }
    
    [Test]
    public void test_none_si_length_inch_to_ft_mi(){
        Quantity l = new Quantity(Metrics.Length, 1, "inc");
    
        Assert.AreEqual(l.Get("ft"), 0.0833, 1e-2);
        Assert.AreEqual(l.Get("mi"), 1.578e-5, 1e-2);
        Assert.AreEqual(l.Get("inc"), 1, 1e-2);
    }
    
    [Test]
    public void test_none_si_length_inch_to_ft_mi_233(){
        Quantity l = new Quantity(Metrics.Length, 2.33, "inc");
    
        Assert.AreEqual(l.Get("ft"), 0.1941, 1e-4);
        Assert.AreEqual(l.Get("mi"), 3.677e-5, 1e-2);
        Assert.AreEqual(l.Get("inc"), 2.33, 1e-2);
    }
    
    [Test]
    public void test_none_si_length_inch_in_to_prefix_m(){
        Quantity l = new Quantity(Metrics.Length, 1, "inc");
    
        Assert.AreEqual(l.Get("Em"), 0.0254e-18);
        Assert.AreEqual(l.Get("Pm"), 0.0254e-15);
        Assert.AreEqual(l.Get("Tm"), 0.0254e-12, 1e-6);
        Assert.AreEqual(l.Get("Gm"), 0.0254e-9);
        Assert.AreEqual(l.Get("Mm"), 0.0254e-6);
        Assert.AreEqual(l.Get("km"), 0.0254e-3);
        Assert.AreEqual(l.Get("hm"), 0.0254e-2);
        Assert.AreEqual(l.Get("dam"), 0.0254e-1);
        Assert.AreEqual(l.Get("m"), 0.0254);
        Assert.AreEqual(l.Get("dm"), 0.0254e1);
        Assert.AreEqual(l.Get("cm"), 0.0254e2, 0.01);
        Assert.AreEqual(l.Get("mm"), 0.0254e3, 0.01);
        Assert.AreEqual(l.Get("μm"), 0.0254e6, 0.01);
        Assert.AreEqual(l.Get("nm"), 0.0254e9, 1e-6);
        Assert.AreEqual(l.Get("pm"), 0.0254e12, 0.01);
        Assert.AreEqual(l.Get("fm"), 0.0254e15, 1);
        Assert.AreEqual(l.Get("am"), 0.0254e18, 1000);
    }
    
    [Test]
    public void test_non_si_length(){
        Quantity l = new Quantity(Metrics.Length, 1, "inc");
        Assert.AreEqual(l.Get("Eyd"), 2.77777778e-20, 1e-22);
        Assert.AreEqual(l.Get("Pyd"), 2.7789934354485774e-17, 1e-20);
        Assert.AreEqual(l.Get("Tyd"), 2.7789934354485771e-14, 1e-18);
        Assert.AreEqual(l.Get("Gyd"), 2.7789934354485776e-11, 1e-14);
        Assert.AreEqual(l.Get("Myd"), 2.7789934354485775e-8, 1e-13);
        Assert.AreEqual(l.Get("kyd"), 2.7789934354485775e-5, 1e-8);
        Assert.AreEqual(l.Get("hyd"), 2.7789934354485773e-4, 1e-7);
        Assert.AreEqual(l.Get("dayd"), 2.7789934354485778e-3, 1e-6);
        Assert.AreEqual(l.Get("yd"), 0.0277777778, 1e-4);
        Assert.AreEqual(l.Get("dyd"), 0.0277899e1, 1e-6);
        Assert.AreEqual(l.Get("cyd"), 0.0277899e2, 1e-5);
        Assert.AreEqual(l.Get("myd"), 0.0277899e3, 1e-4);
        Assert.AreEqual(l.Get("μyd"), 0.0277899e6, 1e-1);
        Assert.AreEqual(l.Get("nyd"), 0.0277899e9, 35);
        Assert.AreEqual(l.Get("pyd"), 0.0277899e12, 35000);
        Assert.AreEqual(l.Get("fyd"), 0.0277899e15, 35000000);
        Assert.AreEqual(l.Get("ayd"), 0.0277899e18, 35000000000);
    }
    
    [Test]
    public void test_mass_g_to_oz_lb_t(){
        Quantity m = new Quantity(Metrics.Mass, 1, "g");
    
        Assert.AreEqual(m.Get("oz"), 0.0352, 1e-4);
        Assert.AreEqual(m.Get("lb"), 0.0022, 1e-4);
        Assert.AreEqual(m.Get("t"), 1e-6);
    }
    
    [Test]
    public void test_mass_g_to_oz_lb_t_233(){
        Quantity m = new Quantity(Metrics.Mass, 2.33, "g");
    
        Assert.AreEqual(m.Get("oz"), 0.0821, 1e-4);
        Assert.AreEqual(m.Get("lb"), 0.00513, 1e-4);
        Assert.AreEqual(m.Get("t"), 2.33e-6);
    }
    
    [Test]
    public void test_time_from_s_to_min(){
       Quantity t = new Quantity(Metrics.Time, 30, "s");
        Assert.AreEqual(t.Get("min"), 0.5);
    }
    
    [Test]
    public void test_time_from_min_to_s(){
        Quantity t = new Quantity(Metrics.Time, 1.0, "min");
        Assert.AreEqual(t.Get("s"), 60);
    }
    
    [Test]
    public void test_time_from_hour_to_s(){
        Quantity t = new Quantity(Metrics.Time, 1.0, "h");
        Assert.AreEqual(t.Get("s"), 3600);
    }
    
    [Test]
    public void test_time_from_s_to_hour(){
        Quantity t = new Quantity(Metrics.Time, 3600, "s");
        Assert.AreEqual(t.Get("h"), 1);
    }
    
    [Test]
    public void test_time_from_d_to_s(){
        Quantity t = new Quantity(Metrics.Time, 1.0, "d");
        Assert.AreEqual(t.Get("s"), 86400d);
    }
    
    [Test]
    public void test_time_from_s_to_d(){
        Quantity t = new Quantity(Metrics.Time, 43200, "s");
        Assert.AreEqual(t.Get("d"), 0.5);
    }
    
    [Test]
    public void test_time_from_day_to_hour(){
        Quantity t = new Quantity(Metrics.Time, 1, "d");
        Assert.AreEqual(t.Get("h"), 24);
    }
    
    [Test]
    public void test_time_from_hour_to_day(){
        Quantity t = new Quantity(Metrics.Time, 48, "h");
        Assert.AreEqual(t.Get("d"), 2);
    }
    
    [Test]
    public void test_temperature_from_K(){
        Quantity t = new Quantity(Metrics.Temperature, 0.0, "K");
        Assert.AreEqual(t.Get("K"), 0.0);
        Assert.AreEqual(t.Get("°C"), -273.15);
        Assert.AreEqual(t.Get("°F"), -459.67);
    }
    
    [Test]
    public void test_temperature_from_K_233(){
        Quantity t = new Quantity(Metrics.Temperature, 2.33, "K");
        Assert.AreEqual(t.Get("K"), 2.33);
        Assert.AreEqual(t.Get("°C"), -270.82);
        Assert.AreEqual(t.Get("°F"), -455.476);
    }
    
    [Test]
    public void test_temperature_from_C(){
       Quantity t = new Quantity(Metrics.Temperature, -40.0, "°C");
        Assert.AreEqual(t.Get("°C"), -40.0);
        Assert.AreEqual(t.Get("K"), 233.15, 1e-9);
        Assert.AreEqual(t.Get("°F"), -40.0, 1e-9);
    }
    
    [Test]
    public void test_temperature_from_F(){
        Quantity t  = new Quantity(Metrics.Temperature, -40.0, "°F");
        Assert.AreEqual(t.Get("K"), 233.15, 1e-9);
        Assert.AreEqual(t.Get("°C"), -40.0, 1e-9);
    }
    
    [Test]
    public void test_convert_velocity_from_mps_to_kmph(){
        Quantity v = new Quantity(Metrics.Velocity, 1.0, "m s-1");
        Assert.AreEqual(v.Get("km h-1"), 3.6);
    }
    
    [Test]
    public void test_convert_velocity_from_kmph_to_kmph(){
        Quantity v = new Quantity(Metrics.Velocity, 3.6, "km h-1");
        Assert.AreEqual(v.Get("km h-1"), 3.6);
    }
    
    [Test]
    public void test_convert_velocity_from_kmph_to_mps(){
        Quantity v = new Quantity(Metrics.Velocity, 3.6, "km h-1");
        Assert.AreEqual(v.Get("m s-1"), 1d);
    }
    
    [Test]
    public void test_convert_velocity_from_miph_to_kmph(){
        Quantity v = new Quantity(Metrics.Velocity, 1d, "mi h-1");
        Assert.AreEqual(v.Get("km h-1"), 1.609344);
    }
    
    [Test]
    public void test_convert_area_from_inch2_to_yd2(){
        Quantity a = new Quantity(Metrics.Area, 2.33, "inc2");
        Assert.AreEqual(a.Get("yd2"), 0.00179783951, 1e-4);
    }
    
    //[Test]
    //public void test_convert_area_from_m2_to_are(){
    //    Quantity a = new Quantity(Metrics.Area, 200, "m2");
    //    Assert.AreEqual(a.Get("are"), 2, 1e-3);
    //}
    
    //[Test]
    //public void test_convert_area_from_acre_to_are(){
    //    Quantity a = new Quantity(Metrics.Area, 1, "ac");
    //    Assert.AreEqual(a.Get("are"), 40.4684, 1e-4);
    //}
    
    [Test]
    public void test_converting_volume_from_m3_to_in3(){
        Quantity v = new Quantity(Metrics.Volume, 1d, "m3");
        Assert.AreEqual(v.Get("cm3"), 1000000d, 1e-6);
        Assert.AreEqual(v.Get("gal"), 264.1720526372959086633370175, 1e-6);
        Assert.AreEqual(v.Get("inc3"), 61023.74409473228395275688189, 1e-6);
    //    Assert.AreEqual(v.Get("oz"), 33814.0227, 1e-6);
    }
    
    [Test]
    public void test_converting_volumetric_flow_from_m3ph_to(){
        Quantity v = new Quantity(Metrics.VolumetricFlow, 1.0, "m3 h-1");
        Assert.AreEqual(v.Get("m3 d-1"), 24.0, 1e-6);
        Assert.AreEqual(v.Get("gal min-1"), 4.402867543954931811055616958, 1e-6);
        Assert.AreEqual(v.Get("l s-1"), 0.2777777777777777777777777778, 1e-6);
    }
    
    [Test]
    public void test_converting_acceleration(){
        Quantity a = new Quantity(Metrics.Acceleration, 1.0, "m s-2");
        Assert.AreEqual(a.Get("inc s-2"), 39.37007874015748031496062992);
        Assert.AreEqual(a.Get("inc ms-2"), 3.93701e-005, 1e-7);
    }
    
    [Test]
    public void test_convert_force(){
        Quantity f = new Quantity(Metrics.Force, 1.0, "kg m s-2");
        Assert.AreEqual(f.Get("lb yd s-2"), 2.412061728866277343179999663);
    }
    
    [Test]
    public void test_convert_concentration(){
        Quantity c = new Quantity(Metrics.Concentration, 1d, "mg l-1");
        Assert.AreEqual(c.Get("mg dm-3"), 1.0, 1e-6);
        Assert.AreEqual(c.Get("g m-3"), 1.0, 1e-6);
    }
                
    }
}