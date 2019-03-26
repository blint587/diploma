# encoding: utf-8
import unittest

from munits.quantities import *


#
# class TestQuantityValidUnit(unittest.TestCase):
#     def test_valid_mass_unit(self):
#         self.assertTrue(Mass.is_valid_unit("kg"))
#
#     def test_invalid_mass_unit(self):
#         self.assertFalse(Mass.is_valid_unit("tg"))
#
#     def test_valid_time_unit_second(self):
#         self.assertTrue(Time.is_valid_unit("s"))
#
#     def test_invalid_time_unit_second(self):
#         self.assertFalse(Time.is_valid_unit("ts"))
#
#     def test_valid_temperature_unit(self):
#         self.assertTrue(Temperature.is_valid_unit("°C"))


class TestQuantitySideFunctionality(unittest.TestCase):

    def test_deepcopy(self):
        from copy import deepcopy
        l = Length(1, "m")
        l_copy = deepcopy(l)

        self.assertEqual(l, l_copy)
        self.assertNotEqual(id(l), id(l_copy))


    def test_convert(self):
        """Happy pass"""

        l1 = Length(1., "m")
        l2 = l1.convert("mm")

        self.assertEqual(l1, l2)
        self.assertEqual("mm", l2.unit,)
        self.assertEqual(1000.,  l2.val)
        self.assertNotEqual(id(l1), id(l2))


if __name__ == "__main__":
    unittest.main()
