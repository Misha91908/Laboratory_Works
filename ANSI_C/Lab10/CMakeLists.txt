cmake_minimum_required(VERSION 3.6)
project(Lab10)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(SOURCE_FILES test1.c)
add_executable(Lab10 ${SOURCE_FILES})