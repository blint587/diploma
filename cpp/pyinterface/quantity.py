# encoding: utf-8
from munitscpp import PyQuantity
import sys
import inspect


class Quantity(PyQuantity):
    UNIT_INDEX = -1

    def __new__(cls, value=0., unit="", other=None):
        if other is None:
            return super().__new__(cls, cls.UNIT_INDEX, value, unit)
        else:
            ncls = list(filter(lambda c: c[1].UNIT_INDEX == other.matrix_index, LIST_OF_CLASSES))[0][1]
            return super().__new__(ncls, other=other)

    def __mul__(self, other):
        return Quantity(other=PyQuantity.__mul__(self, other))

    def __add__(self, other):
        return Quantity(other=PyQuantity.__add__(self, other))

    def __sub__(self, other):
        return Quantity(other=PyQuantity.__sub__(self, other))

    def __truediv__(self, other):
        return Quantity(other=PyQuantity.__truediv__(self, other))


class Length(Quantity):
    UNIT_INDEX = 0


class Area(Quantity):
    UNIT_INDEX = 7


LIST_OF_CLASSES = list(
    filter(lambda cls: issubclass(cls[1], Quantity) or cls is Quantity, inspect.getmembers(sys.modules[__name__], inspect.isclass)))

if __name__ == "__main__":

    from datetime import datetime as dt

    start = dt.now()
    for i in range(1000):
        q1 = Length(1., "m")
        q2 = Length(1., "m")
        q3 = q1 * q2

    stop = dt.now()

    print(stop - start)