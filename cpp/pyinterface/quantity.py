# encoding: utf-8
from munitscpp import PyQuantity, NPOS
import sys
import inspect


class Quantity(PyQuantity):
    UNIT_INDEX = NPOS

    def __new__(cls, value=0., unit="", other=None):
        if other is None:
            return super().__new__(cls, cls.UNIT_INDEX, value, unit)
        else:
            ncls = list(filter(lambda c: c[1].UNIT_INDEX == other.matrix_index, LIST_OF_CLASSES))[0][1]
            return super().__new__(ncls, other=other)

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


LIST_OF_CLASSES = list(
    filter(lambda cls: issubclass(cls[1], Quantity) or cls is Quantity,
           inspect.getmembers(sys.modules[__name__], inspect.isclass)))

if __name__ == "__main__":
    a = VolumetricFlow(234.08, "m3 d-1")
    b = VolumetricFlow(234.08, "m3 d-1")
    print(a == b)
