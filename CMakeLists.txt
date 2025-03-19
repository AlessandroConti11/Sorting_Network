cmake_minimum_required(VERSION 3.30)
project(sorting_network)

set(CMAKE_CXX_STANDARD 20)

add_executable(sorting_network odd-even_transposition_sort/odd_even_transposition_sort.cpp
        odd-even_mergesort/odd_even_mergesort.cpp
        odd-even_mergesort/odd_even_mergesort.h
        odd-even_transposition_sort/odd_even_transposition_sort.h
        main.cpp)
