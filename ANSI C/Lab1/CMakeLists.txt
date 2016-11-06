cmake_minimum_required(VERSION 3.6)
project(Lab1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90 -Wall -Werror -pedantic")

set(SOURCE_FILES test14.c)
add_executable(Lab1 ${SOURCE_FILES})
target_link_libraries(Lab1 m)
