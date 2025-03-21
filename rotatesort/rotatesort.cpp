#include "rotatesort.h"


/**
 * Rotatesort.
 *
 * @attention work only with a squared matrix.
 *
 * @details the sorted matrix is sorted in row-major direction.
 *
 * @param matrix the unsorted matrix.
 */
void Rotatesort::rotatesort(vector<vector<int>> &matrix) {
    const int n = static_cast<int>(matrix.size());

    //balance each vertical slice
    balance(matrix);

    //unblock
    unblock(matrix);

    //balance each horizontal slice - transpose, balance, transpose back
    vector<vector<int>> transposed(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    balance(transposed);
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
 * @param vertical_slice the vertical slice.
 */
void Rotatesort::balance(vector<vector<int>> &vertical_slice) {
    sort_columns(vertical_slice);
    rotate_rows(vertical_slice);
    sort_columns(vertical_slice);
}

/**
 * The unblock operation of rotatesort.
 * 
 * @param matrix the unsorted matrix.
 */
void Rotatesort::unblock(vector<vector<int>> &matrix) {
    rotate_rows(matrix);
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
 * Function that rotate the rows.
 *
 * @param matrix the unsorted matrix.
 */
void Rotatesort::rotate_rows(vector<vector<int>> &matrix) {
    for (auto &row : matrix) {
        rotate(row.rbegin(), row.rbegin() + 1, row.rend());
    }
}
