# encoding: utf-8
from unittest import TestCase
from munits import Pressure

class TestBasicInitialization(TestCase):


    def test_hPa_initialization(self):
        try:
            p = Pressure(1, "hPa")
        except Exception as ex:
            self.fail(str(ex))


