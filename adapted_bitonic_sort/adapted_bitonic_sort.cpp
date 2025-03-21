#include "adapted_bitonic_sort.h"


/**
 * Adapted bitonic sort.
 *
 * @details work even if the array.size() is not divisible by 2^k.
 * @param array
 */
void Adapted_Bitonic_Sort::adapted_bitonic_sort(vector<int> &array) {
    sort_adapted_bitonic(array, 0, static_cast<int>(array.size()), ASCENDING);
}


/**
 * The sort algorithm of adapted bitonic sort.
 *
 * @param array the unsorted array.
 * @param start_position the starting position.
 * @param finish_position the finishing position.
 * @param direction the sorting direction.
 */
void Adapted_Bitonic_Sort::sort_adapted_bitonic(vector<int> &array, const int start_position, const int finish_position, const bool direction) {
    if(finish_position > 1) {
        const int m = finish_position / 2;

        sort_adapted_bitonic(array, start_position, m, !direction);
        sort_adapted_bitonic(array, start_position + m, finish_position - m, direction);

        merge_adapted_bitonic(array, start_position, finish_position, direction);
    }
}

/**
 * The merge algorithm of adapted bitonic sort.
 *
 * @param array the unsorted array.
 * @param start_position the starting position.
 * @param finish_position the finishing position.
 * @param direction the sorting direction.
 */
void Adapted_Bitonic_Sort::merge_adapted_bitonic(vector<int> &array, const int start_position, const int finish_position, const bool direction) {
    if(finish_position > 1) {
        const int m = greatest_power_of_2_less_than(finish_position);

        for (int i = start_position; i < start_position + finish_position - m; ++i) {
            compare_and_swap(array, i, i + m, direction);
        }

        merge_adapted_bitonic(array, start_position, m, direction);
        merge_adapted_bitonic(array, start_position + m, finish_position - m, direction);
    }
}

/**
 * Function that compares and swaps two elements based on the sorting direction.
 *
 * @param array the unsorted array.
 * @param first_index the starting position.
 * @param second_index the finishing position.
 * @param direction the sorting direction.
 */
void Adapted_Bitonic_Sort::compare_and_swap(vector<int> &array, const int first_index, const int second_index, const bool direction) {
    if(direction == (array[first_index] > array[second_index])) {
        swap(array[first_index], array[second_index]);
    }
}

/**
 * Function that finds the greatest power of two that is less than or equal to a given number.
 *
 * @param n the input number.
 * @return the greatest power of two less than or equal to the input number.
 */
int Adapted_Bitonic_Sort::greatest_power_of_2_less_than(const int n) {
    int k = 1;

    while (k > 0 && k < n) {
        k = k << 1;
    }

    return k >> 1;
}