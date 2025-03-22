#include "four_way_mergesort.h"


/**
 * 4-way mergesort.
 *
 * @warning work only with a squared matrix.
 *
 * @details the sorted matrix is sorted in row-major direction.
 *
 * @param matrix the unsorted matrix.
 */
void Four_Way_Mergesort::four_way_mergesort(vector<vector<int>> &matrix) {
    roughsort(matrix, static_cast<int>(matrix.size()));
    sort_rows(matrix);
}


/**
 * The roughsort algorithm of 4-way mergesort.
 *
 * @details transform a unsorted matrix into a roughly sorted matrix.
 *
 * @param matrix the unsorted matrix.
 * @param k the matrix size.
 */
void Four_Way_Mergesort::roughsort(vector<vector<int>> &matrix, const int k) {
    if(k > 1) {
        const int m = k / 2;

        roughsort(matrix, m);
        merge_four_way_mergesort(matrix);
    }
}

/**
 * The merge algorithm of 4-way mergesort.
 *
 * @param matrix the unsorted array.
 */
void Four_Way_Mergesort::merge_four_way_mergesort(vector<vector<int>> &matrix) {
    const int k = static_cast<int>(matrix.size());
    const int m = k / 2;

    //sort rows in subarrays
    for (int i = 0; i < m; i++) { //ascending in the upper subarrays
        sort(matrix[i].begin(), matrix[i].end());
    }
    for (int i = m; i < k; i++) { //descending in the lower subarrays
        sort(matrix[i].rbegin(), matrix[i].rend());
    }

    sort_columns(matrix);

    //sort the rows
    for (int i = 0; i < k; i++) {
        if (i % 2 == 0) { //odd rows ascending
            sort(matrix[i].rbegin(), matrix[i].rend());
        }
        else { //even rows descending
            sort(matrix[i].begin(), matrix[i].end());
        }
    }

    sort_columns(matrix);
}

/**
 * Function that sorts the rows.
 *
 * @param matrix the unsorted matrix.
 */
void Four_Way_Mergesort::sort_rows(vector<vector<int>> &matrix) {
    for (auto &row : matrix) {
        sort(row.begin(), row.end());
    }
}

/**
 * Function that sorts the columns.
 *
 * @param matrix the unsorted matrix.
 */
void Four_Way_Mergesort::sort_columns(vector<vector<int>> &matrix) {
    const int n = static_cast<int>(matrix.size());

    for (int j = 0; j < n; j++) {
        vector<int> column(n);

        for (int i = 0; i < n; i++) {
            column[i] = matrix[i][j];
        }

        sort(column.begin(), column.end());

        for (int i = 0; i < n; i++) {
            matrix[i][j] = column[i];
        }
    }
}
