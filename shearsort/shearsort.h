#ifndef SHEARSORT_H
#define SHEARSORT_H


#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


class Shearsort {
public:
    static void shearSort(vector<vector<int>>& matrix);

private:
    static void sort_rows(vector<vector<int>>& matrix);

    static void sort_columns(vector<vector<int>>& matrix);
};



#endif //SHEARSORT_H
