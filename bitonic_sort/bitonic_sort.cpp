#include "bitonic_sort.h"


/**
 * Bitonic Sort
 *
 * @attention work only with array.size() divisible by 2^k.
 *
 * @param array the unsorted array.
 */
void Bitonic_Sort::bitonic_sort(std::vector<int>& array) {
    sort_bitonic(array, 0, array.size(), Bitonic_Sort::ASCENDING);
}


/**
 * The sort algorithm of bitonic sort.
 *
 * @param array the unsorted array.
 * @param start_position the starting position.
 * @param finish_position the finishing position.
 * @param direction the sorting direction.
 */
void Bitonic_Sort::sort_bitonic(vector<int> &array, int start_position, int finish_position, bool direction) {
    if(finish_position > 1) {
        int m = finish_position / 2;

        sort_bitonic(array, start_position, m, Bitonic_Sort::ASCENDING);
        sort_bitonic(array, start_position + m, m, Bitonic_Sort::DESCENDING);

        merge_bitonic(array, start_position, finish_position, direction);
    }
}

/**
 * The merge algorithm of bitonic sort.
 *
 * @param array the unsorted array.
 * @param start_position the starting position.
 * @param finish_position the finishing position.
 * @param direction the sorting direction.
 */
void Bitonic_Sort::merge_bitonic(vector<int> &array, int start_position, int finish_position, bool direction) {
    if(finish_position > 1) {
        int m = finish_position / 2;

        for (int i = start_position; i < start_position + m; ++i) {
            compare_and_swap(array, i, i + m, direction);
        }

        merge_bitonic(array, start_position, m, direction);
        merge_bitonic(array, start_position + m, m, direction);
    }
}

/**
 * Function that compares and swaps two elements based on the sorting direction.
 *
 * @param array the unsorted array.
 * @param first_index the index of the first element to be swapped.
 * @param second_index the index of the second element to be swapped.
 * @param direction the sorting direction.
 */
void Bitonic_Sort::compare_and_swap(vector<int> &array, int first_index, int second_index, bool direction) {
    if(direction == (array[first_index] > array[second_index])) {
        swap(array[first_index], array[second_index]);
    }
}