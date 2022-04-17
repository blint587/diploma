# encoding: utf-8
from unittest import TestCase
from munits import Length, Mass, MassFlow, Volume, VolumetricFlow


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

    def test_subtract_mass_from_mass_flow(self):
        m = Mass(1, "kg")
        mq = MassFlow(1, "kg h-1")

        with self.assertRaises(TypeError):
            r = mq - m

    def test_add_volume_to_volumetric_flow(self):
        v = Volume(1, "m3")
        q = VolumetricFlow(1, "m3 h-1")

        with self.assertRaises(TypeError):
            r = v + q


