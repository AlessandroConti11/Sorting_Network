#ifndef TWO_D_ODD_EVEN_TRANSPOSITION_SORT_H
#define TWO_D_ODD_EVEN_TRANSPOSITION_SORT_H


#include <vector>
#include <omp.h>

using namespace std;


class Two_D_Odd_Even_Transposition_Sort {
public:
    static void two_d_odd_even_sort(vector<vector<int>>& matrix);

private:
    static bool sort_row_oets_step(vector<vector<int>>& matrix, bool is_odd);
    static bool sort_column_oets_step(vector<vector<int>>& matrix, bool is_odd);
};


#endif //TWO_D_ODD_EVEN_TRANSPOSITION_SORT_H
