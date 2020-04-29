cmake_minimum_required(VERSION 3.14)
project(assignment)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment
        lab1driver.cpp
        partTimeEmployee.cpp
        partTimeEmployee.h
        personType.cpp
        personType.h)
