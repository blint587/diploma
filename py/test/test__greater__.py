import unittest
import munits.unitnotation as unitnotation


class TestDerivedUnitName(unittest.TestCase):

    def test_same_prefix_one(self):
        l = unitnotation.UnitNotation("m", "1")
        m = unitnotation.UnitNotation("kg", "1")
        self.assertTrue(m > l)
        self.assertFalse(l > m)

    def test_pos_prefix_gt_1(self):
        l = unitnotation.UnitNotation("m", "2")
        m = unitnotation.UnitNotation("kg", "1")
        self.assertTrue(l>m)
        self.assertFalse(l<m)

    @unittest.skip("2m!=m2")
    def test_neg_prefix(self):
        l = unitnotation.UnitNotation("K", "-1")
        m = unitnotation.UnitNotation("kg", "-1")
        self.assertTrue(m>l)
        self.assertFalse(l > m)

    def test_neg_prefix(self):
        l = unitnotation.UnitNotation("m", "-2")
        m = unitnotation.UnitNotation("kg", "-1")
        self.assertTrue(m > l)
        self.assertFalse(l > m)