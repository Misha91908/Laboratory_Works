cmake_minimum_required(VERSION 3.5.1)
project(Lab8)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90")

set(SOURCE_FILES test.c)
add_executable(Lab8 ${SOURCE_FILES})
target_link_libraries(Lab8 m)