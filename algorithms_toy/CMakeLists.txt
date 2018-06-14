cmake_minimum_required(VERSION 3.10)
project(toy)

set(CMAKE_CXX_STANDARD 11)


add_executable(main client/main.cpp sort/Merge.h sort/Quick.h sort/Insertion.h dataStructure/SequentialSearchST.h message/MessageProtocol.h)

