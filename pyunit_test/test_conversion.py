# encoding: utf-8
import unittest

from munits import Length, Mass, Time, ElectricCurrent, AmountOfSubstance, Temperature, Velocity, Area, Volume, \
    VolumetricFlow, Acceleration, Force, Concentration


class TestQuantityBaseUnitConversion(unittest.TestCase):
    def test_length_zero(self):
        l = Length(0, 'm')

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
        l = Length(1.0, 'm')

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
        l = Length(2.33, 'm')

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
        m = Mass(0, 'g')

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
        m = Mass(1.0, 'g')

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
        m = Mass(2.33, 'g')

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
        t = Time(0.0, 's')

        self.assertEqual(t('ms'), float('0'))
        self.assertEqual(t('μs'), float('0'))
        self.assertEqual(t('ns'), float('0'))
        self.assertEqual(t('ps'), float('0'))
        self.assertEqual(t('fs'), float('0'))
        self.assertEqual(t('as'), float('0'))

    def test_time(self):
        t = Time(1.0, 's')

        self.assertEqual(t('ms'), float('1000.'))
        self.assertEqual(t('μs'), float('1e6'))
        self.assertAlmostEqual(t('ns'), float('1e9'), delta=1e-6)
        self.assertEqual(t('ps'), float('1e12'))
        self.assertAlmostEqual(t('fs'), float('1e15'), delta=1)
        # self.assertAlmostEqual(t('as'), float('1e18'), delta=1000)

    def test_time_233(self):
        t = Time(2.33, 's')

        self.assertEqual(t('ms'), float('2330.'))
        self.assertEqual(t('μs'), float('2.33e6'))
        self.assertEqual(t('ns'), float('2.33e9'))
        self.assertEqual(t('ps'), float('2.33e12'))
        self.assertEqual(t('fs'), float('2.33e15'))
        self.assertEqual(t('as'), float('2.33e18'))

    # ELECTRIC_CURRENT

    def test_electric_currency_zero(self):
        i = ElectricCurrent(0, 'A')

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
        i = ElectricCurrent(1, 'A')

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
        i = ElectricCurrent(2.33, 'A')

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
        l = Length(1, 'm')

        self.assertAlmostEqual(l('inc'), float('39.37'), delta=1e-4)
        self.assertAlmostEqual(l('ft'), float('3.2808'), delta=1e-4)
        self.assertAlmostEqual(l('mi'), float('0.000621'), delta=1e-4)

    def test_si_length_m_to_in_ft_mi_233(self):
        l = Length(2.33, 'm')

        self.assertAlmostEqual(l('inc'), float('91.7322'), delta=1e-4)
        self.assertAlmostEqual(l('ft'), float('7.6443'), delta=1e-4)
        self.assertAlmostEqual(l('mi'), float('0.00144'), delta=1e-4)

    def test_none_si_length_inch_to_ft_mi(self):
        l = Length(1, 'inc')

        self.assertAlmostEqual(l('ft'), float('0.0833'), delta=1e-2)
        self.assertAlmostEqual(l('mi'), float('1.578e-5'), delta=1e-2)
        self.assertAlmostEqual(l('inc'), float('1'), delta=1e-2)

    def test_none_si_length_inch_to_ft_mi_233(self):
        l = Length(2.33, 'inc')

        self.assertAlmostEqual(l('ft'), float('0.1941'), delta=1e-4)
        self.assertAlmostEqual(l('mi'), float('3.677e-5'), delta=1e-2)
        self.assertAlmostEqual(l('inc'), float('2.33'), delta=1e-2)

    def test_none_si_length_inch_in_to_prefix_m(self):
        l = Length(1, 'inc')

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

    # @unittest.skip("inch to prefix_yard")
    def test_non_si_length(self):
        l = Length(1, 'inc')
        self.assertEqual(l('Eyd'), float('0.027789934354485773e-18'))
        self.assertEqual(l('Pyd'), float('0.02778993435448577680525164114e-15'))
        self.assertEqual(l('Tyd'), float('2.778993435448577e-14'))
        self.assertEqual(l('Gyd'), float('0.02778993435448577680525164114e-9'))
        self.assertEqual(l('Myd'), float('2.7789934354485775e-08'))
        self.assertEqual(l('kyd'), float('2.7789934354485775e-05'))
        self.assertEqual(l('hyd'), float('0.0002778993435448577'))
        self.assertEqual(l('dayd'), float('0.02778993435448577680525164114e-1'))
        self.assertEqual(l('yd'), float('0.027789934354485773'))
        self.assertEqual(l('dyd'), float('0.27789934354485774'))
        self.assertEqual(l('cyd'), float('0.02778993435448577680525164114e2'))
        self.assertEqual(l('myd'), float('27.789934354485773'))
        self.assertEqual(l('μyd'), float('27789.934354485773'))
        self.assertEqual(l('nyd'), float('27789934.35448577'))
        self.assertEqual(l('pyd'), float('27789934354.485775'))
        self.assertEqual(l('fyd'), float('27789934354485.77'))
        self.assertEqual(l('ayd'), float('2.7789934354485772e+16'))

    def test_mass_g_to_oz_lb_t(self):
        m = Mass(1, 'g')

        self.assertAlmostEqual(m('oz'), float('0.0352'), delta=1e-4)
        self.assertAlmostEqual(m('lb'), float('0.0022'), delta=1e-4)
        self.assertEqual(m('t'), float('1e-6'))

    def test_mass_g_to_oz_lb_t_233(self):
        m = Mass(2.33, 'g')

        self.assertAlmostEqual(m('oz'), float('0.0821'), delta=1e-4)
        self.assertAlmostEqual(m('lb'), float('0.00513'), delta=1e-4)
        self.assertEqual(m('t'), float('2.33e-6'))

    def test_time_from_s_to_min(self):
        t = Time(30, "s")
        self.assertEqual(t('min'), float('0.5'))

    def test_time_from_min_to_s(self):
        t = Time(1.0, "min")
        self.assertEqual(t('s'), float('60'))

    def test_time_from_hour_to_s(self):
        t = Time(1.0, "h")
        self.assertEqual(t('s'), float('3600'))

    def test_time_from_s_to_hour(self):
        t = Time(3600, "s")
        self.assertEqual(t('h'), float('1'))

    def test_time_from_d_to_s(self):
        t = Time(1.0, "d")
        self.assertEqual(t('s'), float('86400.'))

    def test_time_from_s_to_d(self):
        t = Time(43200, "s")
        self.assertEqual(t('d'), float('0.5'))

    def test_time_from_day_to_hour(self):
        t = Time(1, "d")
        self.assertEqual(t('h'), float("24"))

    def test_time_from_hour_to_day(self):
        t = Time(48, "h")
        self.assertEqual(t('d'), float("2"))

    def test_aos(self):
        n = AmountOfSubstance(1.0, 'kmol')
        self.assertEqual(n('mol'), 1000.0)

    def test_temperature_from_K(self):
        t = Temperature(0.0, 'K')
        self.assertEqual(t('K'), float('0.0'))
        self.assertEqual(t('°C'), float('-273.15'))
        self.assertEqual(t('°F'), float('-459.67'))

    def test_temperature_from_K_233(self):
        t = Temperature(2.33, 'K')
        self.assertEqual(t('K'), float('2.33'))
        self.assertEqual(t('°C'), float('-270.82'))
        self.assertEqual(t('°F'), float('-455.476'))

    def test_temperature_from_C(self):
        t = Temperature(-40.0, '°C')
        self.assertEqual(t('°C'), float('-40.0'))
        self.assertAlmostEqual(t('K'), float('233.15'), delta=1e-9)
        self.assertAlmostEqual(t('°F'), float('-40.0'), delta=1e-9)

    def test_temperature_from_F(self):
        t = Temperature(-40.0, '°F')
        self.assertAlmostEqual(t('K'), float('233.15'), delta=1e-9)
        self.assertAlmostEqual(t('°C'), float('-40.0'), delta=1e-9)


