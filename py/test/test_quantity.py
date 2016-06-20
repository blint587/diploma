# encoding: utf-8
import unittest

import munits.quantity as quantity


# from float import float





class TestQuantityBaseUnitConversion(unittest.TestCase):
    def test_length_zero(self):
        l = quantity.Length(0, 'm')

        self.assertEqual(l('Em'), float('0'))
        self.assertEqual(l('Pm'), float('0'))
        self.assertEqual(l('Tm'), float('0'))
        self.assertEqual(l('Gm'), float('0'))
        self.assertEqual(l('Mm'), float('0'))
        self.assertEqual(l('km'), float('0'))
        self.assertEqual(l('hm'), float('0'))
        self.assertEqual(l('dam'), float('0'))
        self.assertEqual(l('m'), float('0'))
        self.assertEqual(l('dm'), float('0'))
        self.assertEqual(l('cm'), float('0'))
        self.assertEqual(l('mm'), float('0'))
        self.assertEqual(l('μm'), float('0'))
        self.assertEqual(l('nm'), float('0'))
        self.assertEqual(l('pm'), float('0'))
        self.assertEqual(l('fm'), float('0'))
        self.assertEqual(l('am'), float('0'))

    def test_length(self):
        l = quantity.Length(1.0, 'm')

        self.assertEqual(l('Em'), float('1e-18'))
        self.assertEqual(l('Pm'), float('1e-15'))
        self.assertEqual(l('Tm'), float('1e-12'))
        self.assertEqual(l('Gm'), float('1e-9'))
        self.assertEqual(l('Mm'), float('1e-6'))
        self.assertEqual(l('km'), float('1e-3'))
        self.assertEqual(l('hm'), float('1e-2'))
        self.assertEqual(l('dam'), float('0.1'))
        self.assertEqual(l('m'), float('1'))
        self.assertEqual(l('dm'), float('10.'))
        self.assertEqual(l('cm'), float('100.'))
        self.assertEqual(l('mm'), float('1000.'))
        self.assertEqual(l('μm'), float('1e6'))
        self.assertAlmostEqual(l('nm'), float('1e9'), delta=1)
        self.assertEqual(l('pm'), float('1e12'))
        self.assertAlmostEqual(l('fm'), float('1e15'), delta=1)
        # self.assertAlmostEqual(l('am'), float('1e18'), delta=1)

    def test_length_233(self):
        l = quantity.Length(2.33, 'm')

        self.assertAlmostEqual(l('Em'), float('2.33e-18'), delta=1e-6)
        self.assertAlmostEqual(l('Pm'), float('2.33e-15'), delta=1e-4)
        self.assertAlmostEqual(l('Tm'), float('2.33e-12'), delta=1e-6)
        self.assertEqual(l('Gm'), float('2.33e-9'))
        self.assertEqual(l('Mm'), float('2.33e-6'))
        self.assertEqual(l('km'), float('2.33e-3'))
        self.assertEqual(l('hm'), float('2.33e-2'))
        self.assertEqual(l('dam'), float('2.33e-1'))
        self.assertEqual(l('m'), float('2.33'))
        self.assertEqual(l('dm'), float('23.3'))
        self.assertEqual(l('cm'), float('233.'))
        self.assertEqual(l('mm'), float('2330.'))
        self.assertEqual(l('μm'), float('2.33e6'))
        self.assertEqual(l('nm'), float('2.33e9'))
        self.assertEqual(l('pm'), float('2.33e12'))
        self.assertEqual(l('fm'), float('2.33e15'))
        self.assertEqual(l('am'), float('2.33e18'))

    # MASS

    def test_mass_zero(self):
        m = quantity.Mass(0, 'g')

        self.assertEqual(m('Eg'), float('0'))
        self.assertEqual(m('Pg'), float('0'))
        self.assertEqual(m('Tg'), float('0'))
        self.assertEqual(m('Gg'), float('0'))
        self.assertEqual(m('Mg'), float('0'))
        self.assertEqual(m('kg'), float('0'))
        self.assertEqual(m('hg'), float('0'))
        self.assertEqual(m('dag'), float('0'))
        self.assertEqual(m('g'), float('0'))
        self.assertEqual(m('dg'), float('0'))
        self.assertEqual(m('cg'), float('0'))
        self.assertEqual(m('mg'), float('0'))
        self.assertEqual(m('μg'), float('0'))
        self.assertEqual(m('ng'), float('0'))
        self.assertEqual(m('pg'), float('0'))
        self.assertEqual(m('fg'), float('0'))
        self.assertEqual(m('ag'), float('0'))

    def test_mass(self):
        m = quantity.Mass(1.0, 'g')

        self.assertEqual(m('Eg'), float('1e-18'))
        self.assertEqual(m('Pg'), float('1e-15'))
        self.assertEqual(m('Tg'), float('1e-12'))
        self.assertEqual(m('Gg'), float('1e-9'))
        self.assertEqual(m('Mg'), float('1e-6'))
        self.assertEqual(m('kg'), float('1e-3'))
        self.assertEqual(m('hg'), float('1e-2'))
        self.assertEqual(m('dag'), float('0.1'))
        self.assertEqual(m('g'), float('1.'))
        self.assertEqual(m('dg'), float('10.'))
        self.assertEqual(m('cg'), float('100.'))
        self.assertEqual(m('mg'), float('1000.'))
        self.assertEqual(m('μg'), float('1e6'))
        self.assertAlmostEqual(m('ng'), float('1e9'), delta=1e-6)
        self.assertEqual(m('pg'), float('1e12'))
        self.assertAlmostEqual(m('fg'), float('1e15'), delta=1)
        # self.assertAlmostEqual(m('ag'), float('1e18'), delta=1000)

    def test_mass__233(self):
        m = quantity.Mass(2.33, 'g')

        self.assertAlmostEqual(m('Eg'), float('2.33e-18'), delta=1e-6)
        self.assertAlmostEqual(m('Pg'), float('2.33e-15'), delta=1e-6)
        self.assertEqual(m('Tg'), float('2.33e-12'))
        self.assertEqual(m('Gg'), float('2.33e-9'))
        self.assertEqual(m('Mg'), float('2.33e-6'))
        self.assertEqual(m('kg'), float('2.33e-3'))
        self.assertEqual(m('hg'), float('2.33e-2'))
        self.assertEqual(m('dag'), float('2.33e-1'))
        self.assertEqual(m('g'), float('2.33'))
        self.assertEqual(m('dg'), float('23.3'))
        self.assertEqual(m('cg'), float('233.'))
        self.assertEqual(m('mg'), float('2330.'))
        self.assertEqual(m('μg'), float('2.33e6'))
        self.assertEqual(m('ng'), float('2.33e9'))
        self.assertEqual(m('pg'), float('2.33e12'))
        self.assertEqual(m('fg'), float('2.33e15'))
        self.assertEqual(m('ag'), float('2.33e18'))

    # TIME

    def test_time_zero(self):
        t = quantity.Time(0.0, 's')

        self.assertEqual(t('ms'), float('0'))
        self.assertEqual(t('μs'), float('0'))
        self.assertEqual(t('ns'), float('0'))
        self.assertEqual(t('ps'), float('0'))
        self.assertEqual(t('fs'), float('0'))
        self.assertEqual(t('as'), float('0'))

    def test_time(self):
        t = quantity.Time(1.0, 's')

        self.assertEqual(t('ms'), float('1000.'))
        self.assertEqual(t('μs'), float('1e6'))
        self.assertAlmostEqual(t('ns'), float('1e9'), delta=1e-6)
        self.assertEqual(t('ps'), float('1e12'))
        self.assertAlmostEqual(t('fs'), float('1e15'), delta=1)
        # self.assertAlmostEqual(t('as'), float('1e18'), delta=1000)

    def test_time_233(self):
        t = quantity.Time(2.33, 's')

        self.assertEqual(t('ms'), float('2330.'))
        self.assertEqual(t('μs'), float('2.33e6'))
        self.assertEqual(t('ns'), float('2.33e9'))
        self.assertEqual(t('ps'), float('2.33e12'))
        self.assertEqual(t('fs'), float('2.33e15'))
        self.assertEqual(t('as'), float('2.33e18'))

    # ELECTRIC_CURRENT

    def test_electric_currency_zero(self):
        i = quantity.ElectricCurrency(0, 'A')

        self.assertEqual(i('EA'), float('0'))
        self.assertEqual(i('PA'), float('0'))
        self.assertEqual(i('TA'), float('0'))
        self.assertEqual(i('GA'), float('0'))
        self.assertEqual(i('MA'), float('0'))
        self.assertEqual(i('kA'), float('0'))
        self.assertEqual(i('hA'), float('0'))
        self.assertEqual(i('daA'), float('0'))
        self.assertEqual(i('A'), float('0'))
        self.assertEqual(i('dA'), float('0'))
        self.assertEqual(i('cA'), float('0'))
        self.assertEqual(i('mA'), float('0'))
        self.assertEqual(i('μA'), float('0'))
        self.assertEqual(i('nA'), float('0'))
        self.assertEqual(i('pA'), float('0'))
        self.assertEqual(i('fA'), float('0'))
        self.assertEqual(i('aA'), float('0'))

    def test_electric_currency(self):
        i = quantity.ElectricCurrency(1, 'A')

        self.assertEqual(i('EA'), float('1e-18'))
        self.assertEqual(i('PA'), float('1e-15'))
        self.assertEqual(i('TA'), float('1e-12'))
        self.assertEqual(i('GA'), float('1e-9'))
        self.assertEqual(i('MA'), float('1e-6'))
        self.assertEqual(i('kA'), float('1e-3'))
        self.assertEqual(i('hA'), float('1e-2'))
        self.assertEqual(i('daA'), float('1e-1'))
        self.assertEqual(i('A'), float('1'))
        self.assertEqual(i('dA'), float('10'))
        self.assertEqual(i('cA'), float('100.'))
        self.assertEqual(i('mA'), float('1000.'))
        self.assertEqual(i('μA'), float('1e6'))
        self.assertAlmostEqual(i('nA'), float('1e9'), delta=1e-3)
        self.assertEqual(i('pA'), float('1e12'))
        self.assertAlmostEqual(i('fA'), float('1e15'), delta=1e0)
        self.assertAlmostEqual(i('aA'), float('1e18'), delta=1e3)

    def test_electric_currency_233(self):
        i = quantity.ElectricCurrency(2.33, 'A')

        self.assertAlmostEqual(i('EA'), float('2.33e-18'), delta=1e-3)
        self.assertAlmostEqual(i('PA'), float('2.33e-15'), delta=1)
        self.assertEqual(i('TA'), float('2.33e-12'))
        self.assertEqual(i('GA'), float('2.33e-9'))
        self.assertEqual(i('MA'), float('2.33e-6'))
        self.assertEqual(i('kA'), float('2.33e-3'))
        self.assertEqual(i('hA'), float('2.33e-2'))
        self.assertEqual(i('daA'), float('2.33e-1'))
        self.assertEqual(i('A'), float('2.33'))
        self.assertEqual(i('dA'), float('23.3'))
        self.assertEqual(i('cA'), float('233.'))
        self.assertEqual(i('mA'), float('2330.'))
        self.assertEqual(i('μA'), float('2.33e6'))
        self.assertEqual(i('nA'), float('2.33e9'))
        self.assertEqual(i('pA'), float('2.33e12'))
        self.assertEqual(i('fA'), float('2.33e15'))
        self.assertEqual(i('aA'), float('2.33e18'))

    # NONE SI

    def test_si_length_m_to_in_ft_mi(self):
        l = quantity.Length(1, 'm')

        self.assertAlmostEqual(l('in'), float('39.37'), delta=1e-4)
        self.assertAlmostEqual(l('ft'), float('3.2808'), delta=1e-4)
        self.assertAlmostEqual(l('mi'), float('0.000621'), delta=1e-4)

    def test_si_length_m_to_in_ft_mi_233(self):
        l = quantity.Length(2.33, 'm')

        self.assertAlmostEqual(l('in'), float('91.7322'), delta=1e-4)
        self.assertAlmostEqual(l('ft'), float('7.6443'), delta=1e-4)
        self.assertAlmostEqual(l('mi'), float('0.00144'), delta=1e-4)

    def test_none_si_length_inch_to_ft_mi(self):
        l = quantity.Length(1, 'in')

        self.assertAlmostEqual(l('ft'), float('0.0833'), delta=1e-2)
        self.assertAlmostEqual(l('mi'), float('1.578e-5'), delta=1e-2)
        self.assertAlmostEqual(l('in'), float('1'), delta=1e-2)

    def test_none_si_length_inch_to_ft_mi_233(self):
        l = quantity.Length(2.33, 'in')

        self.assertAlmostEqual(l('ft'), float('0.1941'), delta=1e-4)
        self.assertAlmostEqual(l('mi'), float('3.677e-5'), delta=1e-2)
        self.assertAlmostEqual(l('in'), float('2.33'), delta=1e-2)

    def test_none_si_length_inch_in_to_prefix_m(self):
        l = quantity.Length(1, 'in')

        self.assertEqual(l('Em'), float('0.0254e-18'))
        self.assertEqual(l('Pm'), float('0.0254e-15'))
        self.assertAlmostEqual(l('Tm'), float('0.0254e-12'), delta=1e-6)
        self.assertEqual(l('Gm'), float('0.0254e-9'))
        self.assertEqual(l('Mm'), float('0.0254e-6'))
        self.assertEqual(l('km'), float('0.0254e-3'))
        self.assertEqual(l('hm'), float('0.0254e-2'))
        self.assertEqual(l('dam'), float('0.0254e-1'))
        self.assertEqual(l('m'), float('0.0254'))
        self.assertEqual(l('dm'), float('0.0254e1'))
        self.assertEqual(l('cm'), float('0.0254e2'))
        self.assertEqual(l('mm'), float('0.0254e3'))
        self.assertEqual(l('μm'), float('0.0254e6'))
        self.assertAlmostEqual(l('nm'), float('0.0254e9'), delta=1e-6)
        self.assertEqual(l('pm'), float('0.0254e12'))
        self.assertAlmostEqual(l('fm'), float('0.0254e15'), delta=1)
        # self.assertAlmostEqual(l('am'), float('0.0254e18'), delta=1000)

    @unittest.skip("inch to prefix_yard")
    def test_non_si_length(self):
        l = quantity.Length(1, 'in')
        self.assertEqual(l('Eyd'), float('0.02778993435448577680525164114e-18'))
        self.assertEqual(l('Pyd'), float('0.02778993435448577680525164114e-15'))
        self.assertEqual(l('Tyd'), float('0.02778993435448577680525164114e-12'))
        self.assertEqual(l('Gyd'), float('0.02778993435448577680525164114e-9'))
        self.assertEqual(l('Myd'), float('0.02778993435448577680525164114e-6'))
        self.assertEqual(l('kyd'), float('0.02778993435448577680525164114e-3'))
        self.assertEqual(l('hyd'), float('0.02778993435448577680525164114e-2'))
        self.assertEqual(l('dayd'), float('0.02778993435448577680525164114e-1'))
        self.assertEqual(l('yd'), float('0.02778993435448577680525164114'))
        self.assertEqual(l('dyd'), float('0.02778993435448577680525164114e1'))
        self.assertEqual(l('cyd'), float('0.02778993435448577680525164114e2'))
        self.assertEqual(l('myd'), float('0.02778993435448577680525164114e3'))
        self.assertEqual(l('μyd'), float('0.02778993435448577680525164114e6'))
        self.assertEqual(l('nyd'), float('0.02778993435448577680525164114e9'))
        self.assertEqual(l('pyd'), float('0.02778993435448577680525164114e12'))
        self.assertEqual(l('fyd'), float('0.02778993435448577680525164114e15'))
        self.assertEqual(l('ayd'), float('0.02778993435448577680525164114e18'))

    def test_mass_g_to_oz_lb_t(self):
        m = quantity.Mass(1, 'g')

        self.assertAlmostEqual(m('oz'), float('0.0352'), delta=1e-4)
        self.assertAlmostEqual(m('lb'), float('0.0022'), delta=1e-4)
        self.assertEqual(m('t'), float('1e-6'))

    def test_mass_g_to_oz_lb_t_233(self):
        m = quantity.Mass(2.33, 'g')

        self.assertAlmostEqual(m('oz'), float('0.0821'), delta=1e-4)
        self.assertAlmostEqual(m('lb'), float('0.00513'), delta=1e-4)
        self.assertEqual(m('t'), float('2.33e-6'))

    def test_time_from_s_to_min(self):
        t = quantity.Time(30, "s")
        self.assertEqual(t('min'), float('0.5'))

    def test_time_from_min_to_s(self):
        t = quantity.Time(1.0, "min")
        self.assertEqual(t('s'), float('60'))

    def test_time_from_hour_to_s(self):
        t = quantity.Time(1.0, "h")
        self.assertEqual(t('s'), float('3600'))

    def test_time_from_s_to_hour(self):
        t = quantity.Time(3600, "s")
        self.assertEqual(t('h'), float('1'))

    def test_time_from_d_to_s(self):
        t = quantity.Time(1.0, "d")
        self.assertEqual(t('s'), float('86400.'))

    def test_time_from_s_to_d(self):
        t = quantity.Time(43200, "s")
        self.assertEqual(t('d'), float('0.5'))

    def test_time_from_day_to_hour(self):
        t = quantity.Time(1, "d")
        self.assertEqual(t('h'), float("24"))

    def test_time_from_hour_to_day(self):
        t = quantity.Time(48, "h")
        self.assertEqual(t('d'), float("2"))

    def test_aos(self):
        n = quantity.AmountOfSubstance(1.0, 'kmol')
        self.assertEqual(n('mol'), 1000.0)

    def test_temperature_from_K(self):
        t = quantity.Temperature(0.0, 'K')
        self.assertEqual(t('K'), float('0.0'))
        self.assertEqual(t('°C'), float('-273.15'))
        self.assertEqual(t('°F'), float('-459.67'))

    def test_temperature_from_K_233(self):
        t = quantity.Temperature(2.33, 'K')
        self.assertEqual(t('K'), float('2.33'))
        self.assertEqual(t('°C'), float('-270.82'))
        self.assertEqual(t('°F'), float('-455.476'))

    def test_temperature_from_C(self):
        t = quantity.Temperature(-40.0, '°C')
        self.assertEqual(t('°C'), float('-40.0'))
        self.assertAlmostEqual(t('K'), float('233.15'), delta=1e-9)
        self.assertAlmostEqual(t('°F'), float('-40.0'), delta=1e-9)

    def test_temperature_from_F(self):
        t = quantity.Temperature(-40.0, '°F')
        self.assertAlmostEqual(t('K'), float('233.15'), delta=1e-9)
        self.assertAlmostEqual(t('°C'), float('-40.0'), delta=1e-9)


