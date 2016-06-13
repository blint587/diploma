import inspect
import sys
import operator

import re


class Converter:
    class ConverterFunction():
        def __init__(self, v):
            self.__v = v

        def normal(self, conv):
            return conv * self.__v

        def invers(self, conv):
            return conv / self.__v

    si_prefixes = {
        "E": ConverterFunction(1e18),  # exa
        "P": ConverterFunction(1e15),  # peta
        "T": ConverterFunction(1e12),  # tera
        "G": ConverterFunction(1e9),  # giga
        "M": ConverterFunction(1e6),  # mega
        "k": ConverterFunction(1e3),  # kilo
        "h": ConverterFunction(1e2),  # hecto
        "da": ConverterFunction(1e1),  # deca
        "d": ConverterFunction(10 ** -1),  # deci
        "c": ConverterFunction(10 ** -2),  # centi
        "m": ConverterFunction(10 ** -3),  # milli
        "μ": ConverterFunction(10 ** -6),  # micro
        "n": ConverterFunction(10 ** -9),  # nano
        "p": ConverterFunction(10 ** -12),  # pico
        "f": ConverterFunction(10 ** -15),  # femto
        "a": ConverterFunction(10 ** -18)  # atto
    }

    def __init__(self, base_unit):
        self.__base_unit = base_unit

    def __call__(self, val, funit: str, tunit: str):
        default = Converter.ConverterFunction(1.0)

        in_base = self.si_prefixes.get(self.__prefix_parser(funit), default).normal(val)
        res = self.si_prefixes.get(self.__prefix_parser(tunit), default).invers(in_base)

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
        self._value = value
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

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)
        self.unit_vector = ["", "", "", "", unit, "", ""]


class AmountOfSubstance(Quantity):
    dim_vector = (0, 0, 0, 0, 0, 1, 0)
    base_unit = "mol"

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)
        self.unit_vector = ["", "", "", "", "", unit, ""]


class LuminousIntensity(Quantity):
    dim_vector = (0, 0, 0, 0, 0, 0, 1)

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
