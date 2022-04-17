using munitscs;
using munitscs.Exceptions;
using NUnit.Framework;

namespace munitscs_utests
{
    [TestFixture]
    public class TestBaseMathop
    {
        [Test]
        public void _2rt_rootable()
        {
            var a = new Quantity(Metrics.Area, 4.0, "m2");
            var l = Quantity.Root(a, 2);

            Assert.AreEqual(l.GetUnitType(), Metrics.Length);

            Assert.AreEqual(l.Get("m"), 2.0);
        }

        [Test]
        public void _3rt_not_rootable()
        {
            var a = new Quantity(Metrics.Velocity, 8.0, "m s-1");
            Assert.Throws<CannotPerformRootOperation>(() => Quantity.Root(a, 3));
        }

        [Test]
        public void _3rt_rootable()
        {
            var a = new Quantity(Metrics.Volume, 8.0, "m3");

            var l = Quantity.Root(a,3);

            Assert.AreEqual(l.GetUnitType(), Metrics.Length);

            Assert.AreEqual(l.Get("m"), 2.0);
        }

        [Test]
        public void adding_mass_to_mass()
        {
            var m1 = new Quantity(Metrics.Mass, 1000d, "g");
            var m2 = new Quantity(Metrics.Mass, 1d, "kg");
            var m3 = m1 + m2;

            Assert.AreEqual(m3.Get("g"), 2000d);
        }

        //Create derived via math operation

        [Test]
        public void creat_acceleration_from_l_t_zero_1()
        {
            var l = new Quantity(Metrics.Length, 0, "m");
            var t = new Quantity(Metrics.Time, 1, "s");
            var a1 = l / (t * t);

            Assert.AreEqual(a1.GetUnitType(), Metrics.Acceleration);

            Assert.AreEqual(a1.Get("m s-2"), 0d);
        }

        [Test]
        public void creat_molar_concentration_from_n_l_v_2()
        {
            var l = new Quantity(Metrics.Length, 1, "m");
            var n = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
            var mc2 = n / Quantity.Pow(l, 3);

            Assert.AreEqual(mc2.GetUnitType(), Metrics.MolarConcentration);

            Assert.AreEqual(mc2.Get("mol m-3"), 1d);
        }

        [Test]
        public void create_acceleration_from_l_t_1()
        {
            var l = new Quantity(Metrics.Length, 1, "m");
            var t = new Quantity(Metrics.Time, 1, "s");

            var a1 = l / (t * t);

            Assert.AreEqual(a1.GetUnitType(), Metrics.Acceleration);

            Assert.AreEqual(a1.Get("m s-2"), 1d);
        }

        [Test]
        public void create_acceleration_from_l_t_2()
        {
            var l = new Quantity(Metrics.Length, 1, "m");
            var t = new Quantity(Metrics.Time, 1, "s");

            var a2 = l / Quantity.Pow(t, 2);

            Assert.AreEqual(a2.GetUnitType(), Metrics.Acceleration);

            Assert.AreEqual(a2.Get("m s-2"), 1d);
        }

        [Test]
        public void create_acceleration_from_l_t_3()
        {
            var l = new Quantity(Metrics.Length, 1, "m");
            var t = new Quantity(Metrics.Time, 1, "s");

            var a3 = l / t / t;

            Assert.AreEqual(a3.GetUnitType(), Metrics.Acceleration);

            Assert.AreEqual(a3.Get("m s-2"), 1d);
        }

        [Test]
        public void create_acceleration_from_l_t_none_zero_1()
        {
            var l = new Quantity(Metrics.Length, 2.33, "m");
            var t = new Quantity(Metrics.Time, 2.33, "s");
            var a1 = l / (t * t);

            Assert.AreEqual(a1.GetUnitType(), Metrics.Acceleration);

            Assert.AreEqual(a1.Get("m s-2"), 0.4229, 1e-2);
        }

        [Test]
        public void create_acceleration_from_l_t_none_zero_2()
        {
            var l = new Quantity(Metrics.Length, 2.33, "m");
            var t = new Quantity(Metrics.Time, 2.33, "s");
            var a2 = l / Quantity.Pow(t, 2);

            Assert.AreEqual(a2.GetUnitType(), Metrics.Acceleration);

            Assert.AreEqual(a2.Get("m s-2"), 0.4229, 1e-2);
        }

