cmake_minimum_required(VERSION 3.30)
project(sorting_network)

set(CMAKE_CXX_STANDARD 20)

add_executable(sorting_network main.cpp
        odd-even_transposition_sort/odd_even_transposition_sort.cpp
        odd-even_mergesort/odd_even_mergesort.cpp
        odd-even_mergesort/odd_even_mergesort.h
        odd-even_transposition_sort/odd_even_transposition_sort.h
        bitonic_sort/bitonic_sort.cpp
        bitonic_sort/bitonic_sort.h
        adapted_bitonic_sort/adapted_bitonic_sort.cpp
        adapted_bitonic_sort/adapted_bitonic_sort.h
        LS3_sort/ls3_sort.cpp
        LS3_sort/ls3_sort.h
        4-way_mergesort/four_way_mergesort.cpp
        4-way_mergesort/four_way_mergesort.h
        rotatesort/rotatesort.cpp
        rotatesort/rotatesort.h
        3n_sort_Schnorr_and_Shamir/three_n_sort_Schnorr_and_Shamir.cpp
        3n_sort_Schnorr_and_Shamir/three_n_sort_Schnorr_and_Shamir.h
        2D_odd-even_transposition_sort/two_d_odd_even_transposition_sort.cpp
        2D_odd-even_transposition_sort/two_d_odd_even_transposition_sort.h
        2D_odd-even_transposition_sort/two_d_odd_even_transposition_sort.h
        shearsort/shearsort.cpp
        shearsort/shearsort.h
        shearsort/shearsort.cpp)

find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    target_link_libraries(sorting_network PUBLIC OpenMP::OpenMP_CXX)
endif()
