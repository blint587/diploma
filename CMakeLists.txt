cmake_minimum_required(VERSION 3.5)
project(sandbox)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin/")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D DEBUG")

set(SOURCE_FILES main.cpp
        src/quantity.cpp
        src/quantity.h
        lib/Accesories/accessories.hpp
        src/converter_function.cpp
        src/converter_function.hpp
        src/unit.cpp
        src/unit.hpp
        src/unit_notation.cpp
        src/unit_notation.hpp
        src/metric.cpp
        src/metric.hpp
        src/converter.cpp
        src/converter.hpp
        src/dynamic.hpp
        src/dynamic.cpp
        src/resolver.cpp
        src/resolver.hpp
        )
add_executable(musys ${SOURCE_FILES})

add_subdirectory(test)
add_subdirectory(lib/Accesories)