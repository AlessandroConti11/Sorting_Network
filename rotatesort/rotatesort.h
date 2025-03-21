#ifndef ROTATESORT_H
#define ROTATESORT_H


#include <vector>
#include <algorithm>
using namespace std;


class Rotatesort {
public:
    static void rotatesort(vector<vector<int>> &matrix);

private:
    static void balance(vector<vector<int>> &vertical_slice);
    static void unblock(vector<vector<int>> &matrix);
    static void shear(vector<vector<int>> &matrix);

    static void sort_columns(vector<vector<int>> &matrix);
    static void rotate_rows(vector<vector<int>> &matrix);
};


#endif //ROTATESORT_H
