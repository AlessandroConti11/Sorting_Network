#ifndef SORTING_NETWORK_ODD_EVEN_MERGESORT_H
#define SORTING_NETWORK_ODD_EVEN_MERGESORT_H


#include <iostream>
#include <vector>
using namespace std;


class Odd_Even_Mergesort {
public:
    void odd_even_mergesort(vector<int>& array);

private:
    void mergesort_odd_even(vector<int>& array, int start_position, int finish_position);
    void merge_odd_even(vector<int>& array, int start_position, int finish_position, int distance_to_compare);
    static void compare_and_swap(vector<int>& array, int first_index, int second_index);

};


#endif //SORTING_NETWORK_ODD_EVEN_MERGESORT_H
