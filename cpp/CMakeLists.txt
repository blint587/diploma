cmake_minimum_required(VERSION 3.5)
project(musys)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D DEBUG")

set(SOURCE_FILES main.cpp Quantity.cpp Quantity.h )
add_executable(musys ${SOURCE_FILES})

add_subdirectory(test)