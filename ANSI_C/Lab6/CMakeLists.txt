cmake_minimum_required(VERSION 3.6)
project(Lab6)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90")

set(SOURCE_FILES test.c)
add_executable(Lab6 ${SOURCE_FILES})
target_link_libraries(Lab6 m)