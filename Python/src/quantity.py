import inspect
import sys
import operator
from decimal import Decimal
from fractions import Fraction

import re


class Converter:
    class ConverterFunction():
        def __init__(self, v):
            self.__v = v

        def normal(self, conv):
            return conv * self.__v

        def invers(self, conv):
            return conv / self.__v

    prefixes = {
        "E": ConverterFunction(Decimal("1e18")),  # exa
        "P": ConverterFunction(Decimal("1e15")),  # peta
        "T": ConverterFunction(Decimal("1e12")),  # tera
        "G": ConverterFunction(Decimal("1e9")),  # giga
        "M": ConverterFunction(Decimal("1e6")),  # mega
        "k": ConverterFunction(Decimal("1e3")),  # kilo
        "h": ConverterFunction(Decimal("1e2")),  # hecto
        "da": ConverterFunction(Decimal("1e1")),  # deca
        "d": ConverterFunction(Decimal("0.1")),  # deci
        "c": ConverterFunction(Decimal("0.01")),  # centi
        "m": ConverterFunction(Decimal("0.001")),  # milli
        "μ": ConverterFunction(Decimal("0.000001")),  # micro
        "n": ConverterFunction(Decimal("0.000000001")),  # nano
        "p": ConverterFunction(Decimal("0.000000000001")),  # pico
        "f": ConverterFunction(Decimal("0.000000000000001")),  # femto
        "a": ConverterFunction(Decimal("0.000000000000000001"))  # atto
    }

    def __init__(self, base_unit):
        self.__base_unit = base_unit

    def __call__(self, val, funit: str, tunit: str):
        default = Converter.ConverterFunction(Decimal("1.0"))
        to_base_func = self.prefixes.get(self.__prefix_parser(funit), default)
        in_base = to_base_func.normal(val)

        from_base_func = self.prefixes.get(self.__prefix_parser(tunit), default)
        res = from_base_func.invers(in_base)

        return res

    def __prefix_parser(self, unit: str):
        prefix = re.sub(r'{}$'.format(self.__base_unit), "", unit, count=1)
        return prefix


class Quantity():
    """
    # 1. length
    # 2. mass
    # 3. time
    # 4. electric_current
    # 5. temperature
    # 6. amount_of_substance
    # 7. luminous_intensity
    """
    dim_vector = (0, 0, 0, 0, 0, 0, 0)
    unit_vector = ["", "", "", "", "", "", ""]
    base_unit = ""

    def __init__(self, value, unit):
        self._value = Decimal(value)
        self._unit = unit
        self._converter = Converter(self.base_unit)

    def __type_search(self, dim_vector):
        clslist = list(filter(lambda x: x[1].dim_vector == dim_vector, LIST_OF_CLASSES))
        cls = clslist[0][1] if len(clslist) == 1 else Quantity
        return cls

    def __operation(self, other, op):
        dim_vector = tuple([op(sq, other.dim_vector[index]) for index, sq in enumerate(self.dim_vector)])
        unit_vector = [uv + other.unit_vector[index] if uv != other.unit_vector[index] else uv for index, uv in
                       enumerate(self.unit_vector)]

        return dim_vector, unit_vector

    def __truediv__(self, other):
        if isinstance(other, Quantity):

            dim_vector, unit_vector = self.__operation(other, operator.sub)

            new = self.__type_search(dim_vector)(self.value / other.value, "")
            new.dim_vector = dim_vector
            new.unit_vector = unit_vector
            return new
        else:
            raise TypeError

    def __str__(self):
        return "{0} {1}".format(self.value, self.unit)

    def __mul__(self, other):
        if isinstance(other, Quantity):
            dim_vector, unit_vector = self.__operation(other, operator.add)

            new = self.__type_search(dim_vector)(self.value * other.value, "")
            new.dim_vector = dim_vector
            new.unit_vector = unit_vector
            return new
        else:
            raise TypeError

    @property
    def value(self):
        return self._value

    @value.setter
    def value(self, x):
        self._value = x

    @property
    def unit(self):
        return " ".join(
            filter(lambda x: x, ["{}{}".format(unit, self.dim_vector[index] if self.dim_vector[index] != 1 else "")
                                 if unit else "" for index, unit in enumerate(self.unit_vector)]))

    def __call__(self, unit):

        return self._converter(self.value, self.unit, unit)


class Length(Quantity):
    dim_vector = (1, 0, 0, 0, 0, 0, 0)
    base_unit = "m"

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)
        self.unit_vector = [unit, "", "", "", "", "", ""]


class Mass(Quantity):
    dim_vector = (0, 1, 0, 0, 0, 0, 0)
    base_unit = "g"

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)
        self.unit_vector = ["", unit, "", "", "", "", ""]


class Time(Quantity):
    dim_vector = (0, 0, 1, 0, 0, 0, 0)
    base_unit = "s"

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)
        self.unit_vector = ["", "", unit, "", "", "", ""]


class ElectricCurrency(Quantity):
    dim_vector = (0, 0, 0, 1, 0, 0, 0)
    base_unit = "A"

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)
        self.unit_vector = ["", "", "", unit, "", "", ""]


class Temperature(Quantity):
    dim_vector = (0, 0, 0, 0, 1, 0, 0)
    base_unit = "K"

    # TODO: implement Temperature Delta
    class TemperatureConvert(Converter):
        class TempConverterFunction(Converter.ConverterFunction):

            # noinspection PyMissingConstructor
            def __init__(self, a, b):
                self.__a = a
                self.__b = b

            def normal(self, conv):
                return (self.__a * conv) + self.__b

            def invers(self, conv):
                return conv * self.__a**-1 - self.__b

        prefixes = {
                "K": TempConverterFunction(Decimal('1.0'), Decimal('0.0')),
                "°C": TempConverterFunction(Decimal('1.0'), Decimal('273.15')),
                "°F": TempConverterFunction(Decimal(5/9), Decimal('459.67'))
        }

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)
        self.unit_vector = ["", "", "", "", unit, "", ""]
        self._converter = Temperature.TemperatureConvert(base_unit=Temperature.base_unit)


class AmountOfSubstance(Quantity):
    dim_vector = (0, 0, 0, 0, 0, 1, 0)
    base_unit = "mol"

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)
        self.unit_vector = ["", "", "", "", "", unit, ""]


class LuminousIntensity(Quantity):
    dim_vector = (0, 0, 0, 0, 0, 0, 1)
    base_unit = "cd"

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)
        self.unit_vector = ["", "", "", "", "", "", unit]


class Velocity(Quantity):
    dim_vector = (1, 0, -1, 0, 0, 0, 0)

    # unit_vector = ["", "", "", "", "", "", ""]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class Area(Quantity):
    dim_vector = (2, 0, 0, 0, 0, 0, 0)

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class Volume(Quantity):
    dim_vector = (3, 0, 0, 0, 0, 0, 0)

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class VolumetrikFlow(Quantity):
    dim_vector = (3, 0, -1, 0, 0, 0, 0)

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


LIST_OF_CLASSES = list(
    filter(lambda cls: Quantity in cls[1].mro(), inspect.getmembers(sys.modules[__name__], inspect.isclass)))
