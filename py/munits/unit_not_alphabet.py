# encoding: utf-8
import re

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

def unit_parser2(u: str):
    units_non_exp = []
    units_pos_exp = []

    units_neg_exp = []
    eunits=[]
    for unit in u.split(' '):
        if not unit[0].isdigit() and re.match('^[a-zA-z°Åμ]+(\-?[0-9]?)$', unit):
            if not unit[-1:].isdigit():
                units_non_exp.append(unit)
            elif (unit[-1:]).isdigit() and (int(unit[-1:])) > 1 and unit[-2:-1] != "-":
                exp_orig=int(unit[-1:])
                exp_new=superscripts.get(str(exp_orig))
                unit=unit.replace(unit[-1:],exp_new)
                units_pos_exp.append(unit)

            else:
                exp_orig = int(unit[-1:])
                exp_new = superscripts.get(str(exp_orig))
                unit = unit.replace(unit[-2:-1],"\u207B")
                unit = unit.replace(unit[-1:], exp_new)
                units_neg_exp.append(unit)
        else:
            raise Exception ("invalid unit!")



    all_unit=sorted(units_non_exp)+sorted(units_pos_exp)+sorted(units_neg_exp)
    print(all_unit)
    print (" ".join(all_unit))

    # for unit in all_unit:
    #
    #     exponent=(re.sub('[a-zA-z°Åμ]+', "", unit)) or '1'
    #     u = unit.replace(exponent, "")
    #
    #     eunits.append(u)
    #     eunits.append(exponent)
    # print (eunits)

#
# if __name__ == "__main__":
#     unit_parser2("kg m s-2 ms")