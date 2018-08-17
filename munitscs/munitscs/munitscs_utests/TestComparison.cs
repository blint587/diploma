using System;
using munitscs;
using NUnit.Framework;

namespace munitscs_utests
{
    [TestFixture]
    public class TestComparison
    {
        [Test]
        public void test_comparing_base_with_base_equal()
        {
            var m1 = new Quantity(Metrics.Mass, 1d, "g");
            var m2 = new Quantity(Metrics.Mass, 1d, "g");

            Assert.True(m1 == m2);
            Assert.True(m1 <= m2);
            Assert.True(m1 >= m2);
            Assert.False(m1 > m2);
            Assert.False(m1 < m2);
            Assert.False(m1 != m2);
        }

        [Test]
        public void test_comparing_base_with_base_greater()
        {
            var m1 = new Quantity(Metrics.Mass, 2d, "g");
            var m2 = new Quantity(Metrics.Mass, 1d, "g");
            Assert.False(m1 == m2);
            Assert.False(m1 <= m2);
            Assert.True(m1 >= m2);
            Assert.True(m1 > m2);
            Assert.False(m1 < m2);
            Assert.True(m1 != m2);
        }

        [Test]
        public void test_comparing_base_with_base_less()
        {
            var m1 = new Quantity(Metrics.Mass, 1d, "g");
            var m2 = new Quantity(Metrics.Mass, 2d, "g");
            Assert.False(m1 == m2);
            Assert.True(m1 <= m2);
            Assert.False(m1 >= m2);
            Assert.False(m1 > m2);
            Assert.True(m1 < m2);
            Assert.True(m1 != m2);
        }

        [Test]
        public void test_comparing_base_with_base_temperature_equal()
        {
            var t1 = new Quantity(Metrics.Temperature, 273.15, "K");
            var t2 = new Quantity(Metrics.Temperature, 273.15, "K");
            Assert.True(t1 == t2);
            Assert.True(t1 <= t2);
            Assert.True(t1 >= t2);
            Assert.False(t1 < t2);
            Assert.False(t1 > t2);
            Assert.False(t1 != t2);
        }

        [Test]
        public void test_comparing_base_with_base_temperature_greater()
        {
            var t1 = new Quantity(Metrics.Temperature, 273.15, "K");
            var t2 = new Quantity(Metrics.Temperature, 0d, "K");
            Assert.False(t1 == t2);
            Assert.False(t1 <= t2);
            Assert.True(t1 >= t2);
            Assert.False(t1 < t2);
            Assert.True(t1 > t2);
            Assert.True(t1 != t2);
        }

        [Test]
        public void test_comparing_base_with_base_temperature_less()
        {
            var t1 = new Quantity(Metrics.Temperature, 0d, "K");
            var t2 = new Quantity(Metrics.Temperature, 273.15d, "K");
            Assert.False(t1 == t2);
            Assert.True(t1 <= t2);
            Assert.False(t1 >= t2);
            Assert.True(t1 < t2);
            Assert.False(t1 > t2);
            Assert.True(t1 != t2);
        }
        //

        //# Acceleration
        //
        [Test]
        public void test_comparing_derived_with_derived_acceleration_equal()
        {
            var a1 = new Quantity(Metrics.Acceleration, 1, "m s-2");
            var a2 = new Quantity(Metrics.Acceleration, 1, "m s-2");
            Assert.True(a1 == a2);
            Assert.True(a1 <= a2);
            Assert.True(a1 >= a2);
            Assert.False(a1 > a2);
            Assert.False(a1 < a2);
            Assert.False(a1 != a2);
        }

        [Test]
        public void test_comparing_derived_with_derived_acceleration_greater()
        {
            var a1 = new Quantity(Metrics.Acceleration, 2, "m s-2");
            var a2 = new Quantity(Metrics.Acceleration, 1, "m s-2");
            Assert.False(a1 == a2);
            Assert.False(a1 <= a2);
            Assert.True(a1 >= a2);
            Assert.True(a1 > a2);
            Assert.False(a1 < a2);
            Assert.True(a1 != a2);
        }

