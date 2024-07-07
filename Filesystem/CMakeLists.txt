cmake_minimum_required(VERSION 3.29.0)

project(FileSystem)

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/output)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CORO_INCLUDE}
)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)
link_directories(${CORO_LIB})


add_library(filesystem STATIC ${SRC})
target_link_libraries(filesystem coroutine)
# set_target_properties(filesystem PROPERTIES LINKER_LANGUAGE CXX)


# message(STATUS "PROJECT_NAME: " ${PROJECT_NAME}) #项目名称
# message(STATUS "PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR}) 
# message(STATUS "PROJECT_BINARY_DIR: " ${PROJECT_BINARY_DIR})
# message(STATUS "CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR})
# message(STATUS "CMAKE_CURRENT_BINARY_DIR：" ${CMAKE_CURRENT_BINARY_DIR})
# message(STATUS "CMAKE_CURRENT_LIST_DIR: " ${CMAKE_CURRENT_LIST_DIR})
# message(STATUS "CMAKE_CURRENT_LIST_LINE: " ${CMAKE_CURRENT_LIST_LINE})
# message(STATUS "SRC: " ${SRC})