class TestQuantityDerivedUnitsConversion(unittest.TestCase):
    def test_convert_velocity_from_mps_to_kmph(self):
        v = Velocity(1.0, 'm s-1')
        self.assertEqual(v('km h-1'), float('3.6'))

    def test_convert_velocity_from_kmph_to_kmph(self):
        v = Velocity(3.6, 'km h-1')
        self.assertEqual(v('km h-1'), float('3.6'))

    def test_convert_velocity_from_kmph_to_mps(self):
        v = Velocity(3.6, 'km h-1')
        self.assertEqual(v('m s-1'), float('1.'))

    def test_convert_velocity_from_miph_to_kmph(self):
        v = Velocity(1., 'mi h-1')
        self.assertEqual(v('km h-1'), float('1.609344'))

    def test_convert_area_from_inch2_to_yd2(self):
        a = Area(2.33, 'inc2')
        self.assertAlmostEqual(a('yd2'), float('0.00179783951'), delta=1e-3)

    # def test_convert_area_from_m2_to_are(self):
    #     a = quantity.Area(200, 'm2')
    #     self.assertAlmostEqual(a('are'), float('2'), delta=1e-3)

    # def test_convert_area_from_acre_to_are(self):
    #     a = quantity.Area(1, 'ac')
    #     self.assertAlmostEqual(a('are'), float('40.4684'), delta=1e-3)

    def test_converting_volume_from_m3_to_in3(self):
        v = Volume(1, 'm3')
        self.assertAlmostEqual(v('cm3'), float('1000000.'), delta=1e-6)
        self.assertAlmostEqual(v('gal'), float('264.1720526372959086633370175'), delta=1e-6)
        self.assertAlmostEqual(v("inc3"), float('61023.74409473228395275688189'), delta=1e-6)

    def test_converting_volumetric_flow_from_m3ph_to(self):
        v = VolumetricFlow(1.0, 'm3 h-1')
        self.assertAlmostEqual(v('m3 d-1'), float('24.0'), delta=1e-6)
        self.assertAlmostEqual(v('gal min-1'), float('4.402867543954931811055616958'), delta=1e-6)
        self.assertAlmostEqual(v('l s-1'), float('0.2777777777777777777777777778'), delta=1e-6)

    def test_converting_acceleration(self):
        a = Acceleration(1.0, 'm s-2')
        self.assertEqual(a('inc s-2'), float('39.37007874015748031496062992'))
        self.assertEqual(a('inc ms-2'), float('0.00003937007874015748031496062992'))

    def test_convert_force(self):
        f = Force(1.0, 'kg m s-2')
        self.assertEqual(f('lb yd s-2'), float('2.412061728866277343179999663'))

    def test_convert_concentration(self):
        c = Concentration(1., 'mg l-1')
        self.assertAlmostEqual(c('mg dm-3'), float('1.0'), delta=1e-1)
        self.assertAlmostEqual(c('g m-3'), float('1.0'), delta=1e-6)