# encoding: utf-8
import unittest

from munits import Mass, Length, Time, Acceleration, Force, Volume, VolumetricFlow, AmountOfSubstance, \
    MolarConcentration


class TestQuantityAddition(unittest.TestCase):
    def test_adding_mass_to_mass(self):
        m1 = Mass(1000., "g")
        m2 = Mass(1., "kg")
        m3 = m1 + m2

        self.assertFalse(id(m1) == id(m3))
        self.assertFalse(id(m2) == id(m3))


class TestDerivedUnitsFromBaseUnits(unittest.TestCase):
    def test_acceleration_from_l_t_zero(self):
        l = Length(0, "m")
        t = Time(1, "s")
        a1 = l / (t * t)
        a2 = l / (t ** 2)
        a3 = l / t / t

        self.assertIsInstance(a1, Acceleration)
        self.assertIsInstance(a2, Acceleration)
        self.assertIsInstance(a3, Acceleration)

    def test_acceleration_from_l_t(self):
        l = Length(1, "m")
        t = Time(1, "s")
        a1 = l / (t * t)
        a2 = l / (t ** 2)
        a3 = l / t / t

        self.assertIsInstance(a1, Acceleration)
        self.assertIsInstance(a2, Acceleration)
        self.assertIsInstance(a3, Acceleration)

    def test_acceleration_from_l_t_none_zero(self):
        l = Length(2.33, "m")
        t = Time(2.33, "s")
        a1 = l / (t * t)
        a2 = l / (t ** 2)
        a3 = l / t / t

        self.assertAlmostEqual(a1('m s-2'), float('0.4229'), delta=1e-2)
        # noinspection PyCallingNonCallable
        self.assertAlmostEqual(a2('m s-2'), float('0.4229'), delta=1e-2)
        self.assertAlmostEqual(a3('m s-2'), float('0.4229'), delta=1e-2)

    def test_force_from_m_a_zero(self):
        m = Mass(0, "g")
        a = Acceleration(0, 'm s-2')
        f1 = m * a
        self.assertIsInstance(f1, Force)
        self.assertEqual(f1('kg m s-2'), float('0.'))

    def test_force_from_m_a(self):
        m = Mass(1, "kg")
        a = Acceleration(1, 'm s-2')
        f1 = m * a
        self.assertEqual(f1('kg m s-2'), float('1'))

    def test_force_from_m_a_233(self):
        m = Mass(2.33, "kg")
        a = Acceleration(1, 'm s-2')
        f1 = m * a
        self.assertEqual(f1('kg m s-2'), float('2.33'))

    def test_volumetricflow_zero(self):
        v = Volume(0, 'm3')
        t = Time(1, 'h')
        vf = v / t
        self.assertIsInstance(vf, VolumetricFlow)
        self.assertEqual(vf('m3 h-1'), float('0.'))

    def test_volumetricflow_(self):
        l = Length(1, 'm')
        t = Time(1, 'h')

        v1 = l * l * l
        v2 = l ** 3
        vf1 = v1 / t
        vf2 = v2 / t
        vf3 = l * l * l / t

        self.assertIsInstance(vf1, VolumetricFlow)
        self.assertEqual(vf1('m3 h-1'), float('1.'))

        self.assertIsInstance(vf2, VolumetricFlow)
        self.assertEqual(vf2('m3 h-1'), float('1.'))

        self.assertIsInstance(vf3, VolumetricFlow)
        self.assertEqual(vf3('m3 h-1'), float('1.'))

    def test_volumetricflow_233(self):
        l = Length(2.33, 'm')
        v = Volume(12.649, "m3")
        l1 = l * l * l
        t = Time(2.33, 'h')
        vf1 = l1 / t
        vf2 = v / t
        self.assertIsInstance(vf1, VolumetricFlow)
        self.assertAlmostEqual(vf1('m3 h-1'), float('5.4289'), delta=1e-6)

        self.assertIsInstance(vf2, VolumetricFlow)
        self.assertAlmostEqual(vf2('m3 h-1'), float('5.4289'), delta=1e-3)

    def test_molar_concentration_from_n_l_v_zero(self):
        l = Length(1, 'm')
        v = Volume(1, 'm3')
        n = AmountOfSubstance(0, "mol")
        mc1 = n / (l * l * l)
        mc2 = n / (l ** 3)
        mc3 = n / l / l / l
        mc4 = n / v

        self.assertIsInstance(mc1, MolarConcentration)
        self.assertIsInstance(mc2, MolarConcentration)
        self.assertIsInstance(mc3, MolarConcentration)
        self.assertIsInstance(mc4, MolarConcentration)

        self.assertEqual(mc1('mol m-3'), float('0.'))
        self.assertEqual(mc2('mol m-3'), float('0.'))
        self.assertEqual(mc3('mol m-3'), float('0.'))
        self.assertEqual(mc4('mol m-3'), float('0.'))

    def test_molar_concentration_from_n_l_v(self):
        l = Length(1, 'm')
        v = Volume(1, 'm3')
        n = AmountOfSubstance(1, "mol")
        mc1 = n / (l * l * l)
        mc2 = n / (l ** 3)
        mc3 = n / l / l / l
        mc4 = n / v

        self.assertEqual(mc1('mol m-3'), float('1.'))
        # noinspection PyCallingNonCallable
        self.assertEqual(mc2('mol m-3'), float('1.'))
        self.assertEqual(mc3('mol m-3'), float('1.'))
        self.assertEqual(mc4('mol m-3'), float('1.'))

    def test_molar_concentration_from_n_l_v_233(self):
        l = Length(2.33, 'm')
        v = Volume(12.649, 'm3')
        n = AmountOfSubstance(1, "mol")
        mc1 = n / (l * l * l)
        mc2 = n / (l ** 3)
        mc3 = n / l / l / l
        mc4 = n / v

        self.assertAlmostEqual(mc1('mol m-3'), float('0.0790'), delta=1e-3)
        # noinspection PyCallingNonCallable
        self.assertAlmostEqual(mc2('mol m-3'), float('0.0790'), delta=1e-3)
        self.assertAlmostEqual(mc3('mol m-3'), float('0.0790'), delta=1e-3)
        self.assertAlmostEqual(mc4('mol m-3'), float('0.0790'), delta=1e-3)