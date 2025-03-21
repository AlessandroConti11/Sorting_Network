#ifndef SORTING_NETWORK_LS3_SORT_H
#define SORTING_NETWORK_LS3_SORT_H


#include <iostream>
#include <vector>
#include <algorithm>
#include "../odd-even_transposition_sort/odd_even_transposition_sort.h"

using namespace std;


class LS3_Sort {
public:
    void ls3_sort(vector<vector<int>>& matrix);

private:
    void sort_ls3(vector<vector<int>>& matrix, int n);
    static void merge_ls3(vector<vector<int>>& matrix, int k);

    static void shuffle(vector<vector<int>>& matrix, int n);
    static void oets_step(vector<vector<int>>& matrix, int n);

    static void sort_double_column_in_snake_direction(vector<vector<int>>& matrix, int n);
    static vector<vector<int>> extract_submatrix(const vector<vector<int>>& matrix, int row, int column, int submatrix_size);
    static void insertSubMatrix(vector<vector<int>>& matrix, const vector<vector<int>>& sub_matrix, int row, int column);
};


#endif //SORTING_NETWORK_LS3_SORT_H
