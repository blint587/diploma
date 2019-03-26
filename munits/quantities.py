# encoding: utf-8
from collections import defaultdict
from weakref import WeakKeyDictionary
from munitscpp import PyQuantity, NPOS
from base2.base import BaseClass


class TypeIndex:
    """
    TypeIndex descriptor
    """

    def __init__(self):
        self.__class_data = WeakKeyDictionary()

    def __get__(self, instance, owner):
        if instance is None:
            return self
        return self.__class_data[instance]

    def __set__(self, instance, value):
        if 0 <= value <= NPOS and instance not in self.__class_data.keys():
            self.__class_data[instance] = value
        elif 0 > value or value > NPOS:
            raise ValueError("Type index is out of range when defining <{}>.".format(instance))
        elif instance in self.__class_data.keys():
            raise AttributeError("Cannot overwrite 'type_index' attribute!")


class MetaQuantity(type):
    CLASS_REGISTRY = defaultdict(list)

    type_index = TypeIndex()

    def __new__(mcs, name, bases, class_dict, *, unit_index: int, **kwargs):
        cls = type.__new__(mcs, name, bases, class_dict)
        cls.type_index = unit_index
        MetaQuantity.CLASS_REGISTRY[unit_index].append(cls)
        return cls

    def __init__(cls, name, bases, class_dict, **kwargs):
        super().__init__(name, bases, class_dict)


class Quantity(PyQuantity, BaseClass, metaclass=MetaQuantity, unit_index=NPOS):
    # UNIT_INDEX = NPOS

    def __new__(cls, value=None, unit=None, *, other=None, transform=False):

        if (other is None) and (unit is not None) and (value is not None):
            ob = super().__new__(cls, cls.type_index, value, unit)
            return ob
        elif transform and (cls.type_index == other.__class__.type_index):
            ob = super().__new__(cls, other=other)
            return ob
        elif other is not None:
            ncls = MetaQuantity.CLASS_REGISTRY[other.matrix_index][0]
            ob = super().__new__(ncls, other=other)
            return ob
        else:
            raise TypeError("Inadequate parameter list.")

    def __mul__(self, other):
        if isinstance(other, Quantity) or isinstance(other, int) or isinstance(other, float):
            n = Quantity(other=PyQuantity.__mul__(self, other))
            if n._unquantified:
                return float(n)
            return n
        else:
            return NotImplemented

    def __rmul__(self, other):
        return self.__mul__(other)

    def __add__(self, other):
        if isinstance(other, Quantity):
            return Quantity(other=PyQuantity.__add__(self, other))
        else:
            return NotImplemented

    def __radd__(self, other):
        return self.__add__(other)

    def __sub__(self, other):
        if isinstance(other, Quantity):
            return Quantity(other=PyQuantity.__sub__(self, other))
        else:
            return NotImplemented

    def __rsub__(self, other):
        if isinstance(other, Quantity):
            return other - self
        else:
            return NotImplemented

    def __truediv__(self, other):
        n = Quantity(other=PyQuantity.__truediv__(self, other))
        if n._unquantified:
            return float(n)
        return n

    def __call__(self, unit):
        return PyQuantity.__call__(self, unit)

    def __pow__(self, power, modulo=None):
        return Quantity(other=PyQuantity.__pow__(self, int(power), modulo))

    def __rshift__(self, other: MetaQuantity):
        if issubclass(other, Quantity) and self.__class__.type_index == other.type_index:
            self.__class__ = other

    def __reduce__(self):
        return self.__class__, (self.val, self.unit)

    def __str__(self):
        return PyQuantity.__str__(self)

    def __repr__(self):
        return PyQuantity.__repr__(self)

    def serializable(self, *args, **kwargs):
        if self.init_unit != "":
            s = {"value": self(self.init_unit), "unit": self.init_unit}
        else:
            s = {"value": self.val, "unit": self.unit}
        return s

    def __hash__(self):
        return (7 + hash(self.val)) * 31 + hash(str(self.unit))

    def __abs__(self):
        return self.__class__(abs(self.val), self.unit)

    def ntrt(self, exp: int):
        return Quantity(other=PyQuantity.ntrt(self, int(exp)))

    def convert(self, _unit: str) -> "Quantity":
        return self.__class__.__new__(self.__class__, value=self(_unit), unit=_unit)

    def add_in_same_unit(self, other: float):
        """
        :param other: The amount you want to add.
        :type other: float
        :return: Quantity
        """
        n = self.__class__(value=other, unit=self.unit)
        return self + n

    def subtract_in_same_unit(self, other: float):
        """
        :param other: The amount you want to subtract.
        :type other: float
        :return: Quantity
        """
        n = self.__class__(value=other, unit=self.unit)
        return self - n


class Length(Quantity, unit_index=0):
    pass


class Mass(Quantity, unit_index=1):
    pass


class Time(Quantity, unit_index=2):
    pass


class ElectricCurrency(Quantity, unit_index=3):
    pass


class Temperature(Quantity, unit_index=4):
    pass


class AmountOfSubstance(Quantity, unit_index=5):
    pass


class LuminousIntensity(Quantity, unit_index=6):
    pass


class Area(Quantity, unit_index=7):
    pass


class Volume(Quantity, unit_index=8):
    pass


class VolumetricFlow(Quantity, unit_index=9):
    pass


class MolarConcentration(Quantity, unit_index=10):
    pass


class Acceleration(Quantity, unit_index=11):
    pass


class Force(Quantity, unit_index=12):
    pass


class Velocity(Quantity, unit_index=13):
    pass


class Concentration(Quantity, unit_index=14):
    pass


class Density(Quantity, unit_index=14):
    pass


class MassFlow(Quantity, unit_index=15):
    pass


class Pressure(Quantity, unit_index=16):
    pass


class DynamicViscosity(Quantity, unit_index=17):
    pass


class KinematicViscosity(Quantity, unit_index=18):
    pass


class Power(Quantity, unit_index=19):
    pass


class Energy(Quantity, unit_index=20):
    pass


class Voltage(Quantity, unit_index=21):
    pass


class Frequency(Quantity, unit_index=22):
    pass


class ElectricCharge(Quantity, unit_index=23):
    pass


class ElectricCapacitance(Quantity, unit_index=24):
    pass


class ElectricResistance(Quantity, unit_index=25):
    pass


class ElectricalConductance(Quantity, unit_index=26):
    pass


class MagneticFlux(Quantity, unit_index=27):
    pass


class MagneticFluxDensity(Quantity, unit_index=28):
    pass


class Inductance(Quantity, unit_index=29):
    pass


class Illuminance(Quantity, unit_index=30):
    pass


class Radioactivity(Quantity, unit_index=22):
    pass


class AbsorbedDose(Quantity, unit_index=31):
    pass


class EquivalentDose(Quantity, unit_index=31):
    pass


class CatalyticActivity(Quantity, unit_index=32):
    pass


class Torque(Quantity, unit_index=20):
    pass


class MolarWeight(Quantity, unit_index=33):
    pass


class EnergyFlux(Quantity, unit_index=34):
    pass


class EnergyPerArea(Quantity, unit_index=35):
    pass


class MassFlux(Quantity, unit_index=36):
    pass


class AreaDensity(Quantity, unit_index=37):
    pass

if __name__ == "__main__":

    i = AreaDensity(1, "gsm")
    print(i)

    # r = u * i
    # print(type(r))
