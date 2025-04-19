#ifndef SORTING_NETWORK_ADAPTED_BITONIC_SORT_H
#define SORTING_NETWORK_ADAPTED_BITONIC_SORT_H


#include <vector>
#include <omp.h>

using namespace std;


class Adapted_Bitonic_Sort {
public:
    static void adapted_bitonic_sort(vector<int>& array);

private:
    static constexpr bool ASCENDING = true;


    static void sort_adapted_bitonic(vector<int>& array, int start_position, int finish_position, bool direction);
    static void merge_adapted_bitonic(vector<int>& array, int start_position, int finish_position, bool direction);
    static void compare_and_swap(vector<int>& array, int first_index, int second_index, bool direction);
    static int greatest_power_of_2_less_than(int n);
};


#endif //SORTING_NETWORK_ADAPTED_BITONIC_SORT_H
