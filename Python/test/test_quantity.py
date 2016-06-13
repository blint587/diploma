# encoding: utf-8
from unittest import TestCase
import src.quantity as quantity


class TestQuantityBaseUnitConversion(TestCase):

    def test_base_unit_conversion_length(self):
        l = quantity.Length(1.0, 'm')

        self.assertEqual(l('Em'), 10**-18)
        self.assertEqual(l('Pm'), 10**-15)
        self.assertEqual(l('Tm'), 10**-12)
        self.assertEqual(l('Gm'), 10**-9)
        self.assertEqual(l('Mm'), 10**-6)
        self.assertEqual(l('km'), 10**-3)
        self.assertEqual(l('hm'), 10**-2)
        self.assertEqual(l('dam'), 0.1)
        self.assertEqual(l('dm'), 10.)
        self.assertEqual(l('cm'), 100.)
        self.assertEqual(l('mm'), 1000.)
        self.assertEqual(l('μm'), 1e6)
        self.assertAlmostEqual(l('nm'), 1e9, delta=0.000001)
        self.assertAlmostEqual(l('pm'), 1e12, delta=0.000001)
        self.assertAlmostEqual(l('fm'), 1e15, delta=0.1)
        self.assertAlmostEqual(l('am'), 1e18, delta=0.000001)

    def test_base_unit_conversion_mass(self):
        m = quantity.Mass(1.0, 'kg')
        self.assertEqual(m('g'), 1000.0)
        self.assertEqual(m('cg'), 100000.0)

    def test_base_unit_conversion_aos(self):
        n = quantity.AmountOfSubstance(1.0, 'kmol')
        self.assertEqual(n('mol'), 1000.0)
