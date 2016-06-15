# encoding: utf-8
from unittest import TestCase
import src.quantity as quantity
from decimal import Decimal


class TestQuantityBaseUnitConversion(TestCase):

    def test_length(self):
        l = quantity.Length(1.0, 'm')

        self.assertEqual(l('Em'), Decimal('1e-18'))
        self.assertEqual(l('Pm'), Decimal('1e-15'))
        self.assertEqual(l('Tm'), Decimal('1e-12'))
        self.assertEqual(l('Gm'), Decimal('1e-9'))
        self.assertEqual(l('Mm'), Decimal('1e-6'))
        self.assertEqual(l('km'), Decimal('1e-3'))
        self.assertEqual(l('hm'), Decimal('1e-2'))
        self.assertEqual(l('dam'), Decimal('0.1'))
        self.assertEqual(l('dm'), Decimal('10.'))
        self.assertEqual(l('cm'), Decimal('100.'))
        self.assertEqual(l('mm'), Decimal('1000.'))
        self.assertEqual(l('μm'), Decimal('1e6'))
        self.assertEqual(l('nm'), Decimal('1e9'))
        self.assertEqual(l('pm'), Decimal('1e12'))
        self.assertEqual(l('fm'), Decimal('1e15'))
        self.assertEqual(l('am'), Decimal('1e18'))

    def test_non_si_length(self):
        l=quantity.Length(1, 'm')
        self.assertAlmostEqual(l('in'), Decimal('39.37'),delta=1e-2)
        self.assertAlmostEqual(l('ft'), Decimal('3.28'), delta=1e-2)
        self.assertAlmostEqual(l('mi'), Decimal('0.000621'), delta=1e-2)

    def test_non_si_mass(self):
        m = quantity.Mass(1, 'g')
        self.assertAlmostEqual(m('oz'), Decimal('0.035'), delta=1e-2)
        self.assertAlmostEqual(m('lb'), Decimal('0.0022'), delta=1e-2)
        self.assertAlmostEqual(m('t'), Decimal('1e-6'), delta=1e-2)




    def test_mass(self):
        m = quantity.Mass(1.0, 'kg')

        self.assertEqual(m('Eg'), Decimal('1e-15'))
        self.assertEqual(m('Pg'), Decimal('1e-12'))
        self.assertEqual(m('Tg'), Decimal('1e-9'))
        self.assertEqual(m('Gg'), Decimal('1e-6'))
        self.assertEqual(m('Mg'), Decimal('1e-3'))
        self.assertEqual(m('kg'), Decimal('1'))
        self.assertEqual(m('hg'), Decimal('10'))
        self.assertEqual(m('dag'), Decimal('100'))
        self.assertEqual(m('dg'), Decimal('10000.'))
        self.assertEqual(m('cg'), Decimal('100000.'))
        self.assertEqual(m('mg'), Decimal('1000000.'))
        self.assertEqual(m('μg'), Decimal('1e9'))
        self.assertEqual(m('ng'), Decimal('1e12'))
        self.assertEqual(m('pg'), Decimal('1e15'))
        self.assertEqual(m('fg'), Decimal('1e18'))
        self.assertEqual(m('ag'), Decimal('1e21'))

    def test_time_from_s_with_prefix(self):
        t = quantity.Time(1.0, 's')

        self.assertEqual(t('ms'), Decimal('1000.'))
        self.assertEqual(t('μs'), Decimal('1e6'))
        self.assertEqual(t('ns'), Decimal('1e9'))
        self.assertEqual(t('ps'), Decimal('1e12'))
        self.assertEqual(t('fs'), Decimal('1e15'))
        self.assertEqual(t('as'), Decimal('1e18'))

    def test_time_from_s_to_min(self):
        t = quantity.Time(30, "s")
        self.assertEqual(t('min'), Decimal('0.5'))

    def test_time_from_min_to_s(self):
        t = quantity.Time(1.0, "min")
        self.assertEqual(t('s'), Decimal('60'))


    def test_time_from_hour_to_s(self):
        t = quantity.Time(1.0, "h")
        self.assertEqual(t('s'), Decimal('3600'))

    def test_time_from_s_to_hour(self):
        t = quantity.Time(3600, "s")
        self.assertEqual(t('h'), Decimal('1'))


    def test_time_from_d_to_s(self):
        t = quantity.Time(1.0, "d")
        self.assertEqual(t('s'), Decimal('86400.'))

    def test_time_from_s_to_d(self):
        t = quantity.Time(43200, "s")
        self.assertEqual(t('d'), Decimal('0.5'))

    def test_time_from_day_to_hour(self):
        t=quantity.Time(1,"d")
        self.assertEqual(t('h'), Decimal("24"))

    def test_time_from_hour_to_day(self):
        t=quantity.Time(48,"h")
        self.assertEqual(t('d'), Decimal("2"))



    def test_aos(self):
        n = quantity.AmountOfSubstance(1.0, 'kmol')
        self.assertEqual(n('mol'), 1000.0)

    def test_temperature_from_K(self):
        t = quantity.Temperature(0.0, 'K')
        self.assertEqual(t('K'), Decimal('0.0'))
        self.assertEqual(t('°C'), Decimal('-273.15'))
        self.assertEqual(t('°F'), Decimal('-459.67'))

    def test_temperature_from_C(self):
        t = quantity.Temperature(-40.0, '°C')
        self.assertEqual(t('°C'), Decimal('-40.0'))
        self.assertEqual(t('K'), Decimal('233.15'))
        self.assertAlmostEqual(t('°F'), Decimal('-40.0'), delta=1e-9)

    def test_temperature_from_F(self):
        t = quantity.Temperature(-40.0, '°F')
        self.assertAlmostEqual(t('K'), Decimal('233.15'), delta=1e-9)
        self.assertEqual(t('°C'), Decimal('-40.0'))

    def test_none_overlapping_units(self):
        T = quantity.Temperature(0., 'K')
        t = quantity.Time(0., 's')
        self.assertNotEqual(T._converter.additional_units, t._converter.additional_units)


