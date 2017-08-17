# encoding: utf-8
import unittest

from munits import Mass, Length, Time, Temperature, Acceleration, Force, MolarConcentration


class TestQuantityBaseUnitComparison(unittest.TestCase):
    def test_comparing_base_with_base_equal(self):
        m1 = Mass(1., 'g')
        m2 = Mass(1., 'g')
        self.assertTrue(m1 == m2)
        self.assertTrue(m1 <= m2)
        self.assertTrue(m1 >= m2)
        self.assertFalse(m1 > m2)
        self.assertFalse(m1 < m2)
        self.assertFalse(m1 != m2)

    def test_comparing_base_with_base_greater(self):
        m1 = Mass(2., 'g')
        m2 = Mass(1., 'g')
        self.assertFalse(m1 == m2)
        self.assertFalse(m1 <= m2)
        self.assertTrue(m1 >= m2)
        self.assertTrue(m1 > m2)
        self.assertFalse(m1 < m2)
        self.assertTrue(m1 != m2)

    def test_comparing_base_with_base_less(self):
        m1 = Mass(1., 'g')
        m2 = Mass(2., 'g')
        self.assertFalse(m1 == m2)
        self.assertTrue(m1 <= m2)
        self.assertFalse(m1 >= m2)
        self.assertFalse(m1 > m2)
        self.assertTrue(m1 < m2)
        self.assertTrue(m1 != m2)

    def test_comparing_none_base_with_base_equal(self):
        l1 = Length(1000., 'mm')
        l2 = Length(1., 'm')
        self.assertTrue(l1 == l2)
        self.assertTrue(l1 <= l2)
        self.assertTrue(l1 >= l2)
        self.assertFalse(l1 > l2)
        self.assertFalse(l1 < l2)
        self.assertFalse(l1 != l2)

    def test_comparing_none_base_with_base_greater(self):
        l1 = Length(10000., 'mm')
        l2 = Length(1., 'm')
        self.assertFalse(l1 == l2)
        self.assertFalse(l1 <= l2)
        self.assertTrue(l1 >= l2)
        self.assertTrue(l1 > l2)
        self.assertFalse(l1 < l2)
        self.assertTrue(l1 != l2)

    def test_comparing_none_base_with_base_less(self):
        l1 = Length(100., 'mm')
        l2 = Length(1., 'm')
        self.assertFalse(l1 == l2)
        self.assertTrue(l1 <= l2)
        self.assertFalse(l1 >= l2)
        self.assertFalse(l1 > l2)
        self.assertTrue(l1 < l2)
        self.assertTrue(l1 != l2)

    def test_comparing_none_base_with_none_base_equal(self):
        m1 = Mass(100., 'dag')
        m2 = Mass(1., 'kg')
        self.assertTrue(m1 == m2)
        self.assertTrue(m1 <= m2)
        self.assertTrue(m1 >= m2)
        self.assertFalse(m1 > m2)
        self.assertFalse(m1 < m2)
        self.assertFalse(m1 != m2)

    def test_comparing_none_base_with_none_base_less(self):
        m1 = Mass(10., 'dag')
        m2 = Mass(1., 'kg')
        self.assertFalse(m1 == m2)
        self.assertTrue(m1 <= m2)
        self.assertFalse(m1 >= m2)
        self.assertFalse(m1 > m2)
        self.assertTrue(m1 < m2)
        self.assertTrue(m1 != m2)

    def test_comparing_none_base_with_none_base_greater(self):
        m1 = Mass(1000., 'dag')
        m2 = Mass(1., 'kg')
        self.assertFalse(m1 == m2)
        self.assertFalse(m1 <= m2)
        self.assertTrue(m1 >= m2)
        self.assertTrue(m1 > m2)
        self.assertFalse(m1 < m2)
        self.assertTrue(m1 != m2)

        # TIME

    def test_comparing_time_none_base_with_none_base_equal(self):
        t1 = Time(1., 'd')
        t2 = Time(24., 'h')
        self.assertTrue(t1 == t2)
        self.assertTrue(t1 <= t2)
        self.assertTrue(t1 >= t2)
        self.assertFalse(t1 > t2)
        self.assertFalse(t1 < t2)
        self.assertFalse(t1 != t2)

    def test_comparing_time_none_base_with_none_base_less(self):
        t1 = Time(1., 'd')
        t2 = Time(25., 'h')
        self.assertFalse(t1 == t2)
        self.assertTrue(t1 <= t2)
        self.assertFalse(t1 >= t2)
        self.assertFalse(t1 > t2)
        self.assertTrue(t1 < t2)
        self.assertTrue(t1 != t2)

    def test_comparing_time_none_base_with_none_base_greater(self):
        t1 = Time(1., 'd')
        t2 = Time(23., 'h')
        self.assertFalse(t1 == t2)
        self.assertFalse(t1 <= t2)
        self.assertTrue(t1 >= t2)
        self.assertTrue(t1 > t2)
        self.assertFalse(t1 < t2)
        self.assertTrue(t1 != t2)

    def test_comparing_base_with_base_temperature_equal(self):
        t1 = Temperature(273.15, 'K')
        t2 = Temperature(273.15, 'K')
        self.assertTrue(t1 == t2)
        self.assertTrue(t1 <= t2)
        self.assertTrue(t1 >= t2)
        self.assertFalse(t1 < t2)
        self.assertFalse(t1 > t2)
        self.assertFalse(t1 != t2)

    def test_comparing_base_with_base_temperature_less(self):
        t1 = Temperature(0., 'K')
        t2 = Temperature(273.15, 'K')
        self.assertFalse(t1 == t2)
        self.assertTrue(t1 <= t2)
        self.assertFalse(t1 >= t2)
        self.assertTrue(t1 < t2)
        self.assertFalse(t1 > t2)
        self.assertTrue(t1 != t2)

    def test_comparing_base_with_base_temperature_greater(self):
        t1 = Temperature(273.15, 'K')
        t2 = Temperature(0., 'K')
        self.assertFalse(t1 == t2)
        self.assertFalse(t1 <= t2)
        self.assertTrue(t1 >= t2)
        self.assertFalse(t1 < t2)
        self.assertTrue(t1 > t2)
        self.assertTrue(t1 != t2)


