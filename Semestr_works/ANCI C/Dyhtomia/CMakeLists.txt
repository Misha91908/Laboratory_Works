cmake_minimum_required(VERSION 3.6)
project(Dyhtomia)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90 -Wall -Werror -pedantic")

set(SOURCE_FILES dyht.c)
add_executable(Dyhtomia ${SOURCE_FILES})
target_link_libraries(Dyhtomia m)