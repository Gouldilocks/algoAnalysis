cmake_minimum_required(VERSION 3.17)
project(21s_pa02_Gouldilocks)

set(CMAKE_CXX_STANDARD 14)

# release build flags
#set(CMAKE_CXX_FLAGS_DEBUG -O3)

# debug build flags
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_FLAGS -Wextra)

#include all used directories
include_directories(sorts)
include_directories(src)
include_directories(testing)

#configure each of the files
configure_file(datasets/RandomData.txt datasets/RandomData.txt)
configure_file(datasets/ReversedData.txt datasets/ReversedData.txt)
configure_file(datasets/ThirtyPercent.txt datasets/ThirtyPercent.txt)
configure_file(datasets/TwentyPercent.txt datasets/TwentyPercent.txt)

#add each of the executable files as well as the project name
add_executable(21s_pa02_Gouldilocks
        sorts/AlgorithmStrategy.cpp
        sorts/insertionSort.cpp
        sorts/insertionSort.h
        sorts/mergeSort.cpp
        sorts/mergeSort.h
        sorts/quickSort.cpp
        sorts/quickSort.h
        sorts/selectionSort.cpp
        sorts/selectionSort.h
        sorts/AlgorithmStrategy.h
        testing/catch.hpp
        src/main.cpp
        src/AlgoRunner.cpp
        src/AlgoRunner.h
        src/main.cpp sorts/heapSort.cpp sorts/heapSort.h sorts/cycleSort.cpp sorts/cycleSort.h)
