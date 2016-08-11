# encoding: utf-8

from distutils.core import setup, Extension
from Cython.Build import cythonize

setup(
    ext_modules=cythonize(Extension(
        "munitscpp",
        sources=[
                 "pyinterface/munitscpp.pyx",
                 "quantity.cpp",
                 "converter_function.cpp",
                 "unit.cpp"
                 ],
        language="c++",
        extra_compile_args=["-std=c++11"],
        extra_link_args=["-std=c++11"],
    )))