class TestQuantityBaseUnitComparison(unittest.TestCase):
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


class TestQuantityDerivedUnitComparison(unittest.TestCase):
    # Acceleration

    def test_comparing_derived_with_derived_acceleration_equal(self):
        a1 = quantity.Acceleration(1, "m s-2")
        a2 = quantity.Acceleration(1, "m s-2")

        self.assertTrue(a1 == a2)
        self.assertTrue(a1 <= a2)
        self.assertTrue(a1 >= a2)
        self.assertFalse(a1 > a2)
        self.assertFalse(a1 < a2)
        self.assertFalse(a1 != a2)

    def test_comparing_derived_with_derived_acceleration_greater(self):
        a1 = quantity.Acceleration(2, "m s-2")
        a2 = quantity.Acceleration(1, "m s-2")

        self.assertFalse(a1 == a2)
        self.assertFalse(a1 <= a2)
        self.assertTrue(a1 >= a2)
        self.assertTrue(a1 > a2)
        self.assertFalse(a1 < a2)
        self.assertTrue(a1 != a2)

    def test_comparing_derived_with_derived_acceleration_less(self):
        a1 = quantity.Acceleration(1, "m s-2")
        a2 = quantity.Acceleration(2, "m s-2")

        self.assertFalse(a1 == a2)
        self.assertTrue(a1 <= a2)
        self.assertFalse(a1 >= a2)
        self.assertFalse(a1 > a2)
        self.assertTrue(a1 < a2)
        self.assertTrue(a1 != a2)

    # FORCE

    def test_comparing_derived_with_derived_force_equal(self):
        f1 = quantity.Force(1, "kg m s-2")
        f2 = quantity.Force(1, "kg m s-2")

        self.assertTrue(f1 == f2)
        self.assertTrue(f1 <= f2)
        self.assertTrue(f1 >= f2)
        self.assertFalse(f1 > f2)
        self.assertFalse(f1 < f2)
        self.assertFalse(f1 != f2)

    def test_comparing_derived_with_derived_force_greater(self):
        f1 = quantity.Force(2, "kg m s-2")
        f2 = quantity.Force(1, "kg m s-2")

        self.assertFalse(f1 == f2)
        self.assertFalse(f1 <= f2)
        self.assertTrue(f1 >= f2)
        self.assertTrue(f1 > f2)
        self.assertFalse(f1 < f2)
        self.assertTrue(f1 != f2)

    def test_comparing_derived_with_derived_force_less(self):
        f1 = quantity.Force(1, "kg m s-2")
        f2 = quantity.Force(2, "kg m s-2")

        self.assertFalse(f1 == f2)
        self.assertTrue(f1 <= f2)
        self.assertFalse(f1 >= f2)
        self.assertFalse(f1 > f2)
        self.assertTrue(f1 < f2)
        self.assertTrue(f1 != f2)

    # MOLARCCONCENTRATION

    def test_comparing_derived_with_derived_molar_concentration_equal(self):
        c1 = quantity.MolarConcentration(1, "mol m-3")
        c2 = quantity.MolarConcentration(1, "mol m-3")

        self.assertTrue(c1 == c2)
        self.assertTrue(c1 <= c2)
        self.assertTrue(c1 >= c2)
        self.assertFalse(c1 > c2)
        self.assertFalse(c1 < c2)
        self.assertFalse(c1 != c2)

    def test_comparing_derived_with_derived_molar_concentration_greater(self):
        c1 = quantity.MolarConcentration(2, "mol m-3")
        c2 = quantity.MolarConcentration(1, "mol m-3")

        self.assertFalse(c1 == c2)
        self.assertFalse(c1 <= c2)
        self.assertTrue(c1 >= c2)
        self.assertTrue(c1 > c2)
        self.assertFalse(c1 < c2)
        self.assertTrue(c1 != c2)

    def test_comparing_derived_with_derived_molar_concentration_less(self):
        c1 = quantity.MolarConcentration(1, "mol m-3")
        c2 = quantity.MolarConcentration(2, "mol m-3")

        self.assertFalse(c1 == c2)
        self.assertTrue(c1 <= c2)
        self.assertFalse(c1 >= c2)
        self.assertFalse(c1 > c2)
        self.assertTrue(c1 < c2)
        self.assertTrue(c1 != c2)


