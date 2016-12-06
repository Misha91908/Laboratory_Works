cmake_minimum_required(VERSION 3.6)
project(Matrix_multiple)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90")

set(SOURCE_FILES main.cpp)
add_executable(Matrix_multiple ${SOURCE_FILES})