class TestQuantityBaseUnitComparison(TestCase):

    def test_comparing_base_with_base_equal(self):
        m1 = quantity.Mass(1., 'g')
        m2 = quantity.Mass(1., 'g')
        self.assertTrue(m1 == m2)
        self.assertTrue(m1 <= m2)
        self.assertTrue(m1 >= m2)
        self.assertFalse(m1 > m2)
        self.assertFalse(m1 < m2)
        self.assertFalse(m1 != m2)

    def test_comparing_base_with_base_greater(self):
        m1 = quantity.Mass(2., 'g')
        m2 = quantity.Mass(1., 'g')
        self.assertFalse(m1 == m2)
        self.assertFalse(m1 <= m2)
        self.assertTrue(m1 >= m2)
        self.assertTrue(m1 > m2)
        self.assertFalse(m1 < m2)
        self.assertTrue(m1 != m2)

    def test_comparing_base_with_base_less(self):
        m1 = quantity.Mass(1., 'g')
        m2 = quantity.Mass(2., 'g')
        self.assertFalse(m1 == m2)
        self.assertTrue(m1 <= m2)
        self.assertFalse(m1 >= m2)
        self.assertFalse(m1 > m2)
        self.assertTrue(m1 < m2)
        self.assertTrue(m1 != m2)

    def test_comparing_none_base_with_base_equal(self):
        l1 = quantity.Length(1000., 'mm')
        l2 = quantity.Length(1., 'm')
        self.assertTrue(l1 == l2)
        self.assertTrue(l1 <= l2)
        self.assertTrue(l1 >= l2)
        self.assertFalse(l1 > l2)
        self.assertFalse(l1 < l2)
        self.assertFalse(l1 != l2)

    def test_comparing_none_base_with_base_greater(self):
        l1 = quantity.Length(10000., 'mm')
        l2 = quantity.Length(1., 'm')
        self.assertFalse(l1 == l2)
        self.assertFalse(l1 <= l2)
        self.assertTrue(l1 >= l2)
        self.assertTrue(l1 > l2)
        self.assertFalse(l1 < l2)
        self.assertTrue(l1 != l2)

    def test_comparing_none_base_with_base_less(self):
        l1 = quantity.Length(100., 'mm')
        l2 = quantity.Length(1., 'm')
        self.assertFalse(l1 == l2)
        self.assertTrue(l1 <= l2)
        self.assertFalse(l1 >= l2)
        self.assertFalse(l1 > l2)
        self.assertTrue(l1 < l2)
        self.assertTrue(l1 != l2)

    def test_comparing_none_base_with_none_base_equal(self):
        m1 = quantity.Mass(100., 'dag')
        m2 = quantity.Mass(1., 'kg')
        self.assertTrue(m1 == m2)
        self.assertTrue(m1 <= m2)
        self.assertTrue(m1 >= m2)
        self.assertFalse(m1 > m2)
        self.assertFalse(m1 < m2)
        self.assertFalse(m1 != m2)

    def test_comparing_none_base_with_none_base_less(self):
        m1 = quantity.Mass(10., 'dag')
        m2 = quantity.Mass(1., 'kg')
        self.assertFalse(m1 == m2)
        self.assertTrue(m1 <= m2)
        self.assertFalse(m1 >= m2)
        self.assertFalse(m1 > m2)
        self.assertTrue(m1 < m2)
        self.assertTrue(m1 != m2)

    def test_comparing_none_base_with_none_base_greater(self):
        m1 = quantity.Mass(1000., 'dag')
        m2 = quantity.Mass(1., 'kg')
        self.assertFalse(m1 == m2)
        self.assertFalse(m1 <= m2)
        self.assertTrue(m1 >= m2)
        self.assertTrue(m1 > m2)
        self.assertFalse(m1 < m2)
        self.assertTrue(m1 != m2)

  #TIME

    def test_comparing_time_none_base_with_none_base_equal(self):
        t1 = quantity.Time(1., 'd')
        t2 = quantity.Time(24., 'h')
        self.assertTrue(t1 == t2)
        self.assertTrue(t1 <= t2)
        self.assertTrue(t1 >= t2)
        self.assertFalse(t1 > t2)
        self.assertFalse(t1 < t2)
        self.assertFalse(t1 != t2)

    def test_comparing_time_none_base_with_none_base_less(self):
        t1 = quantity.Time(1., 'd')
        t2 = quantity.Time(25., 'h')
        self.assertFalse(t1 == t2)
        self.assertTrue(t1 <= t2)
        self.assertFalse(t1 >= t2)
        self.assertFalse(t1 > t2)
        self.assertTrue(t1 < t2)
        self.assertTrue(t1 != t2)

    def test_comparing_time_none_base_with_none_base_greater(self):
        t1 = quantity.Time(1., 'd')
        t2 = quantity.Time(23., 'h')
        self.assertFalse(t1 == t2)
        self.assertFalse(t1 <= t2)
        self.assertTrue(t1 >= t2)
        self.assertTrue(t1 > t2)
        self.assertFalse(t1 < t2)
        self.assertTrue(t1 != t2)



    def test_comparing_base_with_base_temperature_equal(self):
        t1 = quantity.Temperature(273.15, 'K')
        t2 = quantity.Temperature(273.15, 'K')
        self.assertTrue(t1 == t2)
        self.assertTrue(t1 <= t2)
        self.assertTrue(t1 >= t2)
        self.assertFalse(t1 < t2)
        self.assertFalse(t1 > t2)
        self.assertFalse(t1 != t2)

    def test_comparing_base_with_base_temperature_less(self):
        t1 = quantity.Temperature(0., 'K')
        t2 = quantity.Temperature(273.15, 'K')
        self.assertFalse(t1 == t2)
        self.assertTrue(t1 <= t2)
        self.assertFalse(t1 >= t2)
        self.assertTrue(t1 < t2)
        self.assertFalse(t1 > t2)
        self.assertTrue(t1 != t2)

    def test_comparing_base_with_base_temperature_greater(self):
        t1 = quantity.Temperature(273.15, 'K')
        t2 = quantity.Temperature(0., 'K')
        self.assertFalse(t1 == t2)
        self.assertFalse(t1 <= t2)
        self.assertTrue(t1 >= t2)
        self.assertFalse(t1 < t2)
        self.assertTrue(t1 > t2)
        self.assertTrue(t1 != t2)


class TestQuantityValidUnit(TestCase):

    def test_valid_mass_unit(self):
        self.assertTrue(quantity.Mass.is_valid_unit("kg"))

    def test_invalid_mass_unit(self):
        self.assertFalse(quantity.Mass.is_valid_unit("tg"))

    def test_valid_time_unit_second(self):
        self.assertTrue(quantity.Time.is_valid_unit("s"))

    def test_invalid_time_unit_second(self):
        self.assertFalse(quantity.Time.is_valid_unit("ts"))


class TestQuantityAddition(TestCase):

    def test_adding_mass_to_mass(self):

        m1 = quantity.Mass(1000., "g")
        m2 = quantity.Mass(1., "kg")
        m3 = m1 + m2

        self.assertEqual(m3.value, 2000.)
        self.assertEqual(m3.unit, "g")
        self.assertFalse(id(m1) == id(m3))
        self.assertFalse(id(m2) == id(m3))


class TestQuantityDerivedUnitsConversion(TestCase):

    def test_convert_velocity(self):

        v = quantity.Velocity(1.0, 'm s-1')
        self.assertEqual(v('km h-1'), Decimal(3.6))