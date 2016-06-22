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

    def __gt__(self, other):
        if isinstance(other, UnitNotation):
            if self.exponent == other.exponent and self.notation[0] < other.notation[0]:
                return True
            if self.exponent == other.exponent and self.notation[0] > other.notation[0]:
                return False
            if self.exponent > 0 and other.exponent > 0 and self.exponent >= other.exponent:
                return True
            if self.exponent > 0 and other.exponent > 0 and self.exponent < other.exponent:
                return False
            if self.exponent < 0 and other.exponent < 0 and self.exponent >= other.exponent:
                return True
            if self.exponent < 0 and other.exponent < 0 and self.exponent < other.exponent:
                return False

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
        units = list()
        for unit in u.split(' '):
            if re.match('^[a-zA-z°Åμ]+(\-?[0-9]?)$', unit):
                exponent = (re.sub('[a-zA-z°Åμ]+', "", unit)) or '1'
                u = unit.replace(exponent, "")
                units.append(UnitNotation(u, exponent))
            else:
                raise Exception
        return units

# if __name__ == '__main__':