        [Test]
        public void test_comparing_derived_with_derived_acceleration_less()
        {
            var a1 = new Quantity(Metrics.Acceleration, 1, "m s-2");
            var a2 = new Quantity(Metrics.Acceleration, 2, "m s-2");
            Assert.False(a1 == a2);
            Assert.True(a1 <= a2);
            Assert.False(a1 >= a2);
            Assert.False(a1 > a2);
            Assert.True(a1 < a2);
            Assert.True(a1 != a2);
        }
        //# FORCE

        [Test]
        public void test_comparing_derived_with_derived_force_equal()
        {
            var f1 = new Quantity(Metrics.Force, 1, "kg m s-2");
            var f2 = new Quantity(Metrics.Force, 1, "kg m s-2");
            Assert.True(f1 == f2);
            Assert.True(f1 <= f2);
            Assert.True(f1 >= f2);
            Assert.False(f1 > f2);
            Assert.False(f1 < f2);
            Assert.False(f1 != f2);
        }

        [Test]
        public void test_comparing_derived_with_derived_force_greater()
        {
            var f1 = new Quantity(Metrics.Force, 2, "kg m s-2");
            var f2 = new Quantity(Metrics.Force, 1, "kg m s-2");
            Assert.False(f1 == f2);
            Assert.False(f1 <= f2);
            Assert.True(f1 >= f2);
            Assert.True(f1 > f2);
            Assert.False(f1 < f2);
            Assert.True(f1 != f2);
        }

        [Test]
        public void test_comparing_derived_with_derived_force_less()
        {
            var f1 = new Quantity(Metrics.Force, 1, "kg m s-2");
            var f2 = new Quantity(Metrics.Force, 2, "kg m s-2");
            Assert.False(f1 == f2);
            Assert.True(f1 <= f2);
            Assert.False(f1 >= f2);
            Assert.False(f1 > f2);
            Assert.True(f1 < f2);
            Assert.True(f1 != f2);
        }
        //# MOLARCCONCENTRATION

        [Test]
        public void test_comparing_derived_with_derived_molar_concentration_equal()
        {
            var c1 = new Quantity(Metrics.MolarConcentration, 1, "mol m-3");
            var c2 = new Quantity(Metrics.MolarConcentration, 1, "mol m-3");
            Assert.True(c1 == c2);
            Assert.True(c1 <= c2);
            Assert.True(c1 >= c2);
            Assert.False(c1 > c2);
            Assert.False(c1 < c2);
            Assert.False(c1 != c2);
        }

        [Test]
        public void test_comparing_derived_with_derived_molar_concentration_greater()
        {
            var c1 = new Quantity(Metrics.MolarConcentration, 2, "mol m-3");
            var c2 = new Quantity(Metrics.MolarConcentration, 1, "mol m-3");
            Assert.False(c1 == c2);
            Assert.False(c1 <= c2);
            Assert.True(c1 >= c2);
            Assert.True(c1 > c2);
            Assert.False(c1 < c2);
            Assert.True(c1 != c2);
        }

        [Test]
        public void test_comparing_derived_with_derived_molar_concentration_less()
        {
            var c1 = new Quantity(Metrics.MolarConcentration, 1, "mol m-3");
            var c2 = new Quantity(Metrics.MolarConcentration, 2, "mol m-3");
            Assert.False(c1 == c2);
            Assert.True(c1 <= c2);
            Assert.False(c1 >= c2);
            Assert.False(c1 > c2);
            Assert.True(c1 < c2);
            Assert.True(c1 != c2);
        }

        [Test]
        public void test_comparing_none_base_with_base_equal()
        {
            var l1 = new Quantity(Metrics.Length, 1000d, "mm");
            var l2 = new Quantity(Metrics.Length, 1d, "m");
            Assert.True(l1 == l2);
            Assert.True(l1 <= l2);
            Assert.True(l1 >= l2);
            Assert.False(l1 > l2);
            Assert.False(l1 < l2);
            Assert.False(l1 != l2);
        }

