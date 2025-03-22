#include "shearsort.h"


/**
 * Shearsort.
 *
 * @warning work only with a squared matrix.
 *
 * @details the sorted matrix is sorted in snake direction.
 *
 * @param matrix the unsorted matrix.
 */
void Shearsort::shearSort(vector<vector<int>>& matrix) {
    const int matrix_size = static_cast<int>(matrix.size());
    const int logn = static_cast<int>(log2(matrix_size)) + 1;

    for (int i = 0; i < logn; i++) {
        sort_rows(matrix);
        sort_columns(matrix);
    }

    sort_rows(matrix);
}


/**
 * Function that sorts the rows.
 *
 * @details sorting direction: even rows from left to right and odd rows from right to left.
 *
 * @param matrix the unsorted matrix.
 */
void Shearsort::sort_rows(vector<vector<int>>& matrix) {
    const int matrix_size = static_cast<int>(matrix.size());

    for (int i = 0; i < matrix_size; i++) {
        if (i % 2 == 0) {
            sort(matrix[i].begin(), matrix[i].end());
        }
        else {
            sort(matrix[i].rbegin(), matrix[i].rend());
        }
    }
}

/**
 * Function that sorts the columns.
 *
 * @param matrix the unsorted matrix.
 */
void Shearsort::sort_columns(vector<vector<int>>& matrix) {
    const int matrix_size = static_cast<int>(matrix.size());

    for (int j = 0; j < matrix_size; j++) {
        vector<int> column(matrix_size);

        for (int i = 0; i < matrix_size; i++) {
            column[i] = matrix[i][j];
        }

        sort(column.begin(), column.end());

        for (int i = 0; i < matrix_size; i++) {
            matrix[i][j] = column[i];
        }
    }
}