class TestQuantityValidUnit(unittest.TestCase):
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


class TestQuantityAddition(unittest.TestCase):
    def test_adding_mass_to_mass(self):
        m1 = quantity.Mass(1000., "g")
        m2 = quantity.Mass(1., "kg")
        m3 = m1 + m2

        self.assertEqual(m3.value, 2000.)
        self.assertEqual(m3.unit, "g")
        self.assertFalse(id(m1) == id(m3))
        self.assertFalse(id(m2) == id(m3))


class TestQuantityDerivedUnitsConversion(unittest.TestCase):
    def test_convert_velocity_from_mps_to_kmph(self):
        v = quantity.Velocity(1.0, 'm s-1')
        self.assertEqual(v('km h-1'), float('3.6'))

    def test_convert_velocity_from_kmph_to_kmph(self):
        v = quantity.Velocity(3.6, 'km h-1')
        self.assertEqual(v('km h-1'), float('3.6'))

    def test_convert_velocity_from_kmph_to_mps(self):
        v = quantity.Velocity(3.6, 'km h-1')
        self.assertEqual(v('m s-1'), float('1.'))

    def test_convert_velocity_from_miph_to_kmph(self):
        v = quantity.Velocity(1., 'mi h-1')
        self.assertEqual(v('km h-1'), float('1.609344'))

    def test_convert_area_from_inch2_to_yd2(self):
        a = quantity.Area(2.33, 'in2')
        self.assertAlmostEqual(a('yd2'), float('0.00179783951'), delta=1e-3)

    def test_convert_area_from_m2_to_are(self):
        a = quantity.Area(200, 'm2')
        self.assertAlmostEqual(a('are'), float('2'), delta=1e-3)

    def test_convert_area_from_acre_to_are(self):
        a = quantity.Area(1, 'ac')
        self.assertAlmostEqual(a('are'), float('40.4684'), delta=1e-3)

    def test_converting_volume_from_m3_to_in3(self):
        v = quantity.Volume(1, 'm3')
        self.assertAlmostEqual(v('cm3'), float('1000000.'), delta=1e-6)
        self.assertAlmostEqual(v('gal'), float('264.1720526372959086633370175'), delta=1e-6)
        self.assertAlmostEqual(v("in3"), float('61023.74409473228395275688189'), delta=1e-6)

    def test_converting_volumetric_flow_from_m3ph_to(self):
        v = quantity.VolumetricFlow(1.0, 'm3 h-1')
        self.assertAlmostEqual(v('m3 d-1'), float('24.0'), delta=1e-6)
        self.assertAlmostEqual(v('gal min-1'), float('4.402867543954931811055616958'), delta=1e-6)
        self.assertAlmostEqual(v('l s-1'), float('0.2777777777777777777777777778'), delta=1e-6)

    def test_converting_acceleration(self):
        a = quantity.Acceleration(1.0, 'm s-2')
        self.assertEqual(a('in s-2'), float('39.37007874015748031496062992'))
        self.assertEqual(a('in ms-2'), float('0.00003937007874015748031496062992'))

    def test_convert_force(self):
        f = quantity.Force(1.0, 'kg m s-2')
        self.assertEqual(f('lb yd s-2'), float('2.412061728866277343179999663'))

    def test_convert_concentration(self):
        c = quantity.Concentration(1., 'mg l-1')
        self.assertAlmostEqual(c('mg dm-3'), float('1.0'), delta=1e-6)
        self.assertAlmostEqual(c('g m-3'), float('1.0'), delta=1e-6)


