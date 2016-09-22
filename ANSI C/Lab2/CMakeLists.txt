cmake_minimum_required(VERSION 3.6)
project(Lab2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90 -Wall -Werror -pedantic")

set(SOURCE_FILES test4.c)
add_executable(Lab2 ${SOURCE_FILES})
target_link_libraries(Lab2 m)