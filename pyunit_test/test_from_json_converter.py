# encoding: utf-8
import json
from unittest import TestCase
from munits import Length
from base2.parsers import ToJsonParser, FromJsonParser
from base2.base import BaseClass


class Foo(BaseClass):

    def __init__(self):
        super().__init__()
        self.something = Length(1, "m")


class TestFromJSONParser(TestCase):

    def test_from_json_parser_injection(self):
        f = Foo()

        js = json.dumps(f, default=ToJsonParser(with_class=True))
        r = json.loads(js, object_hook=FromJsonParser())

        self.assertIsInstance(r, Foo)
        self.assertIsInstance(r.something, Length)

