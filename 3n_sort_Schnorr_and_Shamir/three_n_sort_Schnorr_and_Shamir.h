#ifndef THREE_N_SCHNORR_AND_SHAMIR_H
#define THREE_N_SCHNORR_AND_SHAMIR_H


#include <vector>
#include <algorithm>
#include <cmath>
#include "../odd-even_transposition_sort/odd_even_transposition_sort.h"

using namespace std;



class Three_N_Sort_Schnorr_and_Shamir {
public:
    static void three_n_sort(vector<vector<int>> &matrix);

private:
    static void k_way_unshuffle(vector<vector<int>> &matrix, int k);

    static void sort_blocks(vector<vector<int>> &matrix, int block_size);

    static void sort_columns(vector<vector<int>> &matrix);

    static void sort_vertical_slices(vector<vector<int>> &matrix, int slice_width);

    static void sort_rows_alternating_direction(vector<vector<int>> &matrix);

    static void odd_even_transposition_sort_snake(vector<vector<int>> &matrix);
};



#endif //THREE_N_SCHNORR_AND_SHAMIR_H
