#ifndef SORTING_NETWORK_BITONIC_SORT_H
#define SORTING_NETWORK_BITONIC_SORT_H


#include <vector>
#include <omp.h>

using namespace std;


class Bitonic_Sort {
public:
    static void bitonic_sort(vector<int>& array);

private:
    static constexpr bool ASCENDING = true;
    static constexpr bool DESCENDING = false;


    static void sort_bitonic(vector<int>& array, int start_position, int finish_position, bool direction);
    static void merge_bitonic(vector<int>& array, int start_position, int finish_position, bool direction);
    static void compare_and_swap(vector<int>& array, int first_index, int second_index, bool direction);
};


#endif //SORTING_NETWORK_BITONIC_SORT_H
