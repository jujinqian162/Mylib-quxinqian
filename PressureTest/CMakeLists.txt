cmake_minimum_required(VERSION 3.29.0)

project(pressure_test)

set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(pressure STATIC ${SRC})