        [Test]
        public void test_comparing_none_base_with_base_greater()
        {
            var l1 = new Quantity(Metrics.Length, 10000d, "mm");
            var l2 = new Quantity(Metrics.Length, 1d, "m");
            Assert.False(l1 == l2);
            Assert.False(l1 <= l2);
            Assert.True(l1 >= l2);
            Assert.True(l1 > l2);
            Assert.False(l1 < l2);
            Assert.True(l1 != l2);
        }

        [Test]
        public void test_comparing_none_base_with_base_less()
        {
            var l1 = new Quantity(Metrics.Length, 100d, "mm");
            var l2 = new Quantity(Metrics.Length, 1d, "m");
            Assert.False(l1 == l2);
            Assert.True(l1 <= l2);
            Assert.False(l1 >= l2);
            Assert.False(l1 > l2);
            Assert.True(l1 < l2);
            Assert.True(l1 != l2);
        }

        [Test]
        public void test_comparing_none_base_with_none_base_equal()
        {
            var m1 = new Quantity(Metrics.Mass, 100d, "dag");
            var m2 = new Quantity(Metrics.Mass, 1d, "kg");
            Assert.True(m1 == m2);
            Assert.True(m1 <= m2);
            Assert.True(m1 >= m2);
            Assert.False(m1 > m2);
            Assert.False(m1 < m2);
            Assert.False(m1 != m2);
        }

        [Test]
        public void test_comparing_none_base_with_none_base_greater()
        {
            var m1 = new Quantity(Metrics.Mass, 1000d, "dag");
            var m2 = new Quantity(Metrics.Mass, 1d, "kg");
            Assert.False(m1 == m2);
            Assert.False(m1 <= m2);
            Assert.True(m1 >= m2);
            Assert.True(m1 > m2);
            Assert.False(m1 < m2);
            Assert.True(m1 != m2);
        }

        [Test]
        public void test_comparing_none_base_with_none_base_less()
        {
            var m1 = new Quantity(Metrics.Mass, 10d, "dag");
            var m2 = new Quantity(Metrics.Mass, 1d, "kg");
            Assert.False(m1 == m2);
            Assert.True(m1 <= m2);
            Assert.False(m1 >= m2);
            Assert.False(m1 > m2);
            Assert.True(m1 < m2);
            Assert.True(m1 != m2);
        }

        [Test]
        public void test_comparing_time_none_base_with_none_base_equal()
        {
            var t1 = new Quantity(Metrics.Time, 1d, "d");
            var t2 = new Quantity(Metrics.Time, 24d, "h");
            Assert.True(t1 == t2);
            Assert.True(t1 <= t2);
            Assert.True(t1 >= t2);
            Assert.False(t1 > t2);
            Assert.False(t1 < t2);
            Assert.False(t1 != t2);
        }

        [Test]
        public void test_comparing_time_none_base_with_none_base_greater()
        {
            var t1 = new Quantity(Metrics.Time, 1d, "d");
            var t2 = new Quantity(Metrics.Time, 23d, "h");
            Assert.False(t1 == t2);
            Assert.False(t1 <= t2);
            Assert.True(t1 >= t2);
            Assert.True(t1 > t2);
            Assert.False(t1 < t2);
            Assert.True(t1 != t2);
        }

        [Test]
        public void test_comparing_time_none_base_with_none_base_less()
        {
            var t1 = new Quantity(Metrics.Time, 1d, "d");
            var t2 = new Quantity(Metrics.Time, 25d, "h");
            Assert.False(t1 == t2);
            Console.WriteLine(t1 <= t2);
            Assert.True(t1 <= t2);
            Assert.False(t1 >= t2);
            Assert.False(t1 > t2);
            Assert.True(t1 < t2);
            Assert.True(t1 != t2);
        }
    }
}