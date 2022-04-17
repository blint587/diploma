# encoding: utf-8
import unittest

from munits import (
    Mass,
    Length,
    Time,
    Temperature,
    Acceleration,
    Force,
    MolarConcentration,
    Pressure,
    Power,
    Voltage
)


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

    def test_comparing_temperature_equal_in_different_unit(self):
        t1 = Temperature(-40, '°F')
        t2 = Temperature(-40., '°C')

        self.assertTrue(t1 == t2)
        self.assertTrue(t1 <= t2)
        self.assertTrue(t1 >= t2)
        self.assertFalse(t1 < t2)
        self.assertFalse(t1 > t2)
        self.assertFalse(t1 != t2)


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

    def test_comparing_derived_with_derived_force_equal_combined_def(self):
        f1 = Force(1, "N")
        f2 = Force(1, "N")

        self.assertTrue(f1 == f2)
        self.assertTrue(f1 <= f2)
        self.assertTrue(f1 >= f2)
        self.assertFalse(f1 > f2)
        self.assertFalse(f1 < f2)
        self.assertFalse(f1 != f2)

    def test_comparing_derived_with_derived_force_greater_combined_def(self):
        f1 = Force(2, "N")
        f2 = Force(1, "N")

        self.assertFalse(f1 == f2)
        self.assertFalse(f1 <= f2)
        self.assertTrue(f1 >= f2)
        self.assertTrue(f1 > f2)
        self.assertFalse(f1 < f2)
        self.assertTrue(f1 != f2)

    def test_comparing_derived_with_derived_force_less_combined_def(self):
        f1 = Force(1, "N")
        f2 = Force(2, "N")

        self.assertFalse(f1 == f2)
        self.assertTrue(f1 <= f2)
        self.assertFalse(f1 >= f2)
        self.assertFalse(f1 > f2)
        self.assertTrue(f1 < f2)
        self.assertTrue(f1 != f2)

    def test_force_equality_between_different_prefix_h(self):
        f1 = Force(100, "N")
        f2 = Force(1, "hN")

        self.assertTrue(f1 == f2)
        self.assertTrue(f1 <= f2)
        self.assertTrue(f1 >= f2)
        self.assertFalse(f1 > f2)
        self.assertFalse(f1 < f2)
        self.assertFalse(f1 != f2)

    def test_force_equality_between_different_prefix_k(self):
        f1 = Force(1000, "N")
        f2 = Force(1, "kN")

        self.assertTrue(f1 == f2)
        self.assertTrue(f1 <= f2)
        self.assertTrue(f1 >= f2)
        self.assertFalse(f1 > f2)
        self.assertFalse(f1 < f2)
        self.assertFalse(f1 != f2)

    # PRESSURE
    def test_pressure_equality_between_different_prefix_h(self):
        p1 = Pressure(100, "Pa")
        p2 = Pressure(1, "hPa")

        self.assertTrue(p1 == p2)
        self.assertTrue(p1 <= p2)
        self.assertTrue(p1 >= p2)
        self.assertFalse(p1 > p2)
        self.assertFalse(p1 < p2)
        self.assertFalse(p1 != p2)

    def test_pressure_equality_between_different_unit(self):
        p1 = Pressure(100, "mbar")
        p2 = Pressure(100, "hPa")

        self.assertTrue(p1 == p2)
        self.assertTrue(p1 <= p2)
        self.assertTrue(p1 >= p2)
        self.assertFalse(p1 > p2)
        self.assertFalse(p1 < p2)
        self.assertFalse(p1 != p2)

    # POWER
    def test_power_equality_in_different_prefix_k(self):
        p1 = Power(1000, "W")
        p2 = Power(1, "kW")

        self.assertTrue(p1 == p2)
        self.assertTrue(p1 <= p2)
        self.assertTrue(p1 >= p2)
        self.assertFalse(p1 > p2)
        self.assertFalse(p1 < p2)
        self.assertFalse(p1 != p2)

    def test_power_equality_in_different_prefix_h(self):
        p1 = Power(100, "W")
        p2 = Power(1, "hW")

        self.assertTrue(p1 == p2)
        self.assertTrue(p1 <= p2)
        self.assertTrue(p1 >= p2)
        self.assertFalse(p1 > p2)
        self.assertFalse(p1 < p2)
        self.assertFalse(p1 != p2)

    def test_power_equality_in_different_prefix_m(self):
        p1 = Power(0.001, "W")
        p2 = Power(1, "mW")

        self.assertTrue(p1 == p2)
        self.assertTrue(p1 <= p2)
        self.assertTrue(p1 >= p2)
        self.assertFalse(p1 > p2)
        self.assertFalse(p1 < p2)
        self.assertFalse(p1 != p2)

    # Voltage
    def test_voltage_equality_in_different_prefix_k(self):
        u1 = Voltage(1000, "V")
        u2 = Voltage(1, "kV")

        self.assertTrue(u1 == u2)
        self.assertTrue(u1 <= u2)
        self.assertTrue(u1 >= u2)
        self.assertFalse(u1 > u2)
        self.assertFalse(u1 < u2)
        self.assertFalse(u1 != u2)

    def test_voltage_equality_in_different_prefix_h(self):
        u1 = Voltage(100, "V")
        u2 = Voltage(1, "hV")

        self.assertTrue(u1 == u2)
        self.assertTrue(u1 <= u2)
        self.assertTrue(u1 >= u2)
        self.assertFalse(u1 > u2)
        self.assertFalse(u1 < u2)
        self.assertFalse(u1 != u2)

    def test_voltage_equality_in_different_prefix_m(self):
        u1 = Voltage(0.001, "V")
        u2 = Voltage(1, "mV")

        self.assertTrue(u1 == u2)
        self.assertTrue(u1 <= u2)
        self.assertTrue(u1 >= u2)
        self.assertFalse(u1 > u2)
        self.assertFalse(u1 < u2)
        self.assertFalse(u1 != u2)

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


