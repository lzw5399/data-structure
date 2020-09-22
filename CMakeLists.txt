cmake_minimum_required(VERSION 3.17)
project(data_structure)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(static-allocation 1-linear-list/1.1-static-allocation/static-allocation.cpp)
add_executable(single-linked-list 1-linear-list/1.3-singly-linked-list/singly-linked-list.cpp)
add_executable(reverse-singly-linked-list 1-linear-list/1.3-singly-linked-list/homework/reverse-singly-linked-list.cpp)
add_executable(double-linked-list 1-linear-list/1.4-double-linked-list/double-linked-list.cpp)
