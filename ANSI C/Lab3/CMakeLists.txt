cmake_minimum_required(VERSION 3.6)
project(Lab3)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90 -Wall -Werror -pedantic")

set(SOURCE_FILES test5.c)
add_executable(Lab3 ${SOURCE_FILES})
target_link_libraries(Lab3 m)