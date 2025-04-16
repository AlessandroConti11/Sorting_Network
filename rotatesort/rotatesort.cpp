#include "rotatesort.h"


/**
 * Rotatesort.
 *
 * @warning work only with a squared matrix.
 *
 * @details the sorted matrix is sorted in row-major direction.
 *
 * @param matrix the unsorted matrix.
 */
void Rotatesort::rotatesort(vector<vector<int>> &matrix) {
    const int n = static_cast<int>(matrix.size());

    //balance each vertical slice
    balance(matrix, false);

    //unblock
    unblock(matrix);

    //balance each horizontal slice - transpose, balance, transpose back
    vector transposed(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    balance(transposed, true);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = transposed[j][i];
        }
    }

    //unblock
    unblock(matrix);

    //shear 3 times
    shear(matrix);
    shear(matrix);
    shear(matrix);

    //sort the rows
    for (auto &row : matrix) {
        sort(row.begin(), row.end());
    }
}


/**
 * The balance operation of rotatesort.
 *
 * @param matrix the matrix.
 * @param horizontal_slice the balance operation is on the horizontal slices.
 */
void Rotatesort::balance(vector<vector<int>> &matrix, bool horizontal_slice) {
    const int n = static_cast<int>(matrix.size());
    const int sqrt_n = static_cast<int>(sqrt(n));


    for (int slice_i = 0; slice_i < sqrt_n; slice_i++) {
        ///The slice.
        vector slice(n, vector<int>(sqrt_n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < sqrt_n; ++j) {
                slice[i][j] = horizontal_slice ?
                   matrix[slice_i * sqrt_n + j][i] : //{sqrt(n) x n}
                   matrix[i][slice_i * sqrt_n + j]; //{n x sqrt(n)}
            }
        }

        sort_columns(slice);
        rotate_rows_balance(slice);
        sort_columns(slice);

        // insert slice back
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < sqrt_n; ++j) {
                if (horizontal_slice) {
                    matrix[slice_i * sqrt_n + j][i] = slice[i][j];
                }
                else {
                    matrix[i][slice_i * sqrt_n + j] = slice[i][j];
                }
            }
        }
    }
}

/**
 * The unblock operation of rotatesort.
 * 
 * @param matrix the unsorted matrix.
 */
void Rotatesort::unblock(vector<vector<int>> &matrix) {
    rotate_rows_unblock(matrix);
    sort_columns(matrix);
}

/**
 * The shear operation of rotatesort.
 *
 * @param matrix the unsorted array.
 */
void Rotatesort::shear(vector<vector<int>> &matrix) {
    const int n = static_cast<int>(matrix.size());

    //sort the rows in alternating direction
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) { //sorted in ascending order
            sort(matrix[i].begin(), matrix[i].end());
        }
        else { //sorted in descending order
            sort(matrix[i].rbegin(), matrix[i].rend());
        }
    }

    sort_columns(matrix);
}


/**
 * Function that sorts the columns.
 *
 * @param matrix the unsorted matrix.
 */
void Rotatesort::sort_columns(vector<vector<int>> &matrix) {
    const int n = static_cast<int>(matrix.size());
    vector<int> temp(n);

    for (int col = 0; col < n; ++col) {
        for (int row = 0; row < n; ++row) {
            temp[row] = matrix[row][col];
        }

        sort(temp.begin(), temp.end());

        for (int row = 0; row < n; ++row) {
            matrix[row][col] = temp[row];
        }
    }

}

/**
 * Function used in balance operation that rotates the rows.
 *
 * @details rotate row i by {i % sqrt(n)} positions.
 *
 * @param matrix the unsorted matrix.
 */
void Rotatesort::rotate_rows_balance(vector<vector<int>> &matrix) {
    const int n = static_cast<int>(matrix.size());
    const int sqrt_n = static_cast<int>(sqrt(n));


    for (int i = 0; i < n; ++i) {
        //rotate row i by (i % sqrt(n)) positions
        rotate(matrix[i].begin(), matrix[i].begin() + (i % sqrt_n), matrix[i].end());
    }
}

/**
 * Function used in unblock operation that rotates the rows.
 *
 * @details rotate row i by {(i * sqrt(n)) % n} positions.
 *
 * @param matrix the unsorted matrix.
 */
void Rotatesort::rotate_rows_unblock(vector<vector<int>> &matrix) {
    const int n = static_cast<int>(matrix.size());
    const int sqrt_n = static_cast<int>(sqrt(n));


    for (int i = 0; i < n; ++i) {
        //rotate row i by (i * sqrt(n)) % n positions (used in unblock)
        rotate(matrix[i].begin(), matrix[i].begin() + ((i * sqrt_n) % n), matrix[i].end());
    }
}
