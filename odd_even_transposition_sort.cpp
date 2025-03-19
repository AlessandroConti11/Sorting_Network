#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/**
 * Odd-even transposition sort.
 *
 * @details
 * Odd-even transposition sort step:
 *  1. odd phase
 *  2. even phase
 *
 * @param unsorted_array the unsorted array.
 */
void odd_even_transposition_sort(vector<int>& unsorted_array) {
    ///Array size.
    int array_size = unsorted_array.size();
    ///The array is is_sorted or not.
    bool is_sorted = false;


    while (!is_sorted) {
        is_sorted = true;

        //odd phase
        for (int i = 1; i < array_size - 1; i += 2) {
            if (unsorted_array[i] > unsorted_array[i + 1]) {
                swap(unsorted_array[i], unsorted_array[i + 1]);
                is_sorted = false;
            }
        }

        //even phase
        for (int i = 0; i < array_size - 1; i += 2) {
            if (unsorted_array[i] > unsorted_array[i + 1]) {
                swap(unsorted_array[i], unsorted_array[i + 1]);
                is_sorted = false;
            }
        }
    }
}


int main() {
    vector<int> arr = {2, 1, 4, 9, 5, 3, 6, 10, 8, 7};

    cout << "Unsorted vector\n";
    ranges::for_each(arr, [](int num) { cout << num << " "; });
    cout << endl;
    cout << "\n\n";

    odd_even_transposition_sort(arr);

    cout << "sorted vector\n";
    ranges::for_each(arr, [](int num) { cout << num << " "; });
    cout << endl;

    return 0;
}
