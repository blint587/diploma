cmake_minimum_required(VERSION 3.5)
project(munits)

#find_package(Doxygen)
#
#if(DOXYGEN_FOUND)
#
#    set(DOXYGEN_INPUT ${SOURCE_FILES})
#    set(DOXYGEN_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
#
#    add_custom_command(
#            OUTPUT ${DOXYGEN_OUTPUT}
#            COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
#            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
#            COMMAND ${CMAKE_COMMAND} -E echo "Done."
#            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#            DEPENDS ${DOXYGEN_INPUT}
#    )
#
#    add_custom_target(apidoc ALL DEPENDS ${DOXYGEN_OUTPUT})
#
#    add_custom_target(apidoc_forced
#            COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
#            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
#            COMMAND ${CMAKE_COMMAND} -E echo "Done."
#            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#            )
#
#endif(DOXYGEN_FOUND)

add_definitions(-D_GLIBCXX_USE_CXX14_ABI=0)
add_definitions(-DUNICODE -D_UNICODE)


set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin/")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -D WIN32 -O3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D DEBUG -D NOCYTHON")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
#set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")

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
#        lib/Accesories/math.hpp
        src/prefix.cpp
        src/prefix.hpp
        src/parsers.hpp
        src/parsers.cpp
        src/searchers.cpp
        src/searchers.hpp
        src/unit_validator.cpp
        src/unit_validator.hpp)
if(MSVC)
    set(SOURCE_FILES ${SOURCE_FILES} src/cs/munitscsexport.cpp)
    set(BUILD_SHARED_LIBS TRUE)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
elseif(NOT MSVC)
    # gtest is not working with MSVC
    set(SOURCE_FILES ${SOURCE_FILES} src/cs/munitscsexport.cpp )
    add_subdirectory(test)
endif()


add_library(munits SHARED ${SOURCE_FILES} src/unit_validator.cpp src/unit_validator.hpp)

add_executable(musys ${SOURCE_FILES} main.cpp)

add_subdirectory(lib/Accesories)

#if(WIN32)
#    add_custom_command(TARGET munits
#            POST_BUILD
#            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:munits> /munitscs/munitscs/munitscs)
#endif()
