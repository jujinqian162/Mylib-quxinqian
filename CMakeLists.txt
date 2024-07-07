cmake_minimum_required(VERSION 3.29.0)

project(Library)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COMPILER_IS_GNUCXX ON)
set(CMAKE_COMPILER_IS_GNUCC ON)

message(STATUS "CMAKE_COMPILER_IS_GNUCXX: " ${CMAKE_COMPILER_IS_GNUCXX})

set(CORO_INCLUDE ${PROJECT_SOURCE_DIR}/Coroutine/include)

set(FILE_INCLUDE ${PROJECT_SOURCE_DIR}/Filesystem/include)

set(FMT_INCLUDE ${PROJECT_SOURCE_DIR}/Format/include)

set(FILE_LIB ${PROJECT_SOURCE_DIR}/Filesystem/output)

set(FMT_LIB ${PROJECT_SOURCE_DIR}/Format/output)

set(CORO_LIB ${PROJECT_SOURCE_DIR}/Filesystem/output)

set(CONFIG ${PROJECT_SOURCE_DIR}/config.h)


add_subdirectory(Coroutine)

add_subdirectory(Filesystem)

add_subdirectory(PressureTest)

add_subdirectory(Format)