#ifndef SORTING_NETWORK_ADAPTED_BITONIC_SORT_H
#define SORTING_NETWORK_ADAPTED_BITONIC_SORT_H


#include <iostream>
#include <vector>
using namespace std;


class Adapted_Bitonic_Sort {
public:
    void adapted_bitonic_sort(vector<int>& array);

private:
    static constexpr bool ASCENDING = true;


    void sort_adapted_bitonic(vector<int>& array, int start_position, int finish_position, bool direction);

    void merge_adapted_bitonic(vector<int>& array, int start_position, int finish_position, bool direction);

    void compare_and_swap(vector<int>& array, int first_index, int second_index, bool direction);

    int greatest_power_of_2_less_than(int n);
};


#endif //SORTING_NETWORK_ADAPTED_BITONIC_SORT_H