class TestQuantityDerivedUnitComparison(unittest.TestCase):
    # Acceleration

    def test_comparing_derived_with_derived_acceleration_equal(self):
        a1 = Acceleration(1, "m s-2")
        a2 = Acceleration(1, "m s-2")

        self.assertTrue(a1 == a2)
        self.assertTrue(a1 <= a2)
        self.assertTrue(a1 >= a2)
        self.assertFalse(a1 > a2)
        self.assertFalse(a1 < a2)
        self.assertFalse(a1 != a2)

    def test_comparing_derived_with_derived_acceleration_greater(self):
        a1 = Acceleration(2, "m s-2")
        a2 = Acceleration(1, "m s-2")

        self.assertFalse(a1 == a2)
        self.assertFalse(a1 <= a2)
        self.assertTrue(a1 >= a2)
        self.assertTrue(a1 > a2)
        self.assertFalse(a1 < a2)
        self.assertTrue(a1 != a2)

    def test_comparing_derived_with_derived_acceleration_less(self):
        a1 = Acceleration(1, "m s-2")
        a2 = Acceleration(2, "m s-2")

        self.assertFalse(a1 == a2)
        self.assertTrue(a1 <= a2)
        self.assertFalse(a1 >= a2)
        self.assertFalse(a1 > a2)
        self.assertTrue(a1 < a2)
        self.assertTrue(a1 != a2)

    # FORCE

    def test_comparing_derived_with_derived_force_equal(self):
        f1 = Force(1, "kg m s-2")
        f2 = Force(1, "kg m s-2")

        self.assertTrue(f1 == f2)
        self.assertTrue(f1 <= f2)
        self.assertTrue(f1 >= f2)
        self.assertFalse(f1 > f2)
        self.assertFalse(f1 < f2)
        self.assertFalse(f1 != f2)

    def test_comparing_derived_with_derived_force_greater(self):
        f1 = Force(2, "kg m s-2")
        f2 = Force(1, "kg m s-2")

        self.assertFalse(f1 == f2)
        self.assertFalse(f1 <= f2)
        self.assertTrue(f1 >= f2)
        self.assertTrue(f1 > f2)
        self.assertFalse(f1 < f2)
        self.assertTrue(f1 != f2)

    def test_comparing_derived_with_derived_force_less(self):
        f1 = Force(1, "kg m s-2")
        f2 = Force(2, "kg m s-2")

        self.assertFalse(f1 == f2)
        self.assertTrue(f1 <= f2)
        self.assertFalse(f1 >= f2)
        self.assertFalse(f1 > f2)
        self.assertTrue(f1 < f2)
        self.assertTrue(f1 != f2)

    # MOLARCCONCENTRATION

    def test_comparing_derived_with_derived_molar_concentration_equal(self):
        c1 = MolarConcentration(1, "mol m-3")
        c2 = MolarConcentration(1, "mol m-3")

        self.assertTrue(c1 == c2)
        self.assertTrue(c1 <= c2)
        self.assertTrue(c1 >= c2)
        self.assertFalse(c1 > c2)
        self.assertFalse(c1 < c2)
        self.assertFalse(c1 != c2)

    def test_comparing_derived_with_derived_molar_concentration_greater(self):
        c1 = MolarConcentration(2, "mol m-3")
        c2 = MolarConcentration(1, "mol m-3")

        self.assertFalse(c1 == c2)
        self.assertFalse(c1 <= c2)
        self.assertTrue(c1 >= c2)
        self.assertTrue(c1 > c2)
        self.assertFalse(c1 < c2)
        self.assertTrue(c1 != c2)

    def test_comparing_derived_with_derived_molar_concentration_less(self):
        c1 = MolarConcentration(1, "mol m-3")
        c2 = MolarConcentration(2, "mol m-3")

        self.assertFalse(c1 == c2)
        self.assertTrue(c1 <= c2)
        self.assertFalse(c1 >= c2)
        self.assertFalse(c1 > c2)
        self.assertTrue(c1 < c2)
        self.assertTrue(c1 != c2)


