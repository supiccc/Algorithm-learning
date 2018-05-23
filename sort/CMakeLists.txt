cmake_minimum_required(VERSION 3.10)
project(sort)

set(CMAKE_CXX_STANDARD 11)


add_executable(mergesortClient client/mergesortClient.cpp func/Merge.cpp func/Merge.h)

