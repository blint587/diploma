# encoding: utf-8
import re

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
        self.__exponent = str(exponent)

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

    @staticmethod
    def unit_parser(u: str):
        units_non_exp = []
        units_pos_exp = []
        units_neg_exp = []
        eunits = []
        for unit in u.split(' '):
            if not unit[0].isdigit():
                if not unit[-1:].isdigit():
                    units_non_exp.append(unit)
                elif (unit[-1:]).isdigit() and (int(unit[-1:])) > 1 and unit[-2:-1] != "-":
                    units_pos_exp.append(unit)

                else:
                    units_neg_exp.append(unit)
            else:
                raise Exception("invalid unit!")
        units = sorted(units_non_exp) + sorted(units_pos_exp) + sorted(units_neg_exp)

        for unit in units:
            exponent = (re.sub('[a-zA-z°Åμ]+', "", unit)) or '1'
            u = unit.replace(exponent, "")
            eunits.append(UnitNotation(u, exponent))

        return eunits

if __name__ == '__main__':
    print(UnitNotation.unit_parser('kg m s-2'))