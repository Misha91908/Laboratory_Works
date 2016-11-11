cmake_minimum_required(VERSION 3.6)
project(Lab5)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90")

set(SOURCE_FILES even_number_counter.c)
add_executable(Lab5 ${SOURCE_FILES})
target_link_libraries(Lab5 m)