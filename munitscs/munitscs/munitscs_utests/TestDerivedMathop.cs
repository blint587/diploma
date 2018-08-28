using munitscs;
using NUnit.Framework;

namespace munitscs_utests
{
    [TestFixture]
    public class TestDerivedMathop
    {           
        [Test]
        public void create_create_volumetricflow_zero(){
            Quantity v = new Quantity(Metrics.Volume, 0, "m3");
            Quantity t = new Quantity(Metrics.Time, 1, "h");
            Quantity vf = v / t;
            Assert.AreEqual(vf.GetUnitType(),Metrics.VolumetricFlow);
            Assert.AreEqual(vf.Get("m3 h-1"), 0d);
        }
        
        [Test]
        public void create_volumetricflow_233_2(){
            Quantity v = new Quantity(Metrics.Volume, 12.649, "m3");
            Quantity t = new Quantity(Metrics.Time, 2.33, "h");
            Quantity vf2 = v / t;
        
            Assert.AreEqual(vf2.GetUnitType(), Metrics.VolumetricFlow);
            Assert.AreEqual(vf2.Get("m3 h-1"), 5.4289, 1e-3);
        }
        
        [Test]
        public void create_molar_concentration_from_n_l_v_zero_4(){
            Quantity v = new Quantity(Metrics.Volume,  1, "m3");
            Quantity n = new Quantity(Metrics.AmountOfSubstance, 0, "mol");
            Quantity mc4 = n / v;
        
            Assert.AreEqual(mc4.GetUnitType(), Metrics.MolarConcentration);
        
            Assert.AreEqual(mc4.Get("mol m-3"), 0d);
        }
        
        [Test]
        public void create_molar_concentration_from_n_l_v_4(){
            Quantity v = new Quantity(Metrics.Volume, 1, "m3");
            Quantity n = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
            Quantity mc4 = n / v;
        
            Assert.AreEqual(mc4.GetUnitType(), Metrics.MolarConcentration);
        
            Assert.AreEqual(mc4.Get("mol m-3"), 1d);
        }
        [Test]
        public void create_molar_concentration_from_n_l_v_233_4(){
            Quantity v = new Quantity(Metrics.Volume, 12.649, "m3");
            Quantity n = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
            Quantity mc4 = n / v;
        
            Assert.AreEqual(mc4.GetUnitType(), Metrics.MolarConcentration);
        
            Assert.AreEqual(mc4.Get("mol m-3"), 0.0790, 1e-3);
        }
        
        
        [Test]
        public void create_force_from_m_a_zero(){
            Quantity m = new Quantity(Metrics.Mass, 0, "g");
            Quantity a = new Quantity(Metrics.Acceleration, 0, "m s-2");
            Quantity f1 = m * a;
            Assert.AreEqual(f1.GetUnitType(), Metrics.Force);
            Assert.AreEqual(f1.Get("kg m s-2"), 0d);
        }
        [Test]
        public void create_force_from_m_a(){
            Quantity m = new Quantity(Metrics.Mass, 1, "kg");
            Quantity a = new Quantity(Metrics.Acceleration, 1, "m s-2");
            Quantity f1 = m * a;
            Assert.AreEqual(f1.GetUnitType(), Metrics.Force);
            Assert.AreEqual(f1.Get("kg m s-2"), 1d);
        }
        [Test]
        public void create_force_from_m_a_233(){
            Quantity m = new Quantity(Metrics.Mass, 2.33, "kg");
            Quantity a = new Quantity(Metrics.Acceleration, 1, "m s-2");
            Quantity f1 = m * a;
            Assert.AreEqual(f1.GetUnitType(), Metrics.Force);
            Assert.AreEqual(f1.Get("kg m s-2"), 2.33);
        }
        
