# encoding: utf-8

from base2.parsers import _FromParsersFunction, FromJsonParser


class __MunitsParser(_FromParsersFunction):

    def __call__(self, cls: type, d: dict):
        return cls(value=d["value"], unit=d["unit"])

from munits.quantities import *

FromJsonParser._inject_parser(quantities.Quantity, __MunitsParser())






