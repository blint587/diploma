import unittest
import munits.unitnotation as unitnotation


class TestDerivedUnitName(unittest.TestCase):
    def test_01(self):
        l = unitnotation.UnitNotation("m", "1")
        m = unitnotation.UnitNotation("kg", "1")
        self.assertTrue(m > l)
        self.assertFalse(l > m)
