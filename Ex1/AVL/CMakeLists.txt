cmake_minimum_required(VERSION 3.13)
project(AVL)

set(CMAKE_CXX_STANDARD 11)

add_executable(AVL main_test_avl.cpp avl.h avl.cpp node.h node.cpp)