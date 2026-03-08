#include "../odd-even_transposition_sort/odd_even_transposition_sort.h"
#include "four_way_mergesort.h"


/**
 * 4-way mergesort.
 *
 * @warning work only with a squared matrix.
 *
 * @details C(n) = 4n^3 - 4n^2 - 2n^2 log_2{n} + (n^3 - n^2)/ 2 = 9/2(n^3 - n^2) - 2n^2 log_2{n}
 * @details T_{parallel}(n) = 6n + n = 7n
 *
 * @note the sorted matrix is sorted in row-major direction.
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
 * @details C(n) = 4C(n/2) + 2(n^3 - n^2), C(1) = 0
 * @details --> C(n) = 4n^3 - 4n^2 - 2n^2 log_2{n}
 * @details T_{parallel}(n) = 6n
 *
 * @note transform a unsorted matrix into a roughly sorted matrix.
 *
 * @param matrix the unsorted matrix.
 * @param k the matrix size.
 */
void Four_Way_Mergesort::roughsort(vector<vector<int>> &matrix, const int k) {
    if(k > 1) {
        ///The half size.
        const int half = k / 2;

        //define the 4 {k/2 x k/2}-subarray
        ///Sub-matrix 1.
        vector<vector<int>> sub_matrix_1 = extract_submatrix(matrix, 0, 0, half);
        ///Sub-matrix 2.
        vector<vector<int>> sub_matrix_2 = extract_submatrix(matrix, 0, half, half);
        ///Sub-matrix 3.
        vector<vector<int>> sub_matrix_3 = extract_submatrix(matrix, half, 0, half);
        ///Sub-matrix 4.
        vector<vector<int>> sub_matrix_4 = extract_submatrix(matrix, half, half, half);


        //apply roughsort recursively to the 4 {k/2 x k/2}-subarray
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                roughsort(sub_matrix_1, half);
            }

            #pragma omp section
            {
                roughsort(sub_matrix_2, half);
            }

            #pragma omp section
            {
                roughsort(sub_matrix_3, half);
            }

            #pragma omp section
            {
                roughsort(sub_matrix_4, half);
            }
        }

        //insert submatrices back into the main matrix
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
 * @details C(n) = n (n(n - 1)/2) + n (n(n - 1)/2) + n (n(n - 1)/2) + n (n(n - 1)/2) = 2(n^3 - n^2)
 * @details T_{parallel}(n) = n/2 + n + n + n/2 = 3n
 *
 * @param matrix the unsorted array.
 */
void Four_Way_Mergesort::merge_four_way_mergesort(vector<vector<int>> &matrix) {
    ///The matrix size.
    const int k = static_cast<int>(matrix.size());
    ///The half size.
    const int m = k / 2;


    //sort the rows of the subarrays in parallel
    #pragma omp parallel for
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j += m) { //j = 0 (left), j = m (right)
            if (i < m) { //upper half
                vector<int> temp(matrix[i].begin() + j, matrix[i].begin() + j + m);

                Odd_Even_Transposition_Sort::odd_even_transposition_sort(temp); //ascending
                copy(temp.begin(), temp.end(), matrix[i].begin() + j);
            }
            else { //lower half
                vector<int> temp(matrix[i].begin() + j, matrix[i].begin() + j + m);

                Odd_Even_Transposition_Sort::odd_even_transposition_sort(temp);
                reverse(temp.begin(), temp.end()); //descending
                copy(temp.begin(), temp.end(), matrix[i].begin() + j);
            }
        }
    }

    //sort the columns
    sort_columns(matrix);

    #pragma omp parallel for
    for (int i = 0; i < k; i++) {
        if (i % 2 == 0) { //even rows descending
            Odd_Even_Transposition_Sort::odd_even_transposition_sort(matrix[i]);
            reverse(matrix[i].begin(), matrix[i].end());
        }
        else { //odd rows ascending
            Odd_Even_Transposition_Sort::odd_even_transposition_sort(matrix[i]);
        }
    }

    //sort the columns
    sort_columns(matrix);
}


/**
 * Function that sorts the rows.
 *
 * @details C(n) = n (n(n - 1)/2) = (n^3 - n^2)/2
 * @details T_{parallel}(n) = n
 *
 * @note To sort the rows, use the OETS.
 *
 * @param matrix the unsorted matrix.
 */
void Four_Way_Mergesort::sort_rows(vector<vector<int>> &matrix) {
    #pragma omp parallel for
    for (auto & row : matrix) {
        Odd_Even_Transposition_Sort::odd_even_transposition_sort(row);
    }
}

/**
 * Function that sorts the columns.
 *
 * @details C(n) = n (n(n - 1)/2)
 * @details T_{parallel}(n) = n
 *
 * @param matrix the unsorted matrix.
 */
void Four_Way_Mergesort::sort_columns(vector<vector<int>> &matrix) {
    ///The matrix size.
    const int n = static_cast<int>(matrix.size());


    #pragma omp parallel for
    for (int j = 0; j < n; j++) {
        vector<int> column(n);

        for (int i = 0; i < n; i++) {
            column[i] = matrix[i][j];
        }

        //sort the column in ascending order
        Odd_Even_Transposition_Sort::odd_even_transposition_sort(column);

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
    ///The sub-matrix.
    vector sub_matrix(submatrix_size, vector<int>(submatrix_size));


    #pragma omp parallel for
    for (int i = 0; i < submatrix_size; i++) {
        copy(matrix[row + i].begin() + column, matrix[row + i].begin() + column + submatrix_size,
             sub_matrix[i].begin());
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
    ///The sub-matrix size.
    const int submatrix_size = static_cast<int>(sub_matrix.size());


    #pragma omp parallel for
    for (int i = 0; i < submatrix_size; i++) {
        copy(sub_matrix[i].begin(), sub_matrix[i].end(), matrix[row + i].begin() + column);
    }
}
