import pytest

pytest_args = [
    "./pyunit_test/",
]

plugins = [
    "junitxml"
]

pytest.main(pytest_args, plugins)