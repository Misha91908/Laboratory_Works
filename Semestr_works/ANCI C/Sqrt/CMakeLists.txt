cmake_minimum_required(VERSION 3.6)
project(Sqrt)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90 -Wall -Werror -pedantic")

set(SOURCE_FILES sqrt.c)
add_executable(Sqrt ${SOURCE_FILES})