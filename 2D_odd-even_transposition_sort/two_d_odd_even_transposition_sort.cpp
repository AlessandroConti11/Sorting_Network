#include "two_d_odd_even_transposition_sort.h"


/**
 * 2D odd-even transposition sort.
 *
 * @warning work only with a squared matrix.
 *
 * @details the sorted matrix is sorted in snake direction.
 *
 * @param matrix the unsorted matrix.
 */
void Two_D_Odd_Even_Transposition_Sort::two_d_odd_even_sort(vector<vector<int>>& matrix) {
    const int matrix_size = static_cast<int>(matrix.size());
    bool is_sorted = false;

    while (!is_sorted) {
        is_sorted = true;

        //apply an oets step to the rows
        for (int i = 0; i < matrix_size; ++i) {
            is_sorted = sort_row_oets_step(matrix[i], i % 2 == 0);
        }

        //apply an oets step to the columns
        for (int j = 0; j < matrix_size; ++j) {
            is_sorted = sort_column_oets_step(matrix, j);
        }
    }
}


/**
 * Function that sorts a row following the specified direction.
 *
 * @details sorting direction: even rows from left to right and odd rows from right to left.
 *
 * @param array the unsorted row.
 * @param direction the sorting direction of the rows.
 * @return true if the column is sorted, false otherwise.
 */
bool Two_D_Odd_Even_Transposition_Sort::sort_row_oets_step(vector<int>& array, const bool direction) {
    const int array_size = static_cast<int>(array.size());
    bool is_sorted = true;

    for (int i = 0; i < array_size; ++i) {
        for (int j = (i % 2 == 0) ? 0 : 1; j < array_size - 1; j += 2) {
            
            if ((direction && array[j] > array[j + 1]) || (!direction && array[j] < array[j + 1])) {
                swap(array[j], array[j + 1]);
                is_sorted = false;
            }
        }
    }

    return is_sorted;
}

/**
 * Function that sorts a column.
 *
 * @param matrix the unsorted matrix.
 * @param column_to_sort the column to sort.
 * @return true if the column is sorted, false otherwise.
 */
bool Two_D_Odd_Even_Transposition_Sort::sort_column_oets_step(vector<vector<int>>& matrix, const int column_to_sort) {
    const int matrix_size = static_cast<int>(matrix.size());
    bool is_sorted = true;

    for (int i = 0; i < matrix_size; ++i) {
        for (int j = (i % 2 == 0) ? 0 : 1; j < (matrix_size - 1); j += 2) {

            if (matrix[j][column_to_sort] > matrix[j + 1][column_to_sort]) {
                swap(matrix[j][column_to_sort], matrix[j + 1][column_to_sort]);
                is_sorted = false;
            }
        }
    }

    return is_sorted;
}
