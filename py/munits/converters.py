# encoding: utf-8
from decimal import Decimal
from munits.unitnotation import UnitNotation


class Converter:
    class ConverterFunction():
        def __init__(self, v):
            self._v = v

        def to_base(self, conv, exponent=1):
            return conv * (self._v ** exponent)

        def from_base(self, conv, exponent=1):
            return conv / (self._v ** exponent)

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

    remove_prefix = []

    def __init__(self, base_unit, additional_units: dict = None):
        self.units = {}
        if base_unit:
            self.base_unit = UnitNotation.unit_parser(base_unit)[0].notation

            for key, value in self.prefixes.items():
                if key not in self.remove_prefix:
                    self.units[key + self.base_unit] = value

            self.units[self.base_unit] = Converter.ConverterFunction(Decimal("1.0"))
            if additional_units:
                for key, value in additional_units.items():
                    self.units[key] = value

    def __call__(self, val, funit: str, tunit: str, exp: int):

        to_base_func = self.units.get(funit)
        in_base = to_base_func.to_base(val, exponent=exp)

        from_base_func = self.units.get(tunit)
        res = from_base_func.from_base(in_base, exponent=exp)

        return res

    def valid_units(self):
        return self.units.keys()


class LengthConvert(Converter):
    def __init__(self, base_unit, additional_units: dict = None):
        if not additional_units:
            additional_units = {}
        Converter.__init__(self, base_unit, {**{
            "in": Converter.ConverterFunction(Decimal('0.0254')),
            "ft": Converter.ConverterFunction(Decimal('0.3048')),
            "yd": Converter.ConverterFunction(Decimal('0.914')),
            "mi": Converter.ConverterFunction(Decimal('1609.344'))
        },
                                             **additional_units})


class MassConvert(Converter):
    def __init__(self, base_unit, additional_units: dict = None):
        if not additional_units:
            additional_units = {}

        Converter.__init__(self, base_unit, {**{
            "oz": Converter.ConverterFunction(Decimal('28.3495')),
            "lb": Converter.ConverterFunction(Decimal('453.592')),
            "t": Converter.ConverterFunction(Decimal('1e6')),
            "tonne_uk": Converter.ConverterFunction(Decimal('1016046 ')),
            "tonne_us": Converter.ConverterFunction(Decimal('907184. ')),
        },
                                             **additional_units})


class TimeConvert(Converter):
    remove_prefix = ["E", "P", "T", "G", "M", "k", "h", "da", "d", "c"]

    def __init__(self, base_unit, additional_units: dict = None):
        if not additional_units:
            additional_units = {}
        Converter.__init__(self, base_unit, {**{
            "min": Converter.ConverterFunction(Decimal('60')),
            "h": Converter.ConverterFunction(Decimal('3600')),
            "d": Converter.ConverterFunction(Decimal('86400'))
        }, **additional_units})


class TemperatureConvert(Converter):
    class TempConverterFunction(Converter.ConverterFunction):
        def __init__(self, a, b):
            Converter.ConverterFunction.__init__(self, a)
            self.__b = b

        def to_base(self, conv, exponent=1):
            return (conv + self.__b) * self._v

        def from_base(self, conv, exponent=1):
            return conv * (self._v ** -1) - self.__b

    remove_prefix = Converter.prefixes.keys()

    def __init__(self, base_unit, additional_units: dict = None):
        if not additional_units:
            additional_units = {}
        Converter.__init__(self, base_unit, {**{
            "K": TemperatureConvert.TempConverterFunction(Decimal('1.0'), Decimal('0.0')),
            "°C": TemperatureConvert.TempConverterFunction(Decimal('1.0'), Decimal('273.15')),
            "°F": TemperatureConvert.TempConverterFunction(Decimal('5.') / Decimal('9.'), Decimal('459.67'))
        }, **additional_units})


class AreaConvert(LengthConvert):
    additional_units = {"ac": Converter.ConverterFunction(Decimal('4046.85')),
                        "are": Converter.ConverterFunction(Decimal('100'))

                        }


class VolumeConvert(LengthConvert):
    def __init__(self, base_unit):
        LengthConvert.__init__(self, base_unit, {
            "gal": Converter.ConverterFunction(Decimal('0.1558491279125191126493914617')),
            "oz": Converter.ConverterFunction(Decimal('2.957e-5')),
            "l": Converter.ConverterFunction(Decimal('1e-1'))
        }
                               )

