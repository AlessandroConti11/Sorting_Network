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
        const int half = k / 2;

        //define the 4 {k/2 x k/2}-subarray
        vector<vector<int>> sub_matrix_1 = extract_submatrix(matrix, 0, 0, half);
        vector<vector<int>> sub_matrix_2 = extract_submatrix(matrix, 0, half, half);
        vector<vector<int>> sub_matrix_3 = extract_submatrix(matrix, half, 0, half);
        vector<vector<int>> sub_matrix_4 = extract_submatrix(matrix, half, half, half);


        //apply roughsort recursively to the 4 {k/2 x k/2}-subarray
        roughsort(sub_matrix_1, half);
        roughsort(sub_matrix_2, half);
        roughsort(sub_matrix_3, half);
        roughsort(sub_matrix_4, half);

        //insert submatrices back into main matrix
        insertSubMatrix(matrix, sub_matrix_1, 0, 0);
        insertSubMatrix(matrix, sub_matrix_2, 0, half);
        insertSubMatrix(matrix, sub_matrix_3, half, 0);
        insertSubMatrix(matrix, sub_matrix_4, half, half);

        //4-way merge
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

    //sort the rows of the subarrays
    for (int i = 0; i < m; i++) { //ascending in the upper subarrays
        sort(matrix[i].begin(), matrix[i].end());
    }
    for (int i = m; i < k; i++) { //descending in the lower subarrays
        sort(matrix[i].rbegin(), matrix[i].rend());
    }

    //sort the columns
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

    //sort the columns
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

    //sort each column
    for (int j = 0; j < n; j++) {
        vector<int> column(n);

        for (int i = 0; i < n; i++) {
            column[i] = matrix[i][j];
        }

        //sort the column in ascending order
        sort(column.begin(), column.end());

        for (int i = 0; i < n; i++) {
            matrix[i][j] = column[i];
        }
    }
}


/**
 * Function that extracts a submatrix from a matrix.
 *
 * @param matrix the original matrix.
 * @param row the row.
 * @param column the column.
 * @param submatrix_size the submatrix size.
 * @return the submatrix.
 */
vector<vector<int>> Four_Way_Mergesort::extract_submatrix(const vector<vector<int>>& matrix, const int row, const int column, const int submatrix_size) {
    vector sub_matrix(submatrix_size, vector<int>(submatrix_size));

    for (int i = 0; i < submatrix_size; i++) {
        copy(matrix[row + i].begin() + column, matrix[row + i].begin() + column + submatrix_size, sub_matrix[i].begin());
    }

    return sub_matrix;
}

/**
 * Function that inserts a submatrix into a matrix.
 *
 * @param matrix the matrix.
 * @param sub_matrix the submatrix to insert.
 * @param row the row.
 * @param column the column.
 */
void Four_Way_Mergesort::insertSubMatrix(vector<vector<int>>& matrix, const vector<vector<int>>& sub_matrix, const int row, const int column) {
    const int submatrix_size = static_cast<int>(sub_matrix.size());

    for (int i = 0; i < submatrix_size; i++) {
        copy(sub_matrix[i].begin(), sub_matrix[i].end(), matrix[row + i].begin() + column);
    }
}
