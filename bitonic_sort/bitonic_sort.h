#ifndef SORTING_NETWORK_BITONIC_SORT_H
#define SORTING_NETWORK_BITONIC_SORT_H


#include <iostream>
#include <vector>
using namespace std;


class Bitonic_Sort {
public:
    void bitonic_sort(vector<int>& array);

private:
    static constexpr bool ASCENDING = true;
    static constexpr bool DESCENDING = false;


    void sort_bitonic(vector<int>& array, int start_position, int finish_position, bool direction);

    void merge_bitonic(vector<int>& array, int start_position, int finish_position, bool direction);

    void compare_and_swap(vector<int>& array, int first_index, int second_index, bool direction);
};



#endif //SORTING_NETWORK_BITONIC_SORT_H
