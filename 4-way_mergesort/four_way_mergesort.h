#ifndef SORTING_NETWORK_FOUR_WAY_MERGESORT_H
#define SORTING_NETWORK_FOUR_WAY_MERGESORT_H


#include <vector>
#include <algorithm>
using namespace std;


class Four_Way_Mergesort {
public:
    static void four_way_mergesort(vector<vector<int>> &matrix);

private:
    static void roughsort(vector<vector<int>> &matrix, int k);
    static void merge_four_way_mergesort(vector<vector<int>> &matrix);

    static void sort_rows(vector<vector<int>> &matrix);
    static void sort_columns(vector<vector<int>> &matrix);
};


#endif //SORTING_NETWORK_FOUR_WAY_MERGESORT_H
