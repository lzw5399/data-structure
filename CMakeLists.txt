cmake_minimum_required(VERSION 3.17)
project(data_structure)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(static-allocation 1-linear_list/1.1-static_allocation/static-allocation.cpp)
add_executable(single-linked-list 1-linear_list/1.3-linked-list/singly-linked-list.cpp)
