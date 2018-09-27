cmake_minimum_required(VERSION 3.5)
project(sandbox)

find_package(Doxygen)

if(DOXYGEN_FOUND)

    set(DOXYGEN_INPUT ${SOURCE_FILES})
    set(DOXYGEN_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    add_custom_command(
            OUTPUT ${DOXYGEN_OUTPUT}
            COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
            COMMAND ${CMAKE_COMMAND} -E echo "Done."
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            DEPENDS ${DOXYGEN_INPUT}
    )

    add_custom_target(apidoc ALL DEPENDS ${DOXYGEN_OUTPUT})

    add_custom_target(apidoc_forced
            COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
            COMMAND ${CMAKE_COMMAND} -E echo "Done."
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            )

endif(DOXYGEN_FOUND)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin/")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D DEBUG -D NOCYTHON")

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
        src/uresolver.cpp
        src/uresolver.hpp
        lib/Accesories/math.hpp src/prefix.cpp src/prefix.hpp src/parsers.hpp src/parsers.cpp src/searchers.cpp src/searchers.hpp)
add_executable(musys ${SOURCE_FILES})

add_subdirectory(test)
add_subdirectory(lib/Accesories)