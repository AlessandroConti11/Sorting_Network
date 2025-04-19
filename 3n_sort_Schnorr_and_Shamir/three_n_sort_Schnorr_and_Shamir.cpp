#include "three_n_sort_Schnorr_and_Shamir.h"


/**
 * 3n-sort of Schnorr and Shamir.
 *
 * @warning work only with a squared matrix.
 *
 * @details the sorted matrix is sorted in snake direction.
 *
 * @param matrix the unsorted matrix.
 */
void Three_N_Sort_Schnorr_and_Shamir::three_n_sort(vector<vector<int>> &matrix) {
    const int n = static_cast<int>(matrix.size());
    const int k = static_cast<int>(round(pow(n, 1 / 4)));
    const int block_size = static_cast<int>(round(pow(n, 3 / 4)));

    sort_blocks(matrix, block_size); //n^{3/4}
    k_way_unshuffle(matrix, k); //n^{1/4} on rows
    sort_blocks(matrix, block_size); //n^{3/4}
    sort_columns(matrix);
    sort_vertical_slices(matrix, block_size); //n^{3/4}
    sort_rows_alternating_direction(matrix);
    odd_even_transposition_sort_snake(matrix); //n^{3/4} steps
}


/**
 * k-way unshuffle operation of 3n-sort of Schnorr and Shamir.
 *
 * @param matrix the unsorted matrix.
 * @param k the number of unshuffle way.
 */
void Three_N_Sort_Schnorr_and_Shamir::k_way_unshuffle(vector<vector<int>> &matrix, const int k) {
    const int n = static_cast<int>(matrix.size());
    const int block_size = n / k;
    vector temp(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[i][j % k * block_size + j / k] = matrix[i][j];
        }
    }

    matrix = move(temp);
}


/**
 * Function that sorts the blocks of a matrix.
 *
 * @param matrix the unsorted matrix.
 * @param block_size the block size.
 */
void Three_N_Sort_Schnorr_and_Shamir::sort_blocks(vector<vector<int>> &matrix, const int block_size) {
    const int n = static_cast<int>(matrix.size());

    for (int i = 0; i < n; i += block_size) {
        for (int j = 0; j < n; j += block_size) {
            vector<int> temp(block_size * block_size);
            int index = 0;

            for (int bi = 0; bi < block_size; ++bi) {
                for (int bj = 0; bj < block_size; ++bj) {
                    temp[index++] = matrix[i + bi][j + bj];
                }
            }

            sort(temp.begin(), temp.end());

            index = 0;
            for (int bi = 0; bi < block_size; ++bi) {
                for (int bj = 0; bj < block_size; ++bj) {
                    matrix[i + bi][j + bj] = temp[index++];
                }
            }
        }
    }
}

/**
 * Function that sorts the columns of a matrix.
 *
 * @param matrix the unsorted matrix.
 */
void Three_N_Sort_Schnorr_and_Shamir::sort_columns(vector<vector<int>> &matrix) {
    const int n = static_cast<int>(matrix.size());

    for (int j = 0; j < n; ++j) {
        vector<int> temp(n);

        for (int i = 0; i < n; ++i) {
            temp[i] = matrix[i][j];
        }

        sort(temp.begin(), temp.end());

        for (int i = 0; i < n; ++i) {
            matrix[i][j] = temp[i];
        }
    }
}

/**
 * Function that sorts the vertical slices.
 *
 * @param matrix the unsorted matrix.
 * @param slice_width the slice width.
 */
void Three_N_Sort_Schnorr_and_Shamir::sort_vertical_slices(vector<vector<int>> &matrix, const int slice_width) {
    const int n = static_cast<int>(matrix.size());

    for (int j = 0; j < n; j += slice_width) {
        vector<int> temp;
        temp.reserve(n * slice_width);

        for (int i = 0; i < n; ++i) {
            for (int sj = 0; sj < slice_width && j + sj < n; ++sj) {
                temp.push_back(matrix[i][j + sj]);
            }
        }

        sort(temp.begin(), temp.end());

        int index = 0;

        for (int i = 0; i < n; ++i) {
            for (int sj = 0; sj < slice_width && j + sj < n; ++sj) {
                matrix[i][j + sj] = temp[index++];
            }
        }

    }
}

/**
 * Function that sorts the rows in alternating direction.
 *
 * @param matrix the unsorted matrix.
 */
void Three_N_Sort_Schnorr_and_Shamir::sort_rows_alternating_direction(vector<vector<int>> &matrix) {
    const int n = static_cast<int>(matrix.size());

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) { //sorted in ascending order
            sort(matrix[i].begin(), matrix[i].end());
        }
        else { //sorted in descending order
            sort(matrix[i].rbegin(), matrix[i].rend());
        }
    }
}

/**
 * Function that executes the odd-even transposition sort to the snake.
 *
 * @param matrix the unsorted matrix.
 */
void Three_N_Sort_Schnorr_and_Shamir::odd_even_transposition_sort_snake(vector<vector<int>> &matrix) {
    const int n = static_cast<int>(matrix.size());
    const int steps = static_cast<int>(pow(n, 0.75)); // Only n^{3/4} steps
    const int total = n * n;
    vector<int> snake;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) { //sorted in ascending order
            snake.insert(snake.end(), matrix[i].begin(), matrix[i].end());
        }
        else { //sorted in descending order
            snake.insert(snake.end(), matrix[i].rbegin(), matrix[i].rend());
        }
    }

    //partial odd-even transposition sort (n^{3/4} steps)
    for (int step = 0; step < steps; ++step) {
        int start = step % 2; //even or odd step

        for (int i = start; i + 1 < total; i += 2) {
            if (snake[i] > snake[i + 1]) {
                swap(snake[i], snake[i + 1]);
            }
        }
    }

    int index = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            copy_n(snake.begin() + index, n, matrix[i].begin());
        }
        else {
            copy_n(snake.begin() + index, n, matrix[i].rbegin());
        }
        index += n;
    }
}
