# encoding: utf-8
from collections import defaultdict
from munitscpp import PyQuantity, NPOS
from base2.base import BaseClass


CLASS_REGISTRY = defaultdict(list)


class Register(type):
    def __new__(mcs, name, bases, class_dict):
        cls = type.__new__(mcs, name, bases, class_dict)
        CLASS_REGISTRY[cls.UNIT_INDEX].append(cls)
        return cls


class Quantity(PyQuantity, BaseClass, metaclass=Register):
    UNIT_INDEX = NPOS

    def __new__(cls, value=0., unit="", *, other=None, transform=False):

        if other is None:
            ob = super().__new__(cls, cls.UNIT_INDEX, value, unit)
            return ob
        elif transform and (cls.UNIT_INDEX == other.__class__.UNIT_INDEX):
            ob = super().__new__(cls, other=other)
            return ob
        else:
            ncls = CLASS_REGISTRY[other.matrix_index][0]
            ob = super().__new__(ncls, other=other)
            return ob

    def __mul__(self, other):
        n = Quantity(other=PyQuantity.__mul__(self, other))
        if n._unquantified:
            return float(n)
        return n

    def __add__(self, other):
        return Quantity(other=PyQuantity.__add__(self, other))

    def __sub__(self, other):
        return Quantity(other=PyQuantity.__sub__(self, other))

    def __truediv__(self, other):
        n = Quantity(other=PyQuantity.__truediv__(self, other))
        if n._unquantified:
            return float(n)
        return n

    def __call__(self, unit):
        return PyQuantity.__call__(self, unit)

    def __pow__(self, power, modulo=None):
        return Quantity(other=PyQuantity.__pow__(self, int(power), modulo))

    def __rshift__(self, other):
        if issubclass(other, Quantity) and self.UNIT_INDEX == other.UNIT_INDEX:
            self.__class__ = other

    def __reduce__(self):
        return self.__class__, (self.val, self.unit)

    def __str__(self):
        return PyQuantity.__str__(self)

    def serializable(self):
        return {"value": self.val, "unit": self.unit}


class Length(Quantity):
    UNIT_INDEX = 0


class Mass(Quantity):
    UNIT_INDEX = 1


class Time(Quantity):
    UNIT_INDEX = 2


class ElectricCurrency(Quantity):
    UNIT_INDEX = 3


class Temperature(Quantity):
    UNIT_INDEX = 4


class AmountOfSubstance(Quantity):
    UNIT_INDEX = 5


class LuminousIntensity(Quantity):
    UNIT_INDEX = 6


class Area(Quantity):
    UNIT_INDEX = 7


class Volume(Quantity):
    UNIT_INDEX = 8


class VolumetricFlow(Quantity):
    UNIT_INDEX = 9


class MolarConcentration(Quantity):
    UNIT_INDEX = 10


class Acceleration(Quantity):
    UNIT_INDEX = 11


class Force(Quantity):
    UNIT_INDEX = 12


class Velocity(Quantity):
    UNIT_INDEX = 13


class Concentration(Quantity):
    UNIT_INDEX = 14


class Density(Quantity):
    UNIT_INDEX = 14


class MassFlow(Quantity):
    UNIT_INDEX = 15


class Pressure(Quantity):
    UNIT_INDEX = 16


class DynamicViscosity(Quantity):
    UNIT_INDEX = 17


class KinematicViscosity(Quantity):
    UNIT_INDEX = 18


class Power(Quantity):
    UNIT_INDEX = 19


class Energy(Quantity):
    UNIT_INDEX = 20


class Voltage(Quantity):
    UNIT_INDEX = 21


class Frequency(Quantity):
    UNIT_INDEX = 22


class ElectricCharge(Quantity):
    UNIT_INDEX = 23


class ElectricCapacitance(Quantity):
    UNIT_INDEX = 24


class ElectricResistance(Quantity):
    UNIT_INDEX = 25


class ElectricalConductance(Quantity):
    UNIT_INDEX = 26


class MagneticFlux(Quantity):
    UNIT_INDEX = 27


class MagneticFluxDensity(Quantity):
    UNIT_INDEX = 28


class Inductance(Quantity):
    UNIT_INDEX = 29


class Illuminance(Quantity):
    UNIT_INDEX = 30


class Radioactivity(Quantity):
    UNIT_INDEX = 22


class AbsorbedDose(Quantity):
    UNIT_INDEX = 31


class EquivalentDose(Quantity):
    UNIT_INDEX = 31


class CatalyticActivity(Quantity):
    UNIT_INDEX = 32


class Torque(Quantity):
    UNIT_INDEX = 20



if __name__ == "__main__":

    i = ElectricCurrency(1, "A")
    # print(i)

    u = Voltage(1, "V")
    print(u)

    # r = u * i
    # print(type(r))
