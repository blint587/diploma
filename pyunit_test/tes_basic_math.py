# encoding: utf-8
from unittest import TestCase
from munits import Length


class TestBasicMath(TestCase):

    def test_divide_by_zero_float(self):
        l = Length(1, "m")

        with self.assertRaises(ZeroDivisionError):
            l / 0

    def test_divide_by_zero_quantity(self):
        l = Length(1, "m")
        zero = Length(0, "m")
        with self.assertRaises(ZeroDivisionError):
            l / zero
