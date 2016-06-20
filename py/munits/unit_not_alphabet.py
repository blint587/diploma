# encoding: utf-8
import re


def unit_parser(u: str):
    units_non_exp = []
    units_pos_exp = []
    units_neg_exp = []
    for unit in u.split(' '):
        if not unit[0].isdigit():
            if not unit[-1:].isdigit() and not unit[0].isdigit():
                units_non_exp.append(unit)
            elif (unit[-1:]).isdigit() and (int(unit[-1:])) > 1 and unit[-2:-1] != "-":
                units_pos_exp.append(unit)
            else:
                if not unit[0].isdigit():
                    units_neg_exp.append(unit)
        else:
            raise Exception ("invalid unit!")
    print("no index", sorted(units_non_exp), "pos index", sorted(units_pos_exp), "neg index", sorted(units_neg_exp))


unit_parser("kg 2m s2")
