#include "odd_even_transposition_sort.h"

/**
 * Odd-even transposition adapted_bitonic_sort.
 *
 * @details
 * Odd-even transposition adapted_bitonic_sort step:
 *  1. odd phase
 *  2. even phase
 *
 * @param unsorted_array the unsorted array.
 */
void Odd_Even_Transposition_Sort::odd_even_transposition_sort(vector<int>& unsorted_array) {
    ///Array size.
    int array_size = unsorted_array.size();
    ///The array is is_sorted or not.
    bool is_sorted = false;


    while (!is_sorted) {
        is_sorted = true;

        //odd phase
        for (int i = 1; i < array_size - 1; i += 2) {
            if (unsorted_array[i] > unsorted_array[i + 1]) {
                swap(unsorted_array[i], unsorted_array[i + 1]);
                is_sorted = false;
            }
        }

        //even phase
        for (int i = 0; i < array_size - 1; i += 2) {
            if (unsorted_array[i] > unsorted_array[i + 1]) {
                swap(unsorted_array[i], unsorted_array[i + 1]);
                is_sorted = false;
            }
        }
    }
}
