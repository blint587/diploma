import copy
import inspect
import sys
import operator
# from decimal import float
from munits.unitnotation import UnitNotation
from munits.converters import (Converter, LengthConvert, MassConvert,
                               TimeConvert, TemperatureConvert, AreaConvert,
                               VolumeConvert)


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

    def __init__(self, value, unit, check_unit=True):

        if value is None:
            self._value = - float('inf')
        else:
            self._value = float(str(value))
        if isinstance(unit, str):
            self._unit = unit
            self.unit_vector = Quantity.__compose_unit(unit, self.dim_vector, check_unit)

        elif isinstance(unit, list) and len(unit) == 7:
            self._unit = self.__unit_rep(self.dim_vector, unit)
        else:
            raise Exception()  # TODO: raise some proper exceptions

    @staticmethod
    def __type_search(dim_vector):
        """
        Searches the proper quantity type based on the dimension vector.
        :param dim_vector:
        :return:
        """
        if isinstance(dim_vector, list):
            dim_vector = tuple(dim_vector)
        clslist = list(filter(lambda x: x[1].dim_vector == dim_vector, LIST_OF_CLASSES))
        cls = clslist[0][1] if len(clslist) == 1 else Quantity
        return cls

    def __dimension_determination(self, other, op):
        """
        Merges dimension- and unit wector during operation multiply and divide.
        :param other:
        :param op:
        :return:
        """
        dim_vector = tuple([op(sq, other.dim_vector[index]) for index, sq in enumerate(self.dim_vector)])
        unit_vector = [uv + other.unit_vector[index] if uv != other.unit_vector[index] else uv for index, uv in
                       enumerate(self.unit_vector)]

        return dim_vector, unit_vector

    def __math_operator_2(self, other, op1, op2):
        if isinstance(other, Quantity):
            dim_vector, unit_vector = self.__dimension_determination(other, op1)
            if dim_vector != (0, 0, 0, 0, 0, 0, 0):
                check_unit = True
                cls = self.__type_search(dim_vector)
                new = object.__new__(cls)
                if new.dim_vector == (0, 0, 0, 0, 0, 0, 0):
                    new.dim_vector = dim_vector
                    new.unit_vector = unit_vector
                    check_unit = False

                new.__init__(op2(self.value, other.value), self.__unit_rep(dim_vector, unit_vector), check_unit)
            else:
                new = float(op2(self.value, other(self.unit)))
            return new
        elif isinstance(other, int) or isinstance(other, float) or isinstance(other, float):
            return self.__class__(op2(self.value, float(other)), self.__unit_rep(self.dim_vector, self.unit_vector))
        else:
            raise TypeError("Unsupported type: {}".format(type(other)))  # TODO: add proper exception

    def __math_operation_1(self, other, op):
        """
         General function for subtraction and addition operation.
        :param other:
        :param op:
        :return:
        """
        if isinstance(other, self.__class__):
            new = self.__class__(op(self.value, other(self.unit)), self.unit)
            return new
        else:
            TypeError()  # TODO: add proper exception

    def __truediv__(self, other):
        return self.__math_operator_2(other, operator.sub, operator.truediv)

    def __mul__(self, other):
        return self.__math_operator_2(other, operator.add, operator.mul)

    def __add__(self, other):
        return self.__math_operation_1(other, operator.add)

    def __sub__(self, other):
        return self.__math_operation_1(other, operator.sub)

    def __str__(self):
        return "{0} {1}".format(float(self.value), self.__unit_rep(self.dim_vector, self.unit_vector, supercase=True))

    def __pow__(self, power):

        if isinstance(power, int) and power >= 1:
            x = copy.deepcopy(self)
            for i in range(power - 1):
                x *= self
            return x
        else:
            raise Exception("incorrect exponent")  # TODO: add proper exception

    @property
    def value(self):
        return self._value

    @property
    def unit(self):
        return self.__unit_rep(self.dim_vector, self.unit_vector)

    @staticmethod
    def __unit_rep(dim_vector, unit_vector, supercase=False):
        l = list()
        for index, unit in enumerate(unit_vector):
            exponent = dim_vector[index]
            if exponent != 0:
                if supercase:
                    l.append(str(UnitNotation(unit, exponent)))
                else:
                    l.append("{}{}".format(unit, exponent if dim_vector[index] != 1 else ""))

        return " ".join(l)

    @classmethod
    def is_valid_unit(cls, unit):
        units = cls._converter.valid_units()
        return unit in units

    def __call__(self, unit):
        """

        :param unit:
        :return:
        """
        value = self._value
        if unit != self.unit:
            to_unit_vecto = self.__compose_unit(unit, self.dim_vector)
            matrix = self.__quantity_matrix_from_dimension_vector(self.dim_vector)
            for index, vector in enumerate(matrix):
                if Quantity.__not_empty_vector(vector):
                    cls = Quantity.__fallback_type_search(vector)
                    value = cls._converter(value, self.unit_vector[index], to_unit_vecto[index], self.dim_vector[index])

        return value

    def __comparison_operation(self, rghsv, op):
        """
        General functionality for comparison operators.
        :param rghsv:
        :param op:
        :return:
        """
        if type(self) == type(rghsv):
            return op(round(self(self._unit), 6), round(rghsv(self.unit), 6))
        else:
            raise TypeError("Unsupported type: {}".format(type(rghsv)))

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

    @staticmethod
    def __quantity_matrix_from_dimension_vector(v: tuple):
        matrix = [[0 for i in v] for i in v]
        for index, value in enumerate(v):
            matrix[index][index] = abs(value)

        return matrix

    @staticmethod
    def __compose_unit(inunit, dim_v, check_unit=True):

        unit_vector = ["", "", "", "", "", "", ""]

        quantity_matrix = Quantity.__quantity_matrix_from_dimension_vector(dim_v)
        units = UnitNotation.unit_parser(inunit)
        for index, quantity_v in enumerate(quantity_matrix):
            not_empty = Quantity.__not_empty_vector(quantity_v)
            if not_empty:
                quantity_class = Quantity.__fallback_type_search(quantity_v)
                for unit in units:
                    unit_to_check = unit.notation
                    if quantity_class.is_valid_unit(unit_to_check) or not check_unit:
                        unit_vector[index] = unit.notation
                        units.remove(unit)
                        break
            else:
                continue

        if len(units) != 0:
            raise ValueError('Unsupported unit!')
        else:
            return unit_vector

    @staticmethod
    def __fallback_type_search(quantity_v):
        quantity_class = Quantity.__type_search(tuple(quantity_v))
        if quantity_class is Quantity:
            quantity_class = Quantity.__type_search([1 if i != 0 else 0 for i in quantity_v])
        return quantity_class

    @staticmethod
    def __not_empty_vector(v):
        return bool(sum(map(lambda x: bool(x), v)))


