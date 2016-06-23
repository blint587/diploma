# encoding: utf-8
import unittest

import munits.quantity as quantity

class TestDerivedUnitName(unittest.TestCase):
    def test_velocity_name_m_per_s(self):
        v = quantity.Velocity(2, 'm s-1')
        self.assertEquals(str(v), "2.0 m s\u207B\u00B9")

    def test_velocity_name_km_per_h(self):
        v = quantity.Velocity(2, 'km h-1')
        self.assertEquals(str(v), "2.0 km h\u207B\u00B9")

    def test_velocity_name_km_per_h_(self):
        v = quantity.Velocity(2, 'h-1 km')
        self.assertEquals(str(v), "2.0 km h\u207B\u00B9")

    def test_velocity_name(self):
        self.assertRaises(Exception, quantity.Velocity, 2, 'm/s')


    def test_volume_name(self):
        v = quantity.Volume(2, 'm')
        self.assertEquals(str(v), '2.0 m\u00B3')

        v = quantity.Volume(2, 'dm')
        self.assertEquals(str(v), '2.0 dm\u00B3')

    # @unittest.skip("l!=l3")
    def test_volume_name_l_l3(self):
        v = quantity.Volume(2, 'cl')
        self.assertEquals(str(v), '2.0 cl')

    def test_area_name_m2(self):
        a = quantity.Area(2, "m2")
        self.assertEquals(str(a), '2.0 m\u00B2')

    @unittest.skip("2m!=m2")
    def test_area_name_2m(self):
        a = quantity.Area(2, "2m")
        self.assertRaises(Exception )

    def test_volumetric_flow_name_m3_h(self):
        vf = quantity.VolumetricFlow(2, "m3 h-1")
        self.assertEquals(str(vf), "2.0 m\u00B3 h\u207B\u00B9")

    def test_volumetric_flow_name_inch3_s(self):
        vf = quantity.VolumetricFlow(2, "in3 h-1")
        self.assertEquals(str(vf), "2.0 in\u00B3 h\u207B\u00B9")

    @unittest.skip("3m h-1!=m3 h-1")
    def test_volumetric_flow_name_m3_h(self):
        vf = quantity.VolumetricFlow(2, "3m h-1")
        self.assertNotEquals(str(vf), "2.0 m\u00B3 h\u207B\u00B9"),

    def test_acceleration_name_m_s2(self):
        a = quantity.Acceleration(2, "m s2")
        self.assertEquals(str(a), "2.0 m s\u207B\u00B2")

    # @unittest.skip("kg m s-2!=m kg s-2")
    def test_force_name_kg_m_s2(self):
        f = quantity.Force(2, "kg m s-2")
        self.assertEquals(str(f), "2.0 kg m s\u207B\u00B2")

    @unittest.skip("mg m-3!= m-3 mg")
    def test_concentration_name_mg_m3(self):
        c = quantity.Concentration(2, "mg m-3")
        self.assertEquals(str(c), "2.0 mg m\u207B\u00B3")

    @unittest.skip("mg l-1!=l-3 mg")
    def test_concentration_name_mg_l(self):
        c = quantity.Concentration(2, "mg l-1")
        self.assertEquals(str(c), "2.0 mg l\u207B\u00B9")
