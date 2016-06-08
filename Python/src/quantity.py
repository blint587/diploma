import inspect
import sys
import operator


class Quantity():
    # 1. length
    # 2. mass
    # 3. time
    # 4. electric_current
    # 5. temperature
    # 6. amount_of_substance
    # 7. luminous_intensity
    dim_vector = (0, 0, 0, 0, 0, 0, 0)
    unit_vector = ["", "", "", "", "", "", ""]

    def __init__(self, value, unit):
        self.__value = value
        self.__unit = unit

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
        return self.__value

    @value.setter
    def value(self, x):
        self.__value = x

    @property
    def unit(self):
        return " ".join(
            filter(lambda x: x, ["{}{}".format(unit, self.dim_vector[index] if self.dim_vector[index] != 1 else "")
                                 if unit else "" for index, unit in enumerate(self.unit_vector)]))


class Length(Quantity):
    dim_vector = (1, 0, 0, 0, 0, 0, 0)
    unit_vector = ["m", "", "", "", "", "", ""]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class Mass(Quantity):
    dim_vector = (0, 1, 0, 0, 0, 0, 0)
    unit_vector = ["", "kg", "", "", "", "", ""]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class Time(Quantity):
    dim_vector = (0, 0, 1, 0, 0, 0, 0)
    unit_vector = ["", "", "s", "", "", "", ""]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class ElectricCurrency(Quantity):
    dim_vector = (0, 0, 0, 1, 0, 0, 0)
    unit_vector = ["", "", "", "A", "", "", ""]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class Temperature(Quantity):
    dim_vector = (0, 0, 0, 0, 1, 0, 0)
    unit_vector = ["", "", "", "", "K", "", ""]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class AmountOfSubstance(Quantity):
    dim_vector = (0, 0, 0, 0, 0, 1, 0)
    unit_vector = ["", "", "", "", "", "mol", ""]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class LuminousIntensity(Quantity):
    dim_vector = (0, 0, 0, 0, 0, 0, 1)
    unit_vector = ["", "", "", "", "", "", "cd"]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class Velocity(Quantity):
    dim_vector = (1, 0, -1, 0, 0, 0, 0)
    unit_vector = ["", "", "", "", "", "", ""]

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
