# encoding: utf-8
import unittest

from munits.quantities import *


class TestOperationInSameUnit(unittest.TestCase):

    def test_add_in_same_unit_add_to_one(self):

        l = Length(1, "m")
        nl = l.add_in_same_unit(1)
        self.assertEqual(nl, Length(2, "m"))

    def test_add_in_same_unit_add_to_zero(self):

        l = Length(0, "m")
        nl = l.add_in_same_unit(1)
        self.assertEqual(nl, Length(1, "m"))

    def test_add_in_same_unit_add_to_arbitrary_number(self):

        l = Length(25, "m")
        nl = l.add_in_same_unit(1)
        self.assertEqual(nl, Length(26, "m"))

    def test_subtract_in_same_unit_subtract_from_one(self):

        l = Length(1, "m")
        nl = l.subtract_in_same_unit(1)
        self.assertEqual(nl, Length(0, "m"))

    def test_subtract_in_same_unit_subtract_from_two(self):

        l = Length(2, "m")
        nl = l.subtract_in_same_unit(1)
        self.assertEqual(nl, Length(1, "m"))

    def test_subtract_in_same_unit_subtract_from_arbitrary_number(self):

        l = Length(25, "m")
        nl = l.subtract_in_same_unit(1)
        self.assertEqual(nl, Length(24, "m"))

