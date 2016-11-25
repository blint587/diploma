# encoding: utf-8

from distutils.core import setup, Extension
from Cython.Build import cythonize

setup(
    ext_modules=cythonize(Extension(
        "munitscpp",
        sources=[
                 "pyinterface/munitscpp.pyx",
                 "src/quantity.cpp",
                 "src/converter.cpp",
                 "src/converter_function.cpp",
                 "src/dynamic.cpp",
                 "src/metric.cpp",
                 "src/unit.cpp",
                 "src/unit_notation.cpp",
                 "src/resolver.cpp"
                 ],
        language="c++",
        extra_compile_args=["-std=c++14"],
        extra_link_args=["-std=c++14"],
    )))
