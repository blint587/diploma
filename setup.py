# encoding: utf-8

from setuptools import setup
from setuptools.extension import Extension
import sys

try:
    from Cython.Build import cythonize
    USE_CYTHON = "build_ext" in sys.argv
except ImportError as ie:
    USE_CYTHON = False


sources = ["munitscpp.pyx",
           "src/quantity.cpp",
           "src/converter.cpp",
           "src/converter_function.cpp",
           "src/dynamic.cpp",
           "src/metric.cpp",
           "src/unit.cpp",
           "src/unit_notation.cpp",
           "src/uresolver.cpp",
           "src/searchers.cpp",
           "src/prefix.cpp",
           "src/parsers.cpp"
           ]

if not USE_CYTHON:
    sources += ["munitscpp.cpp"]


extensions = [Extension(
    "munitscpp",
    sources=sources,
    language="c++",
    extra_compile_args=["-std=c++11"],
    # extra_compile_args=["-std=c++11", "-Zi", "/Od" "-D CYTHON"],    # Debug flag version
    extra_link_args=["-std=c++11"],
    # extra_link_args=["-std=c++11", "-debug" "-D CYTHON"],   # Debug flag version
)]

if USE_CYTHON:
    from Cython.Build import cythonize
    extensions = cythonize(extensions)


setup(
    name="munits",
    version="0.2.1",
    packages=["munits"],
    ext_modules=extensions,
    install_requires=["base2>=0.1.16"],
    # data_files={"munits": ["src/*.hpp", "src/*.h", "lib/Accesories/*.hpp", "src/uresolver.hpp"]},
    dependency_links=[]
)