class test_derived_units_from_base_units(unittest.TestCase):
    def test_acceleration_from_l_t_zero(self):
        l = quantity.Length(0, "m")
        t = quantity.Time(1, "s")
        a1 = l / (t * t)
        a2 = l / (t ** 2)
        a3 = l / t / t

        self.assertIsInstance(a1, quantity.Acceleration)
        self.assertIsInstance(a2, quantity.Acceleration)
        self.assertIsInstance(a3, quantity.Acceleration)

    def test_acceleration_from_l_t(self):
        l = quantity.Length(1, "m")
        t = quantity.Time(1, "s")
        a1 = l / (t * t)
        a2 = l / (t ** 2)
        a3 = l / t / t

        self.assertIsInstance(a1, quantity.Acceleration)
        self.assertIsInstance(a2, quantity.Acceleration)
        self.assertIsInstance(a3, quantity.Acceleration)

    def test_acceleration_from_l_t_none_zero(self):
        l = quantity.Length(2.33, "m")
        t = quantity.Time(2.33, "s")
        a1 = l / (t * t)
        a2 = l / (t ** 2)
        a3 = l / t / t

        self.assertAlmostEqual(a1('m s-2'), float('0.4229'), delta=1e-2)
        self.assertAlmostEqual(a2('m s-2'), float('0.4229'), delta=1e-2)
        self.assertAlmostEqual(a3('m s-2'), float('0.4229'), delta=1e-2)

    def test_force_from_m_a_zero(self):
        m = quantity.Mass(0, "g")
        a = quantity.Acceleration(0, 'm s-2')
        f1 = m * a
        self.assertIsInstance(f1, quantity.Force)
        self.assertEqual(f1('kg m s-2'), float('0.'))

    def test_force_from_m_a(self):
        m = quantity.Mass(1, "kg")
        a = quantity.Acceleration(1, 'm s-2')
        f1 = m * a
        self.assertEqual(f1('kg m s-2'), float('1'))

    def test_force_from_m_a_233(self):
        m = quantity.Mass(2.33, "kg")
        a = quantity.Acceleration(1, 'm s-2')
        f1 = m * a
        self.assertEqual(f1('kg m s-2'), float('2.33'))

    def test_volumetricflow_zero(self):
        v = quantity.Volume(0, 'm3')
        t = quantity.Time(1, 'h')
        vf = v / t
        self.assertIsInstance(vf, quantity.VolumetricFlow)
        self.assertEqual(vf('m3 h-1'), float('0.'))

    def test_volumetricflow_(self):
        l = quantity.Length(1, 'm')
        v1 = l * l * l
        v2 = l ** 3
        t = quantity.Time(1, 'h')
        vf1 = v1 / t
        vf2 = v2 / t
        vf3 = l * l * l / t
        self.assertIsInstance(vf1, quantity.VolumetricFlow)
        self.assertEqual(vf1('m3 h-1'), float('1.'))

        self.assertIsInstance(vf2, quantity.VolumetricFlow)
        self.assertEqual(vf2('m3 h-1'), float('1.'))

        self.assertIsInstance(vf3, quantity.VolumetricFlow)
        self.assertEqual(vf3('m3 h-1'), float('1.'))

    def test_volumetricflow_233(self):
        l = quantity.Length(2.33, 'm')
        v = quantity.Volume(12.649, "m3")
        l1 = l * l * l
        t = quantity.Time(2.33, 'h')
        vf1 = l1 / t
        vf2 = v / t
        self.assertIsInstance(vf1, quantity.VolumetricFlow)
        self.assertAlmostEqual(vf1('m3 h-1'), float('5.4289'), delta=1e-6)

        self.assertIsInstance(vf2, quantity.VolumetricFlow)
        self.assertAlmostEqual(vf2('m3 h-1'), float('5.4289'), delta=1e-3)


    def test_molar_concentration_from_n_l_v_zero(self):
        l = quantity.Length(1, 'm')
        v = quantity.Volume(1, 'm3')
        n = quantity.AmountOfSubstance(0, "mol")
        mc1 = n / (l * l * l)
        mc2 = n / (l ** 3)
        mc3 = n / l / l / l
        mc4 = n / v

        self.assertIsInstance(mc1, quantity.MolarConcentration)
        self.assertIsInstance(mc2, quantity.MolarConcentration)
        self.assertIsInstance(mc3, quantity.MolarConcentration)
        self.assertIsInstance(mc4, quantity.MolarConcentration)

        self.assertEqual(mc1('mol m-3'), float('0.'))
        self.assertEqual(mc2('mol m-3'), float('0.'))
        self.assertEqual(mc3('mol m-3'), float('0.'))
        self.assertEqual(mc4('mol m-3'), float('0.'))


    def test_molar_concentration_from_n_l_v(self):
        l = quantity.Length(1, 'm')
        v = quantity.Volume(1, 'm3')
        n = quantity.AmountOfSubstance(1, "mol")
        mc1 = n / (l * l * l)
        mc2 = n / (l ** 3)
        mc3 = n / l / l / l
        mc4 = n / v

        self.assertEqual(mc1('mol m-3'), float('1.'))
        self.assertEqual(mc2('mol m-3'), float('1.'))
        self.assertEqual(mc3('mol m-3'), float('1.'))
        self.assertEqual(mc4('mol m-3'), float('1.'))


    def test_molar_concentration_from_n_l_v_233(self):
        l = quantity.Length(2.33, 'm')
        v = quantity.Volume(12.649, 'm3')
        n = quantity.AmountOfSubstance(1, "mol")
        mc1 = n / (l * l * l)
        mc2 = n / (l ** 3)
        mc3 = n / l / l / l
        mc4 = n / v

        self.assertAlmostEqual(mc1('mol m-3'), float('0.0790'), delta=1e-3)
        self.assertAlmostEqual(mc2('mol m-3'), float('0.0790'), delta=1e-3)
        self.assertAlmostEqual(mc3('mol m-3'), float('0.0790'), delta=1e-3)
        self.assertAlmostEqual(mc4('mol m-3'), float('0.0790'), delta=1e-3)