        [Test]
        public void create_power_from_force_length_and_time(){
            Quantity f = new Quantity(Metrics.Force, 2.33, "N");
            Quantity l = new Quantity(Metrics.Length, 1, "m");
            Quantity t = new Quantity(Metrics.Time, 1, "s");
        
            Quantity p = f * l / t;
            Assert.AreEqual(p.GetUnitType(), Metrics.Power);
            Assert.AreEqual(p.Get("W"), 2.33);
        }
        
        [Test]
        public void create_power_from_power(){
            Quantity f = new Quantity(Metrics.Power, 1, "kW");
            Quantity t1 = new Quantity(Metrics.Time, 1, "h");
            Quantity t2 = new Quantity(Metrics.Time, 1, "d");
        
            Quantity p = f * t1 / t2;
            Assert.AreEqual(p.GetUnitType(), Metrics.Power);
            Assert.AreEqual(p.Get("kW"), 1/24d);
        }
        
        [Test]
        public void conversion_during_mathop_multiplication(){
        
            Quantity q = new Quantity(Metrics.VolumetricFlow, 1, "m3 d-1");
            Quantity t = new Quantity(Metrics.Time, 24, "h");
        
            Quantity v = q * t;
        
            Assert.AreEqual(v.GetUnitType(), Metrics.Volume);
        
            Assert.AreEqual(v.Get("m3"), 1);
        
        }
        
        [Test]
        public void conversion_during_mathop_division_rato_same_exponents(){
        
            Quantity v1 = new Quantity(Metrics.VolumetricFlow, 50, "m3 h-1");
            Quantity v2 = new Quantity(Metrics.VolumetricFlow, 400, "m3 d-1");
        
            Quantity r = v1 / v2;
        
            Assert.AreEqual(r.GetUnitType(), Metrics._Last);
        
            Assert.AreEqual((double) r, 3.0, 1e-15);
        }
        [Test]
        public void conversion_during_mathop_division_rato_different_exponents_left(){
        
            Quantity v1 = new Quantity(Metrics.MolarConcentration, 10, "mol l-1");
            Quantity v2 = new Quantity(Metrics.MolarConcentration, 1, "mol dm-3");
        
            Quantity r = v1 / v2;
        
            Assert.AreEqual(r.GetUnitType(), Metrics._Last);
        
            Assert.AreEqual((double) r, 10d, 10e-5);
        }
        [Test]
        public void conversion_during_mathop_division_rato_different_exponents_right(){
        
            Quantity v1 = new Quantity(Metrics.MolarConcentration, 10, "mol dm-3");
            Quantity v2 = new Quantity(Metrics.MolarConcentration, 1, "mol l-1");
        
            Quantity r = v1 / v2;
        
            Assert.AreEqual(r.GetUnitType(), Metrics._Last);
        
            Assert.AreEqual((double) r, 10d, 10e-5);
        }
        
        [Test]
        public void conversion_during_mathop_division(){
        
            Quantity v = new Quantity(Metrics.Volume, 9, "m3");
            Quantity l = new Quantity(Metrics.Length, 3000, "mm");
        
            Quantity a = v /l;
        
            Assert.AreEqual(a.GetUnitType(), Metrics.Area);
        
            Assert.AreEqual(a.Get("m2"), 3, 0.00001);
        }
        [Test]
        public void conversion_during_mathop_division_right_special(){
        
            Quantity v = new Quantity(Metrics.Volume, 1, "m3");
            Quantity l = new Quantity(Metrics.Length, 1, "inc");
        
            Quantity a = v /l;
        
            Assert.AreEqual(a.GetUnitType(), Metrics.Area);
            Assert.AreEqual(a.Get("m2"), 39.37007874015748, 1e-4);
        }
        [Test]
        public void conversion_during_mathop_division_left_special(){
        
            Quantity v = new Quantity(Metrics.Volume, 1, "l");
            Quantity l = new Quantity(Metrics.Length, 1, "dm");
        
            Quantity a = v /l;
        
            Assert.AreEqual(a.GetUnitType(), Metrics.Area);
            double avl = a.Get("dm2");
            Assert.AreEqual(avl, 1, 1e-4);
        }


    }
}