        [Test]
        public void create_acceleration_from_l_t_none_zero_3()
        {
            var l = new Quantity(Metrics.Length, 2.33, "m");
            var t = new Quantity(Metrics.Time, 2.33, "s");
            var a3 = l / t / t;

            Assert.AreEqual(a3.GetUnitType(), Metrics.Acceleration);

            Assert.AreEqual(a3.Get("m s-2"), 0.4229, 1e-2);
        }


        [Test]
        public void create_acceleration_from_l_t_zero_2()
        {
            var l = new Quantity(Metrics.Length, 0, "m");
            var t = new Quantity(Metrics.Time, 1, "s");
            var a2 = l / Quantity.Pow(t, 2);

            Assert.AreEqual(a2.GetUnitType(), Metrics.Acceleration);

            Assert.AreEqual(a2.Get("m s-2"), 0d);
        }

        [Test]
        public void create_acceleration_from_l_t_zero_3()
        {
            var l = new Quantity(Metrics.Length, 0, "m");
            var t = new Quantity(Metrics.Time, 1, "s");
            var a3 = l / t / t;

            Assert.AreEqual(a3.GetUnitType(), Metrics.Acceleration);

            Assert.AreEqual(a3.Get("m s-2"), 0d);
        }

        [Test]
        public void create_molar_concentration_from_n_l_v_1()
        {
            var l = new Quantity(Metrics.Length, 1, "m");
            var n = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
            var mc1 = n / (l * l * l);

            Assert.AreEqual(mc1.GetUnitType(), Metrics.MolarConcentration);

            Assert.AreEqual(mc1.Get("mol m-3"), 1d);
        }

        [Test]
        public void create_molar_concentration_from_n_l_v_233_1()
        {
            var l = new Quantity(Metrics.Length, 2.33, "m");
            var n = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
            var mc1 = n / (l * l * l);

            Assert.AreEqual(mc1.GetUnitType(), Metrics.MolarConcentration);

            Assert.AreEqual(mc1.Get("mol m-3"), 0.0790, 1e-3);
        }

        [Test]
        public void create_molar_concentration_from_n_l_v_233_3()
        {
            var l = new Quantity(Metrics.Length, 2.33, "m");
            var n = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
            var mc3 = n / l / l / l;

            Assert.AreEqual(mc3.GetUnitType(), Metrics.MolarConcentration);

            Assert.AreEqual(mc3.Get("mol m-3"), 0.0790, 1e-3);
        }

        [Test]
        public void create_molar_concentration_from_n_l_v_3()
        {
            var l = new Quantity(Metrics.Length, 1, "m");
            var n = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
            var mc3 = n / l / l / l;

            Assert.AreEqual(mc3.GetUnitType(), Metrics.MolarConcentration);

            Assert.AreEqual(mc3.Get("mol m-3"), 1d);
        }

        [Test]
        public void create_molar_concentration_from_n_l_v_zero_1()
        {
            var l = new Quantity(Metrics.Length, 1, "m");
            var n = new Quantity(Metrics.AmountOfSubstance, 0, "mol");
            var mc1 = n / (l * l * l);

            Assert.AreEqual(mc1.GetUnitType(), Metrics.MolarConcentration);

            Assert.AreEqual(mc1.Get("mol m-3"), 0d);
        }

        [Test]
        public void create_molar_concentration_from_n_l_v_zero_2()
        {
            var l = new Quantity(Metrics.Length, 1, "m");
            var n = new Quantity(Metrics.AmountOfSubstance, 0, "mol");
            var mc2 = n / Quantity.Pow(l, 3);

            Assert.AreEqual(mc2.GetUnitType(), Metrics.MolarConcentration);

            Assert.AreEqual(mc2.Get("mol m-3"), 0d);
        }

        [Test]
        public void create_molar_concentration_from_n_l_v_zero_3()
        {
            var l = new Quantity(Metrics.Length, 1, "m");
            var n = new Quantity(Metrics.AmountOfSubstance, 0, "mol");
            var mc3 = n / l / l / l;

            Assert.AreEqual(mc3.GetUnitType(), Metrics.MolarConcentration);

            Assert.AreEqual(mc3.Get("mol m-3"), 0d);
        }

