#include "odd_even_transposition_sort.h"


/**
 * Odd-even transposition sort.
 *
 * @details C(n) = n (n - 1)/2
 * @details T_{parallel}(n) = n
 *
 * @note Odd-even transposition sort step: \n 1. odd phase; \n 2. even phase.
 *
 * @param unsorted_array the unsorted array.
 */
void Odd_Even_Transposition_Sort::odd_even_transposition_sort(vector<int>& unsorted_array) {
    ///Array size.
    const int array_size = static_cast<int>(unsorted_array.size());


    for (int w = 0; w < array_size / 2; ++w) {
        //odd phase
        oets_odd_step(unsorted_array);;

        //even phase
        oets_even_step(unsorted_array);
    }
}

/**
 * The even step.
 *
 * @details C(n) = n / 2
 * @details T_{parallel)(n) = 1
 *
 * @param unsorted_array the unsorted array.
 */
void Odd_Even_Transposition_Sort::oets_even_step(vector<int>& unsorted_array) {
    ///Array size.
    const int array_size = static_cast<int>(unsorted_array.size());


#pragma omp parallel for
    for (int i = 0; i < array_size - 1; i += 2) {
        if (unsorted_array[i] > unsorted_array[i + 1]) {
            std::swap(unsorted_array[i], unsorted_array[i + 1]);
        }
    }
}

/**
 * The odd step.
 *
 * @details C(n) = n / 2
 * @details T_{parallel)(n) = 1
 *
 * @param unsorted_array the unsorted array.
 */
void Odd_Even_Transposition_Sort::oets_odd_step(vector<int>& unsorted_array) {
    ///Array size.
    const int array_size = static_cast<int>(unsorted_array.size());


#pragma omp parallel for
    for (int i = 1; i < array_size - 1; i += 2) {
        if (unsorted_array[i] > unsorted_array[i + 1]) {
            std::swap(unsorted_array[i], unsorted_array[i + 1]);
        }
    }
}
