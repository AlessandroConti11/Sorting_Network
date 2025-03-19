#include "odd_even_mergesort.h"


/**
 * Odd-even mergesort algorithm.
 *
 * @attention work only with array.size() divisible by 2^k.
 *
 * @param array the unsorted array.
 */
void Odd_Even_Mergesort::odd_even_mergesort(vector<int>& array) {
    mergesort_odd_even(array, 0, (int) array.size());
}


/**
 * The mergesort algorithm of odd-even mergesort.
 *
 * @param array the unsorted array.
 * @param start_position the starting position.
 * @param finish_position the finishing position.
 */
void Odd_Even_Mergesort::mergesort_odd_even(vector<int>& array, int start_position, int finish_position) {
    if (finish_position > 1) {
        ///The midpoint.
        int midpoint = finish_position / 2;
        
        mergesort_odd_even(array, start_position, midpoint);
        mergesort_odd_even(array, start_position + midpoint, midpoint);
        merge_odd_even(array, start_position, finish_position, 1);
    }
}

/**
 * The merge algorithm of odd-even mergesort.
 *
 * @param array the unsorted array.
 * @param start_position the starting position.
 * @param finish_position the finishing position.
 * @param distance_to_compare the distance of the elements to be compared
 */
void Odd_Even_Mergesort::merge_odd_even(vector<int>& array, int start_position, int finish_position, int distance_to_compare) {
    ///Distance between the elements that are to be compared and exchanged.
    int m = distance_to_compare * 2;

    if (m < finish_position) {
        merge_odd_even(array, start_position, finish_position, m);
        merge_odd_even(array, start_position + distance_to_compare, finish_position, m);

        for (int i = start_position + distance_to_compare; i + distance_to_compare < start_position + finish_position; i += m)
            compare_and_swap(array, i, i + distance_to_compare);
    }
    else {
        compare_and_swap(array, start_position, start_position + distance_to_compare);
    }
}

/**
 * The function compares and swap two elements when the first is greater than the second.
 *
 * @param array the unsorted array.
 * @param first_index The index of the first element to be swapped.
 * @param second_index The index of the second element to be swapped.
 */
void Odd_Even_Mergesort::compare_and_swap(vector<int>& array, int first_index, int second_index) {
    if (array[first_index] > array[second_index]) {
        swap(array[first_index], array[second_index]);
    }
}