        [Test]
        public void create_power_base_units()
        {
            var l = new Quantity(Metrics.Length, 1, "m");
            var m = new Quantity(Metrics.Mass, 2.33, "kg");
            var t = new Quantity(Metrics.Time, 1, "s");
            var p = m * l * l / t / t / t;

            Assert.AreEqual(p.GetUnitType(), Metrics.Power);

            Assert.AreEqual(p.Get("W"), 2.33, 1e-3);
        }

        [Test]
        public void create_volumetricflow_233_1()
        {
            var l = new Quantity(Metrics.Length, 2.33, "m");
            var l1 = l * l * l;
            var t = new Quantity(Metrics.Time, 2.33, "h");
            var vf1 = l1 / t;

            Assert.AreEqual(vf1.GetUnitType(), Metrics.VolumetricFlow);

            Assert.AreEqual(vf1.Get("m3 h-1"), 5.4289, 1e-3);
        }

        [Test]
        public void create_volumetricflow_one_1()
        {
            var l = new Quantity(Metrics.Length, 1, "m");
            var v1 = l * l * l;
            var t = new Quantity(Metrics.Time, 1, "h");

            var vf1 = v1 / t;

            Assert.AreEqual(vf1.GetUnitType(), Metrics.VolumetricFlow);

            Assert.AreEqual(vf1.Get("m3 h-1"), 1d);
        }

        [Test]
        public void create_volumetricflow_one_2()
        {
            var l = new Quantity(Metrics.Length, 1, "m");
            var v2 = Quantity.Pow(l, 3);
            var t = new Quantity(Metrics.Time, 1, "h");

            var vf2 = v2 / t;

            Assert.AreEqual(vf2.GetUnitType(), Metrics.VolumetricFlow);

            Assert.AreEqual(vf2.Get("m3 h-1"), 1d);
        }

        [Test]
        public void create_volumetricflow_one_3()
        {
            var l = new Quantity(Metrics.Length, 1, "m");
            var t = new Quantity(Metrics.Time, 1, "h");

            var vf3 = l * l * l / t;

            Assert.AreEqual(vf3.GetUnitType(), Metrics.VolumetricFlow);

            Assert.AreEqual(vf3.Get("m3 h-1"), 1d);
        }

        [Test]
        public void crete_molar_concentration_from_n_l_v_233_2()
        {
            var l = new Quantity(Metrics.Length, 2.33, "m");
            var n = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
            var mc2 = n / Quantity.Pow(l, 3);

            Assert.AreEqual(mc2.GetUnitType(), Metrics.MolarConcentration);

            Assert.AreEqual(mc2.Get("mol m-3"), 0.0790, 1e-3);
        }

        [Test]
        public void division_with_numeric_type_from_right()
        {
            var m = new Quantity(Metrics.Mass, 1, "kg");
            var r = m / 2d;

            Assert.AreEqual(r.GetUnitType(), Metrics.Mass);

            Assert.AreEqual(r.Get("kg"), .5);
        }

        [Test]
        public void multiplaying_length_to_length()
        {
            var m1 = new Quantity(Metrics.Length, 1000d, "mm");
            var m2 = new Quantity(Metrics.Length, 1000d, "mm");
            var m3 = m1 * m2;

            Assert.AreEqual(m3.Get("m2"), 1, 0.0001);
        }

        [Test]
        public void multiplication_with_numeric_type_from_left()
        {
            var m = new Quantity(Metrics.Mass, 1, "kg");
            var r = 2 * m;

            Assert.AreEqual(r.GetUnitType(), Metrics.Mass);

            Assert.AreEqual(r.Get("kg"), 2d);
        }

        [Test]
        public void multiplication_with_numeric_type_from_right()
        {
            var m = new Quantity(Metrics.Mass, 1, "kg");
            var r = m * 2;

            Assert.AreEqual(r.GetUnitType(), Metrics.Mass);

            Assert.AreEqual(r.Get("kg"), 2d);
        }
    }
}