class Length(Quantity):
    dim_vector = (1, 0, 0, 0, 0, 0, 0)
    _converter = LengthConvert("m")


class Mass(Quantity):
    dim_vector = (0, 1, 0, 0, 0, 0, 0)
    _converter = MassConvert("g")


class Time(Quantity):
    dim_vector = (0, 0, 1, 0, 0, 0, 0)
    _converter = TimeConvert("s")


class ElectricCurrency(Quantity):
    dim_vector = (0, 0, 0, 1, 0, 0, 0)
    _converter = Converter("A")


class Temperature(Quantity):
    # https://en.wikipedia.org/wiki/Conversion_of_units_of_temperature
    # TODO: implement Temperature Delta

    dim_vector = (0, 0, 0, 0, 1, 0, 0)
    _converter = TemperatureConvert("K")


class AmountOfSubstance(Quantity):
    dim_vector = (0, 0, 0, 0, 0, 1, 0)
    _converter = Converter("mol")


class LuminousIntensity(Quantity):
    dim_vector = (0, 0, 0, 0, 0, 0, 1)
    _converter = Converter("cd")


class Velocity(Quantity):
    dim_vector = (1, 0, -1, 0, 0, 0, 0)


class Area(Quantity):
    dim_vector = (2, 0, 0, 0, 0, 0, 0)
    _converter = AreaConvert("m2")


class Volume(Quantity):
    dim_vector = (3, 0, 0, 0, 0, 0, 0)
    _converter = VolumeConvert("m3")


class VolumetricFlow(Quantity):
    dim_vector = (3, 0, -1, 0, 0, 0, 0)


class Acceleration(Quantity):
    dim_vector = (1, 0, -2, 0, 0, 0, 0)


class Force(Quantity):
    dim_vector = (1, 1, -2, 0, 0, 0, 0)


class Concentration(Quantity):
    dim_vector = (-3, 1, 0, 0, 0, 0, 0)

class MolarConcentration(Quantity):
    dim_vector = (-3, 0, 0, 0, 0, 1, 0)

LIST_OF_CLASSES = list(
    filter(lambda cls: Quantity in cls[1].mro(), inspect.getmembers(sys.modules[__name__], inspect.isclass)))
