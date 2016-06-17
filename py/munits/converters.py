# encoding: utf-8
# from decimal import float
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
        "E": ConverterFunction(float("1e18")),  # exa
        "P": ConverterFunction(float("1e15")),  # peta
        "T": ConverterFunction(float("1e12")),  # tera
        "G": ConverterFunction(float("1e9")),  # giga
        "M": ConverterFunction(float("1e6")),  # mega
        "k": ConverterFunction(float("1e3")),  # kilo
        "h": ConverterFunction(float("1e2")),  # hecto
        "da": ConverterFunction(float("1e1")),  # deca
        "d": ConverterFunction(float("0.1")),  # deci
        "c": ConverterFunction(float("0.01")),  # centi
        "m": ConverterFunction(float("0.001")),  # milli
        "μ": ConverterFunction(float("0.000001")),  # micro
        "n": ConverterFunction(float("0.000000001")),  # nano
        "p": ConverterFunction(float("0.000000000001")),  # pico
        "f": ConverterFunction(float("0.000000000000001")),  # femto
        "a": ConverterFunction(float("0.000000000000000001"))  # atto
    }

    remove_prefix = []

    def __init__(self, base_unit, additional_units: dict = None):
        self.units = {}
        if base_unit:
            self.base_unit = UnitNotation.unit_parser(base_unit)[0].notation

            for key, value in self.prefixes.items():
                if key not in self.remove_prefix:
                    self.units[key + self.base_unit] = value

            self.units[self.base_unit] = Converter.ConverterFunction(float("1.0"))
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
            "in": Converter.ConverterFunction(float('0.0254')),
            "ft": Converter.ConverterFunction(float('0.3048')),
            "yd": Converter.ConverterFunction(float('0.914')),
            "mi": Converter.ConverterFunction(float('1609.344'))
        },
                                             **additional_units})


class MassConvert(Converter):
    def __init__(self, base_unit, additional_units: dict = None):
        if not additional_units:
            additional_units = {}

        Converter.__init__(self, base_unit, {**{
            "oz": Converter.ConverterFunction(float('28.3495')),
            "lb": Converter.ConverterFunction(float('453.592')),
            "t": Converter.ConverterFunction(float('1e6')),
            "tonne_uk": Converter.ConverterFunction(float('1016046 ')),
            "tonne_us": Converter.ConverterFunction(float('907184. ')),
        },
                                             **additional_units})


class TimeConvert(Converter):
    remove_prefix = ["E", "P", "T", "G", "M", "k", "h", "da", "d", "c"]

    def __init__(self, base_unit, additional_units: dict = None):
        if not additional_units:
            additional_units = {}
        Converter.__init__(self, base_unit, {**{
            "min": Converter.ConverterFunction(float('60')),
            "h": Converter.ConverterFunction(float('3600')),
            "d": Converter.ConverterFunction(float('86400'))
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
            "K": TemperatureConvert.TempConverterFunction(float('1.0'), float('0.0')),
            "°C": TemperatureConvert.TempConverterFunction(float('1.0'), float('273.15')),
            "°F": TemperatureConvert.TempConverterFunction(float('5.') / float('9.'), float('459.67'))
        }, **additional_units})


class AreaConvert(LengthConvert):
    def __init__(self, base_unit):
        LengthConvert.__init__(self, base_unit, {
            "ac": Converter.ConverterFunction(float('63.6148567553')),
            "are": Converter.ConverterFunction(float('10'))
            }
                               )



class VolumeConvert(LengthConvert):
    def __init__(self, base_unit):
        LengthConvert.__init__(self, base_unit, {
            "gal": Converter.ConverterFunction(float('0.1558491279125191126493914617')),
            "oz": Converter.ConverterFunction(float('2.957e-5')),
            "l": Converter.ConverterFunction(float('1e-1'))
        }
                               )

