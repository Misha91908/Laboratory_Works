cmake_minimum_required(VERSION 3.6)
project(Lab4)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90 -Wall -Werror -pedantic")

set(SOURCE_FILES test.c)
add_executable(Lab4 ${SOURCE_FILES})
target_link_libraries(Lab4 m)