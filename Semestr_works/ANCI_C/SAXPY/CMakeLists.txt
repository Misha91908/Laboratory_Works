cmake_minimum_required(VERSION 3.6)
project(SAXPY)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90")

set(SOURCE_FILES test3.c)
add_executable(SAXPY ${SOURCE_FILES})
target_link_libraries(SAXPY -fopenmp)