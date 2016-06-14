# encoding: utf-8
import copy
from decimal import Decimal

import re


class Converter:
    class ConverterFunction():
        def __init__(self, v):
            self._v = v

        def to_base(self, conv):
            return conv * self._v

        def from_base(self, conv):
            return conv / self._v

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

    additional_units = {}

    def __init__(self, base_unit):
        self.__base_unit = base_unit

    def __call__(self, val, funit: str, tunit: str):
        default = Converter.ConverterFunction(Decimal("1.0"))
        to_base_func = self.prefixes.get(self._prefix_parser(funit)) or self.additional_units.get(funit) or default
        in_base = to_base_func.to_base(val)

        from_base_func = self.prefixes.get(self._prefix_parser(tunit)) or self.additional_units.get(tunit) or default
        res = from_base_func.from_base(in_base)

        return res

    def _prefix_parser(self, unit: str):
        prefix = re.sub(r'{}$'.format(self.__base_unit), "", unit, count=1)
        return prefix


class TemperatureConvert(Converter):
    class TempConverterFunction(Converter.ConverterFunction):
        # noinspection PyMissingConstructor
        def __init__(self, a, b):
            Converter.ConverterFunction.__init__(self, a)
            self.__b = b

        def to_base(self, conv):
            return (conv + self.__b) * self._v

        def from_base(self, conv):
            return conv * (self._v ** -1) - self.__b

    additional_units = {
        "K": TempConverterFunction(Decimal('1.0'), Decimal('0.0')),
        "°C": TempConverterFunction(Decimal('1.0'), Decimal('273.15')),
        "°F": TempConverterFunction(Decimal('5.') / Decimal('9.'), Decimal('459.67'))
    }


class TimeConvert(Converter):
    prefixes = copy.deepcopy(Converter.prefixes)

    remove_prefix = ["E", "P", "T", "G", "M", "k", "h", "da", "d", "c"]

    for p in remove_prefix:
        prefixes.__delitem__(p)

    additional_units = {
        "min": Converter.ConverterFunction(Decimal('60')),
        "h": Converter.ConverterFunction(Decimal('3600')),
        "d": Converter.ConverterFunction(Decimal('86400'))
    }

    def __init__(self, base_unit):
        Converter.__init__(self, base_unit)
