#include "ls3_sort.h"


/**
 * LS3 sort.
 *
 * @attention work only with a squared matrix.
 *
 * @details the sorted matrix is sorted in snake direction.
 *
 * @param matrix the unsorted matrix.
 */
void LS3_Sort::ls3_sort(vector<vector<int>> &matrix) {
    sort_ls3(matrix, static_cast<int>(matrix.size()));
}


/**
 * The sort algorithm of LS3 sort.
 *
 * @param matrix the unsorted matrix.
 * @param n the matrix size.
 */
void LS3_Sort::sort_ls3(vector<vector<int>>& matrix, const int n) {
    if(n > 1) {
        const int half = n / 2;

        //define the 4 {n/2 X n/2}-subarray
        vector<vector<int>> sub_matrix_1 = extract_submatrix(matrix, 0, 0, half);
        vector<vector<int>> sub_matrix_2 = extract_submatrix(matrix, 0, half, half);
        vector<vector<int>> sub_matrix_3 = extract_submatrix(matrix, half, 0, half);
        vector<vector<int>> sub_matrix_4 = extract_submatrix(matrix, half, half, half);


        //apply LS3 sort recursively to the 4 {n/2 X n/2}-subarray
        sort_ls3(sub_matrix_1, half);
        sort_ls3(sub_matrix_2, half);
        sort_ls3(sub_matrix_3, half);
        sort_ls3(sub_matrix_4, half);

        insertSubMatrix(matrix, sub_matrix_1, 0, 0);
        insertSubMatrix(matrix, sub_matrix_2, 0, half);
        insertSubMatrix(matrix, sub_matrix_3, half, 0);
        insertSubMatrix(matrix, sub_matrix_4, half, half);

        //LS3 merge
        merge_ls3(matrix, n);
    }
}

/**
 * The merge algorithm of LS3 sort.
 *
 * @param matrix the unsorted matrix.
 * @param k the matrix size.
 */
void LS3_Sort::merge_ls3(vector<vector<int>>& matrix, const int k) {
    shuffle(matrix, k);
    sort_double_column_in_snake_direction(matrix, k);
    oets_step(matrix, k);
}


/**
 * The shuffle basic operation of LS3 sort.
 *
 * @param matrix the unsorted matrix.
 * @param n the matrix size.
 */
void LS3_Sort::shuffle(vector<vector<int>>& matrix, const int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
}

/**
 * The oets basic operation of LS3 sort.
 *
 * @param matrix the unsorted matrix.
 * @param n the matrix size.
 */
void LS3_Sort::oets_step(vector<vector<int>>& matrix, const int n) {
    vector<int> flattened;

    for (size_t i = 0; i < matrix.size(); i++) {
        if (i % 2 == 0) {
            copy(matrix[i].begin(), matrix[i].end(), back_inserter(flattened));
        }
        else {
            copy(matrix[i].rbegin(), matrix[i].rend(), back_inserter(flattened));
        }
    }

    Odd_Even_Transposition_Sort::odd_even_transposition_sort(flattened);

    int index = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = flattened[index++];
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                matrix[i][j] = flattened[index++];
            }
        }
    }
}


/**
 * Function that sorts each double column in snake-like direction.
 *
 * @param matrix the unsorted matrix.
 * @param n the matrix size.
 */
void LS3_Sort::sort_double_column_in_snake_direction(vector<vector<int>>& matrix, const int n) {
    for (int j = 0; j < n; j += 2) {
        vector<int> column;

        for (int i = 0; i < n; i++) {
            column.push_back(matrix[i][j]);
            if (j + 1 < n) {
                column.push_back(matrix[i][j + 1]);
            }
        }

        Odd_Even_Transposition_Sort::odd_even_transposition_sort(column);

        int index = 0;

        for (int i = 0; i < n; i++) {
            matrix[i][j] = column[index++];
            if (j + 1 < n) {
                matrix[i][j + 1] = column[index++];
            }
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
vector<vector<int>> LS3_Sort::extract_submatrix(const vector<vector<int>>& matrix, const int row, const int column, const int submatrix_size) {
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
void LS3_Sort::insertSubMatrix(vector<vector<int>>& matrix, const vector<vector<int>>& sub_matrix, const int row, const int column) {
    const int submatrix_size = static_cast<int>(sub_matrix.size());

    for (int i = 0; i < submatrix_size; i++) {
        copy(sub_matrix[i].begin(), sub_matrix[i].end(), matrix[row + i].begin() + column);
    }
}
