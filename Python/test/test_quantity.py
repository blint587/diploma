# encoding: utf-8
from unittest import TestCase
import src.quantity as quantity
from decimal import Decimal


class TestQuantityBaseUnitConversion(TestCase):

    def test_base_unit_conversion_length(self):
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

    def test_base_unit_conversion_mass(self):
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

    def test_base_unit_conversion_aos(self):
        n = quantity.AmountOfSubstance(1.0, 'kmol')
        self.assertEqual(n('mol'), 1000.0)

    def test_base_unit_conversion_temperature_from_K(self):
        t = quantity.Temperature(0.0, 'K')
        self.assertEqual(t('K'), Decimal('0.0'))
        self.assertEqual(t('°C'), Decimal('-273.15'))
        self.assertEqual(t('°F'), Decimal('-459.67'))

    def test_base_unit_conversion_temperature_from_C(self):
        t = quantity.Temperature(-40.0, '°C')
        self.assertEqual(t('°C'), Decimal('-40.0'))
        self.assertAlmostEqual(t('°F'), Decimal('-40.0'), delta=0.000000000001)