class TestDerivedUnitName(unittest.TestCase):
    def test_velocity_name_m_per_s(self):
        v = quantity.Velocity(2, 'm s-1')
        self.assertEquals(str(v), "2.0 m s\u207B\u00B9")

    def test_velocity_name_km_per_h(self):
        v = quantity.Velocity(2, 'km h-1')
        self.assertEquals(str(v), "2.0 km h\u207B\u00B9")

    def test_velocity_name_km_per_h_(self):
        v = quantity.Velocity(2, 'h-1 km')
        self.assertEquals(str(v), "2.0 km h\u207B\u00B9")

    @unittest.skip("m/s=m /s")
    def test_velocity_name(self):
        v = quantity.Velocity(2, 'm/s')
        self.assertEquals(str(v), "2.0 ms\u207B\u00B9")

    def test_volume_name(self):
        v = quantity.Volume(2, 'm')
        self.assertEquals(str(v), '2.0 m\u00B3')

        v = quantity.Volume(2, 'dm')
        self.assertEquals(str(v), '2.0 dm\u00B3')

    @unittest.skip("l!=l3")
    def test_volume_name_l_l3(self):
        v = quantity.Volume(2, 'l')
        self.assertEquals(str(v), '2.0 l')

    def test_area_name_m2(self):
        a = quantity.Area(2, "m2")
        self.assertEquals(str(a), '2.0 m\u00B2')

    @unittest.skip("2m!=m2")
    def test_area_name_2m(self):
        a = quantity.Area(2, "2m")
        self.assertNotEquals(str(a), '2.0 m\u00B2')

    def test_volumetric_flow_name_m3_h(self):
        vf = quantity.VolumetricFlow(2, "m3 h-1")
        self.assertEquals(str(vf), "2.0 m\u00B3 h\u207B\u00B9")

    def test_volumetric_flow_name_inch3_s(self):
        vf = quantity.VolumetricFlow(2, "in3 h-1")
        self.assertEquals(str(vf), "2.0 in\u00B3 h\u207B\u00B9")

    @unittest.skip("3m h-1!=m3 h-1")
    def test_volumetric_flow_name_m3_h(self):
        vf = quantity.VolumetricFlow(2, "3m h-1")
        self.assertNotEquals(str(vf), "2.0 m\u00B3 h\u207B\u00B9"),

    def test_acceleration_name_m_s2(self):
        a = quantity.Acceleration(2, "m s2")
        self.assertEquals(str(a), "2.0 m s\u207B\u00B2")

    @unittest.skip("kg m s-2!=m kg s-2")
    def test_force_name_kg_m_s2(self):
        f = quantity.Force(2, "kg m s-2")
        self.assertEquals(str(f), "2.0 kg m s\u207B\u00B2")

    @unittest.skip("mg m-3!=,m-3 mg")
    def test_concentration_name_mg_m3(self):
        c = quantity.Concentration(2, "mg m-3")
        self.assertEquals(str(c), "2.0 mg m\u207B\u00B3")

    @unittest.skip("mg l-1!=l-3 mg")
    def test_concentration_name_mg_l(self):
        c = quantity.Concentration(2, "mg l-1")
        self.assertEquals(str(c), "2.0 mg l\u207B\u00B9")
