#include "three_n_sort_Schnorr_and_Shamir.h"

#include "../4-way_mergesort/four_way_mergesort.h"
#include "../odd-even_transposition_sort/odd_even_transposition_sort.h"


/**
 * 3n-sort of Schnorr and Shamir.
 *
 * @warning work only with a squared matrix.
 *
 * @details C(n) = O(n^3)
 * @details T_{parallel}(n) = 3n + O(n^{3/4})
 *
 * @note the sorted matrix is sorted in snake direction.
 *
 * @param matrix the unsorted matrix.
 */
void Three_N_Sort_Schnorr_and_Shamir::three_n_sort(vector<vector<int>> &matrix) {
    ///The matrix size.
    const int n = static_cast<int>(matrix.size());


    //sort blocks
    sort_blocks(matrix); //n^{3/4}
    //{n^{1/4}}-way unshuffle along the rows
    k_way_unshuffle(matrix, static_cast<int>(ceil(pow(n, 1.0 / 4.0)))); //n^{1/4} on rows
    //sort blocks
    sort_blocks(matrix); //n^{3/4}
    //sort columns
    sort_columns(matrix);
    //sort vertical slices
    sort_vertical_slices(matrix); //n^{3/4}
    //sort rows
    sort_rows_alternating_direction(matrix);
    //n^{3/4} steps of oets
    odd_even_transposition_sort_snake(matrix); //n^{3/4} steps
}


/**
 * k-way unshuffle operation of 3n-sort of Schnorr and Shamir.
 *
 * @details C(n) = 0
 * @details T_{parallel}(n) = n
 *
 * @param matrix the unsorted matrix.
 * @param k the number of unshuffle way.
 */
void Three_N_Sort_Schnorr_and_Shamir::k_way_unshuffle(vector<vector<int>> &matrix, const int k) {
    ///The matrix size.
    const int n = static_cast<int>(matrix.size());
    ///The block size.
    const int block_size = n / k;
    ///The permutated matrix.
    vector temp(n, vector<int>(n));


    #pragma omp parallel for collapse(2)
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
 * @details C(n) = n^{1/2} (9/2((n^{3/4})^3 - (n^{3/4})^2) - 2(n^{3/4})^2 log_2{(n^{3/4})}) = 9/2(n^{9/8} - n^{3/4}) - 2n^{3/4} log_2{n^{3/4}}
 * @details T_{parallel}(n) = 7n^{3/4}
 *
 * @param matrix the unsorted matrix.
 */
void Three_N_Sort_Schnorr_and_Shamir::sort_blocks(vector<vector<int>> &matrix) {
    ///The matrix size.
    const int n = static_cast<int>(matrix.size());
    ///The block size.
    const int block_size = static_cast<int>(pow(n, 3.0 / 4.0));


    #pragma omp parallel for collapse(2) schedule(dynamic)
    for (int i = 0; i < n; i += block_size) {
        for (int j = 0; j < n; j += block_size) {
            ///The temporary block.
            vector<vector<int>> temp(block_size, vector<int>(block_size));

            for (int bi = 0; bi < block_size; ++bi) {
                for (int bj = 0; bj < block_size; ++bj) {
                    temp[bi][bj] = matrix[i + bi][j + bj];
                }
            }

            Four_Way_Mergesort::four_way_mergesort(temp);

            for (int bi = 0; bi < block_size; ++bi) {
                for (int bj = 0; bj < block_size; ++bj) {
                    matrix[i + bi][j + bj] = temp[bi][bj];
                }
            }
        }
    }
}

/**
 * Function that sorts the columns of a matrix.
 *
 * @details C(n) = n n(n - 1)/2 = n^2(n - 1)/2
 * @details T_{parallel}(n) = n
 *
 * @param matrix the unsorted matrix.
 */
void Three_N_Sort_Schnorr_and_Shamir::sort_columns(vector<vector<int>> &matrix) {
    ////The matrix size.
    const int n = static_cast<int>(matrix.size());


    #pragma omp parallel for
    for (int j = 0; j < n; ++j) {
        ///The column.
        vector<int> column(n);

        for (int i = 0; i < n; ++i) {
            column[i] = matrix[i][j];
        }

        Odd_Even_Transposition_Sort::odd_even_transposition_sort(column);

        for (int i = 0; i < n; ++i) {
            matrix[i][j] = column[i];
        }
    }
}

/**
 * Function that sorts the vertical slices.
 *
 * @details C(n) = n^{1/4} ((n n^{3/4})(n n^{3/4} - 1))/2 = n^2 (n^{7/4} - 1)/2
 * @details T_{parallel}(n) = n n^{3/4} = n^{7/4}
 *
 * @note the vertical slices can be sorted in time O(n^{3/4}), because they contain a region of only n^{1/4} dirty rows
 * @note e.g. by sorting the blocks and subsequently sorting the blocks vertically overlapping by n^{1/4} rows.
 *
 * @param matrix the unsorted matrix.
 */
void Three_N_Sort_Schnorr_and_Shamir::sort_vertical_slices(vector<vector<int>> &matrix) {
    ///The matrix size.
    const int n = static_cast<int>(matrix.size());
    ///The slice width.
    const int slice_width = static_cast<int>(pow(n, 3.0 / 4.0));


    #pragma omp parallel for schedule(dynamic)
    for (int j = 0; j < n; j += slice_width) {
        ///The slice.
        vector<int> temp;
        temp.reserve(n * slice_width);

        for (int i = 0; i < n; ++i) {
            for (int sj = 0; sj < slice_width && j + sj < n; ++sj) {
                temp.push_back(matrix[i][j + sj]);
            }
        }

        Odd_Even_Transposition_Sort::odd_even_transposition_sort(temp);

        ///The index in the slice.
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
 * @details C(n) = n n(n - 1)/2 = n^2 (n - 1)/2
 * @details T_{parallel}(n) = n
 *
 * @param matrix the unsorted matrix.
 */
void Three_N_Sort_Schnorr_and_Shamir::sort_rows_alternating_direction(vector<vector<int>> &matrix) {
    ///The matrix size.
    const int n = static_cast<int>(matrix.size());


    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) { //sorted in ascending order
            Odd_Even_Transposition_Sort::odd_even_transposition_sort(matrix[i]);
        }
        else { //sorted in descending order
            Odd_Even_Transposition_Sort::odd_even_transposition_sort(matrix[i]);
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
}

/**
 * Function that executes the odd-even transposition sort to the snake.
 *
 * @details C(n) = n^{3/4}/2 (n^2/2 + n^2/2) = n^{7/4}/2
 * @details T_{parallel}(n) = n^{3/4}
 *
 * @param matrix the unsorted matrix.
 */
void Three_N_Sort_Schnorr_and_Shamir::odd_even_transposition_sort_snake(vector<vector<int>> &matrix) {
    ///The matrix size.
    const int n = static_cast<int>(matrix.size());
    ///The number of odd-even transposition steps.
    const int steps = static_cast<int>(round(pow(n, 3.0 / 4.0))); //only n^{3/4} steps
    ///The array.
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
    for (int step = 0; step < steps / 2; ++step) {
        Odd_Even_Transposition_Sort::oets_odd_step(snake);
        Odd_Even_Transposition_Sort::oets_even_step(snake);
    }

    for (int i = 0; i < n; ++i) {
        int index = i * n;

        if (i % 2 == 0) {
            copy_n(snake.begin() + index, n, matrix[i].begin());
        }
        else {
            copy_n(snake.begin() + index, n, matrix[i].rbegin());
        }
    }
}
