# encoding: utf-8
from unittest import TestCase
import munits.quantity as quantity
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
        self.assertEqual(l('m'), Decimal('1'))
        self.assertEqual(l('dm'), Decimal('10.'))
        self.assertEqual(l('cm'), Decimal('100.'))
        self.assertEqual(l('mm'), Decimal('1000.'))
        self.assertEqual(l('μm'), Decimal('1e6'))
        self.assertEqual(l('nm'), Decimal('1e9'))
        self.assertEqual(l('pm'), Decimal('1e12'))
        self.assertEqual(l('fm'), Decimal('1e15'))
        self.assertEqual(l('am'), Decimal('1e18'))

    def test_length_none_one(self):
        l = quantity.Length(2.33, 'm')

        self.assertEqual(l('Em'), Decimal('2.33e-18'))
        self.assertEqual(l('Pm'), Decimal('2.33e-15'))
        self.assertEqual(l('Tm'), Decimal('2.33e-12'))
        self.assertEqual(l('Gm'), Decimal('2.33e-9'))
        self.assertEqual(l('Mm'), Decimal('2.33e-6'))
        self.assertEqual(l('km'), Decimal('2.33e-3'))
        self.assertEqual(l('hm'), Decimal('2.33e-2'))
        self.assertEqual(l('dam'), Decimal('2.33e-1'))
        self.assertEqual(l('m'), Decimal('2.33'))
        self.assertEqual(l('dm'), Decimal('23.3'))
        self.assertEqual(l('cm'), Decimal('233.'))
        self.assertEqual(l('mm'), Decimal('2330.'))
        self.assertEqual(l('μm'), Decimal('2.33e6'))
        self.assertEqual(l('nm'), Decimal('2.33e9'))
        self.assertEqual(l('pm'), Decimal('2.33e12'))
        self.assertEqual(l('fm'), Decimal('2.33e15'))
        self.assertEqual(l('am'), Decimal('2.33e18'))

    def test_length_zero(self):
        l = quantity.Length(0, 'm')

        self.assertEqual(l('Em'), Decimal('0'))
        self.assertEqual(l('Pm'), Decimal('0'))
        self.assertEqual(l('Tm'), Decimal('0'))
        self.assertEqual(l('Gm'), Decimal('0'))
        self.assertEqual(l('Mm'), Decimal('0'))
        self.assertEqual(l('km'), Decimal('0'))
        self.assertEqual(l('hm'), Decimal('0'))
        self.assertEqual(l('dam'), Decimal('0'))
        self.assertEqual(l('m'), Decimal('0'))
        self.assertEqual(l('dm'), Decimal('0'))
        self.assertEqual(l('cm'), Decimal('0'))
        self.assertEqual(l('mm'), Decimal('0'))
        self.assertEqual(l('μm'), Decimal('0'))
        self.assertEqual(l('nm'), Decimal('0'))
        self.assertEqual(l('pm'), Decimal('0'))
        self.assertEqual(l('fm'), Decimal('0'))
        self.assertEqual(l('am'), Decimal('0'))

    #MASS
    
    def test_mass_zero(self):
        m = quantity.Mass(0, 'g')
    
        self.assertEqual(m('Eg'), Decimal('0'))
        self.assertEqual(m('Pg'), Decimal('0'))
        self.assertEqual(m('Tg'), Decimal('0'))
        self.assertEqual(m('Gg'), Decimal('0'))
        self.assertEqual(m('Mg'), Decimal('0'))
        self.assertEqual(m('kg'), Decimal('0'))
        self.assertEqual(m('hg'), Decimal('0'))
        self.assertEqual(m('dag'), Decimal('0'))
        self.assertEqual(m('g'), Decimal('0'))
        self.assertEqual(m('dg'), Decimal('0'))
        self.assertEqual(m('cg'), Decimal('0'))
        self.assertEqual(m('mg'), Decimal('0'))
        self.assertEqual(m('μg'), Decimal('0'))
        self.assertEqual(m('ng'), Decimal('0'))
        self.assertEqual(m('pg'), Decimal('0'))
        self.assertEqual(m('fg'), Decimal('0'))
        self.assertEqual(m('ag'), Decimal('0'))

    def test_mass(self):
        m = quantity.Mass(1.0, 'g')

        self.assertEqual(m('Eg'), Decimal('1e-18'))
        self.assertEqual(m('Pg'), Decimal('1e-15'))
        self.assertEqual(m('Tg'), Decimal('1e-12'))
        self.assertEqual(m('Gg'), Decimal('1e-9'))
        self.assertEqual(m('Mg'), Decimal('1e-6'))
        self.assertEqual(m('kg'), Decimal('1e-3'))
        self.assertEqual(m('hg'), Decimal('1e-2'))
        self.assertEqual(m('dag'), Decimal('0.1'))
        self.assertEqual(m('g'), Decimal('1.'))
        self.assertEqual(m('dg'), Decimal('10.'))
        self.assertEqual(m('cg'), Decimal('100.'))
        self.assertEqual(m('gg'), Decimal('1000.'))
        self.assertEqual(m('μg'), Decimal('1e6'))
        self.assertEqual(m('ng'), Decimal('1e9'))
        self.assertEqual(m('pg'), Decimal('1e12'))
        self.assertEqual(m('fg'), Decimal('1e15'))
        self.assertEqual(m('ag'), Decimal('1e18'))


    def test_mass_none_one(self):
        m = quantity.Mass(2.33, 'g')

        self.assertEqual(m('Eg'), Decimal('2.33e-18'))
        self.assertEqual(m('Pg'), Decimal('2.33e-15'))
        self.assertEqual(m('Tg'), Decimal('2.33e-12'))
        self.assertEqual(m('Gg'), Decimal('2.33e-9'))
        self.assertEqual(m('Mg'), Decimal('2.33e-6'))
        self.assertEqual(m('kg'), Decimal('2.33e-3'))
        self.assertEqual(m('hg'), Decimal('2.33e-2'))
        self.assertEqual(m('dag'), Decimal('2.33e-1'))
        self.assertEqual(m('g'), Decimal('2.33'))
        self.assertEqual(m('dg'), Decimal('23.3'))
        self.assertEqual(m('cg'), Decimal('233.'))
        self.assertEqual(m('mg'), Decimal('2330.'))
        self.assertEqual(m('μg'), Decimal('2.33e6'))
        self.assertEqual(m('ng'), Decimal('2.33e9'))
        self.assertEqual(m('pg'), Decimal('2.33e12'))
        self.assertEqual(m('fg'), Decimal('2.33e15'))
        self.assertEqual(m('ag'), Decimal('2.33e18'))

    #TIME

    def test_time_zero(self):
        t = quantity.Time(0.0, 's')

        self.assertEqual(t('ms'), Decimal('0'))
        self.assertEqual(t('μs'), Decimal('0'))
        self.assertEqual(t('ns'), Decimal('0'))
        self.assertEqual(t('ps'), Decimal('0'))
        self.assertEqual(t('fs'), Decimal('0'))
        self.assertEqual(t('as'), Decimal('0'))

    def test_time(self):
        t = quantity.Time(1.0, 's')

        self.assertEqual(t('ms'), Decimal('1000.'))
        self.assertEqual(t('μs'), Decimal('1e6'))
        self.assertEqual(t('ns'), Decimal('1e9'))
        self.assertEqual(t('ps'), Decimal('1e12'))
        self.assertEqual(t('fs'), Decimal('1e15'))
        self.assertEqual(t('as'), Decimal('1e18'))

    def test_time_none_one(self):
        t = quantity.Time(2.33, 's')

        self.assertEqual(t('ms'), Decimal('2330.'))
        self.assertEqual(t('μs'), Decimal('2.33e6'))
        self.assertEqual(t('ns'), Decimal('2.33e9'))
        self.assertEqual(t('ps'), Decimal('2.33e12'))
        self.assertEqual(t('fs'), Decimal('2.33e15'))
        self.assertEqual(t('as'), Decimal('2.33e18'))

    #ELECTRIC_CURRENT
    def test_electric_currency_zero(self):
        i = quantity.ElectricCurrency(0, 'A')

        self.assertEqual(i('EA'), Decimal('0'))
        self.assertEqual(i('PA'), Decimal('0'))
        self.assertEqual(i('TA'), Decimal('0'))
        self.assertEqual(i('GA'), Decimal('0'))
        self.assertEqual(i('MA'), Decimal('0'))
        self.assertEqual(i('kA'), Decimal('0'))
        self.assertEqual(i('hA'), Decimal('0'))
        self.assertEqual(i('daA'), Decimal('0'))
        self.assertEqual(i('A'), Decimal('0'))
        self.assertEqual(i('dA'), Decimal('0'))
        self.assertEqual(i('cA'), Decimal('0'))
        self.assertEqual(i('mA'), Decimal('0'))
        self.assertEqual(i('μA'), Decimal('0'))
        self.assertEqual(i('nA'), Decimal('0'))
        self.assertEqual(i('pA'), Decimal('0'))
        self.assertEqual(i('fA'), Decimal('0'))
        self.assertEqual(i('aA'), Decimal('0'))

    def test_electric_currency(self):
        i = quantity.ElectricCurrency(1, 'A')

        self.assertEqual(i('EA'), Decimal('1e-18'))
        self.assertEqual(i('PA'), Decimal('1e-15'))
        self.assertEqual(i('TA'), Decimal('1e-12'))
        self.assertEqual(i('GA'), Decimal('1e-9'))
        self.assertEqual(i('MA'), Decimal('1e-6'))
        self.assertEqual(i('kA'), Decimal('1e-3'))
        self.assertEqual(i('hA'), Decimal('1e-2'))
        self.assertEqual(i('daA'), Decimal('1e-1'))
        self.assertEqual(i('A'), Decimal('1'))
        self.assertEqual(i('dA'), Decimal('10'))
        self.assertEqual(i('cA'), Decimal('100.'))
        self.assertEqual(i('mA'), Decimal('1000.'))
        self.assertEqual(i('μA'), Decimal('1e6'))
        self.assertEqual(i('nA'), Decimal('1e9'))
        self.assertEqual(i('pA'), Decimal('1e12'))
        self.assertEqual(i('fA'), Decimal('1e15'))
        self.assertEqual(i('aA'), Decimal('1e18'))

    def test_electric_currency_none_one(self):
        i = quantity.ElectricCurrency(2.33, 'A')

        self.assertEqual(i('EA'), Decimal('2.33e-18'))
        self.assertEqual(i('PA'), Decimal('2.33e-15'))
        self.assertEqual(i('TA'), Decimal('2.33e-12'))
        self.assertEqual(i('GA'), Decimal('2.33e-9'))
        self.assertEqual(i('MA'), Decimal('2.33e-6'))
        self.assertEqual(i('kA'), Decimal('2.33e-3'))
        self.assertEqual(i('hA'), Decimal('2.33e-2'))
        self.assertEqual(i('daA'), Decimal('2.33e-1'))
        self.assertEqual(i('A'), Decimal('2.33'))
        self.assertEqual(i('dA'), Decimal('23.3'))
        self.assertEqual(i('cA'), Decimal('233.'))
        self.assertEqual(i('mA'), Decimal('2330.'))
        self.assertEqual(i('μA'), Decimal('2.33e6'))
        self.assertEqual(i('nA'), Decimal('2.33e9'))
        self.assertEqual(i('pA'), Decimal('2.33e12'))
        self.assertEqual(i('fA'), Decimal('2.33e15'))
        self.assertEqual(i('aA'), Decimal('2.33e18'))

    def test_non_si_length(self):
        l = quantity.Length(1, 'm')
        self.assertAlmostEqual(l('in'), Decimal('39.37'), delta=1e-2)
        self.assertAlmostEqual(l('ft'), Decimal('3.28'), delta=1e-2)
        self.assertAlmostEqual(l('mi'), Decimal('0.000621'), delta=1e-2)

        l = quantity.Length(1, 'in')
        self.assertEqual(l('Em'), Decimal('0.0254e-18'))
        self.assertEqual(l('Pm'), Decimal('0.0254e-15'))
        self.assertEqual(l('Tm'), Decimal('0.0254e-12'))
        self.assertEqual(l('Gm'), Decimal('0.0254e-9'))
        self.assertEqual(l('Mm'), Decimal('0.0254e-6'))
        self.assertEqual(l('km'), Decimal('0.0254e-3'))
        self.assertEqual(l('hm'), Decimal('0.0254e-2'))
        self.assertEqual(l('dam'), Decimal('0.0254e-1'))
        self.assertEqual(l('m'), Decimal('0.0254'))
        self.assertEqual(l('dm'), Decimal('0.0254e1'))
        self.assertEqual(l('cm'), Decimal('0.0254e2'))
        self.assertEqual(l('mm'), Decimal('0.0254e3'))
        self.assertEqual(l('μm'), Decimal('0.0254e6'))
        self.assertEqual(l('nm'), Decimal('0.0254e9'))
        self.assertEqual(l('pm'), Decimal('0.0254e12'))
        self.assertEqual(l('fm'), Decimal('0.0254e15'))
        self.assertEqual(l('am'), Decimal('0.0254e18'))

    # @unittest.skip("inch to prefix_yard")
    # def test_non_si_length(self):
    #     l = quantity.Length(1, 'in')
    #     self.assertEqual(l('Eyd'), Decimal('0.02778993435448577680525164114e-18'))
    #     self.assertEqual(l('Pyd'), Decimal('0.02778993435448577680525164114e-15'))
    #     self.assertEqual(l('Tyd'), Decimal('0.02778993435448577680525164114e-12'))
    #     self.assertEqual(l('Gyd'), Decimal('0.02778993435448577680525164114e-9'))
    #     self.assertEqual(l('Myd'), Decimal('0.02778993435448577680525164114e-6'))
    #     self.assertEqual(l('kyd'), Decimal('0.02778993435448577680525164114e-3'))
    #     self.assertEqual(l('hyd'), Decimal('0.02778993435448577680525164114e-2'))
    #     self.assertEqual(l('dayd'), Decimal('0.02778993435448577680525164114e-1'))
    #     self.assertEqual(l('yd'), Decimal('0.02778993435448577680525164114'))
    #     self.assertEqual(l('dyd'), Decimal('0.02778993435448577680525164114e1'))
    #     self.assertEqual(l('cyd'), Decimal('0.02778993435448577680525164114e2'))
    #     self.assertEqual(l('myd'), Decimal('0.02778993435448577680525164114e3'))
    #     self.assertEqual(l('μyd'), Decimal('0.02778993435448577680525164114e6'))
    #     self.assertEqual(l('nyd'), Decimal('0.02778993435448577680525164114e9'))
    #     self.assertEqual(l('pyd'), Decimal('0.02778993435448577680525164114e12'))
    #     self.assertEqual(l('fyd'), Decimal('0.02778993435448577680525164114e15'))
    #     self.assertEqual(l('ayd'), Decimal('0.02778993435448577680525164114e18'))

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
        t = quantity.Time(1, "d")
        self.assertEqual(t('h'), Decimal("24"))

    def test_time_from_hour_to_day(self):
        t = quantity.Time(48, "h")
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

        # TIME

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

    def test_valid_temperature_unit(self):
        self.assertTrue(quantity.Temperature.is_valid_unit("°C"))


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
    def test_convert_velocity_from_mps_to_kmph(self):
        v = quantity.Velocity(1.0, 'm s-1')
        self.assertEqual(v('km h-1'), Decimal('3.6'))

    def test_convert_velocity_from_kmph_to_kmph(self):
        v = quantity.Velocity(3.6, 'km h-1')
        self.assertEqual(v('km h-1'), Decimal('3.6'))

    def test_convert_velocity_from_kmph_to_mps(self):
        v = quantity.Velocity(3.6, 'km h-1')
        self.assertEqual(v('m s-1'), Decimal('1.'))

    def test_convert_velocity_from_miph_to_kmph(self):
        v = quantity.Velocity(1., 'mi h-1')
        self.assertEqual(v('km h-1'), Decimal('1.609344'))

    def test_converting_volume_from_m3_to_in3(self):
        v = quantity.Volume(1, 'm3')
        self.assertEqual(v('cm3'), Decimal('1000000.'))
        self.assertEqual(v('gal'), Decimal('264.1720526372959086633370175'))
        self.assertEqual(v("in3"), Decimal('61023.74409473228395275688189'))

    def test_converting_volumetric_flow_from_m3ph_to(self):
        v = quantity.VolumetricFlow(1.0, 'm3 h-1')
        self.assertAlmostEqual(v('m3 d-1'), Decimal('24.0'), delta=1e-6)
        self.assertEqual(v('gal min-1'), Decimal('4.402867543954931811055616958'))
        self.assertEqual(v('l s-1'), Decimal('0.2777777777777777777777777778'))

    def test_converting_acceleration(self):
        a = quantity.Acceleration(1.0, 'm s-2')
        self.assertEqual(a('in s-2'), Decimal('39.37007874015748031496062992'))
        self.assertEqual(a('in ms-2'), Decimal('0.00003937007874015748031496062992'))

    def test_convert_force(self):
        f = quantity.Force(1.0, 'kg m s-2')
        self.assertEqual(f('lb yd s-2'), Decimal('2.412061728866277343179999663'))

    def test_convert_concentration(self):
        c = quantity.Concentration(1.,  'mg l-1')
        self.assertEqual(c('mg dm-3'), Decimal('1.0'))
        self.assertEqual(c('g m-3'), Decimal('1.0'))