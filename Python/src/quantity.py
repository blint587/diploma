import inspect
import sys
import operator
from decimal import Decimal
from src.converters import Converter, LengthConvert, MassConvert, TimeConvert,  TemperatureConvert, AreaConvert, VolumeConvert


class UnitNotation:

    superscripts = {
        '-': '\u207B',
        '0': '\u2070',
        '1': '\u00B9',
        '2': '\u00B2',
        '3': '\u00B3',
        '4': '\u2074',
        '5': '\u2075',
        '6': '\u2076',
        '7': '\u2077',
        '8': '\u2078',
        '9': '\u2079'
    }

    def __init__(self, unotation, exponent: str):
        self.__unotation = unotation
        self.__exponent = exponent

    @property
    def notation(self):
        return self.__unotation

    @property
    def exponent(self):
        return int(self.__exponent)

    def __str__(self):
        if self.exponent != 1:
            exp = self.__exponent
            for n in self.superscripts.keys():
                exp = exp.replace(n, self.superscripts.get(n))
        else:
            exp = ""
        return '{}{}'.format(self.notation, exp)


class Quantity:
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
    _converter = Converter("")

    def __init__(self, value, unit):
        if isinstance(unit, str):
            if unit in self._converter.valid_units():
                self._value = Decimal(value)
                self._unit = unit
            else:
                raise ValueError()  # TODO: add proper exception
        elif isinstance(unit, list) and len(unit) == 7:
            self._value = Decimal(value)
            self._unit = self.__unit_constructor(self.dim_vector, unit)

    @staticmethod
    def __type_search(dim_vector):
        clslist = list(filter(lambda x: x[1].dim_vector == dim_vector, LIST_OF_CLASSES))
        cls = clslist[0][1] if len(clslist) == 1 else Quantity
        return cls

    def __dimension_determination(self, other, op):
        dim_vector = tuple([op(sq, other.dim_vector[index]) for index, sq in enumerate(self.dim_vector)])
        unit_vector = [uv + other.unit_vector[index] if uv != other.unit_vector[index] else uv for index, uv in
                       enumerate(self.unit_vector)]

        return dim_vector, unit_vector

    def __truediv__(self, other):
        if isinstance(other, Quantity):

            dim_vector, unit_vector = self.__dimension_determination(other, operator.sub)

            new = self.__type_search(dim_vector)(self.value / other.value, "")
            new.dim_vector = dim_vector
            new.unit_vector = unit_vector
            return new
        else:
            raise TypeError

    def __mul__(self, other):
        if isinstance(other, Quantity):
            dim_vector, unit_vector = self.__dimension_determination(other, operator.add)

            new = self.__type_search(dim_vector)(self.value * other.value,
                                                 self.__unit_constructor(dim_vector, unit_vector))
            new.dim_vector = dim_vector
            new.unit_vector = unit_vector
            return new
        else:
            raise TypeError()  # TODO: add proper exception

    def __math_operation_1(self, other, op):
        if isinstance(other, self.__class__):
            new = self.__class__(op(self.value, other(self.unit)), self.unit)
            return new
        else:
            TypeError()  # TODO: add proper exception

    def __add__(self, other):
        return self.__math_operation_1(other, operator.add)

    def __sub__(self, other):
        return self.__math_operation_1(other, operator.sub)

    def __str__(self):
        return "{0} {1}".format(self.value, self.unit)

    @property
    def value(self):
        return self._value

    @property
    def unit(self):
        return self.__unit_constructor(self.dim_vector, self.unit_vector)

    @staticmethod
    def __unit_constructor(dim_vector, unit_vector):
        return " ".join(
            filter(lambda x: x, ["{}{}".format(unit, dim_vector[index] if dim_vector[index] != 1 else "")
                                 if unit else "" for index, unit in enumerate(unit_vector)]))

    @classmethod
    def is_valid_unit(cls, unit):
        units = cls._converter.valid_units()
        return unit in units

    def __call__(self, unit):
        """

        :param unit:
        :return:
        """
        return self._converter(self.value, self.unit, unit)

    def __comparison_operation(self, rghsv, op):
        """

        :param rghsv:
        :param op:
        :return:
        """
        if type(self) == type(rghsv):
            return op(self(self._converter.base_unit), rghsv(self._converter.base_unit))
        else:
            raise TypeError("something")

    def __eq__(self, other):
        return self.__comparison_operation(other, operator.eq)

    def __le__(self, other):
        return self.__comparison_operation(other, operator.le)

    def __ge__(self, other):
        return self.__comparison_operation(other, operator.ge)

    def __lt__(self, other):
        return self.__comparison_operation(other, operator.lt)

    def __gt__(self, other):
        return self.__comparison_operation(other, operator.gt)

    def __ne__(self, other):
        return self.__comparison_operation(other, operator.ne)


class Length(Quantity):
    dim_vector = (1, 0, 0, 0, 0, 0, 0)
    _converter = LengthConvert("m")

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit, )
        self.unit_vector = [unit, "", "", "", "", "", ""]


class Mass(Quantity):
    dim_vector = (0, 1, 0, 0, 0, 0, 0)
    _converter = MassConvert("g")

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)
        self.unit_vector = ["", unit, "", "", "", "", ""]


class Time(Quantity):
    dim_vector = (0, 0, 1, 0, 0, 0, 0)
    _converter = TimeConvert("s")

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit, )
        self.unit_vector = ["", "", unit, "", "", "", ""]


class ElectricCurrency(Quantity):
    dim_vector = (0, 0, 0, 1, 0, 0, 0)
    _converter = Converter("A")

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)
        self.unit_vector = ["", "", "", unit, "", "", ""]


class Temperature(Quantity):
    # https://en.wikipedia.org/wiki/Conversion_of_units_of_temperature
    dim_vector = (0, 0, 0, 0, 1, 0, 0)
    _converter = TemperatureConvert("K")

    # TODO: implement Temperature Delta

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)
        self.unit_vector = ["", "", "", "", unit, "", ""]


class AmountOfSubstance(Quantity):
    dim_vector = (0, 0, 0, 0, 0, 1, 0)
    _converter = Converter("mol")

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)
        self.unit_vector = ["", "", "", "", "", unit, ""]


class LuminousIntensity(Quantity):
    dim_vector = (0, 0, 0, 0, 0, 0, 1)
    _converter = Converter("cd")

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
    _converter = AreaConvert("m2")

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class Volume(Quantity):
    dim_vector = (3, 0, 0, 0, 0, 0, 0)
    _converter = VolumeConvert("m3")

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class VolumetrikFlow(Quantity):
    dim_vector = (3, 0, -1, 0, 0, 0, 0)

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


LIST_OF_CLASSES = list(
    filter(lambda cls: Quantity in cls[1].mro(), inspect.getmembers(sys.modules[__name__], inspect.isclass)))
