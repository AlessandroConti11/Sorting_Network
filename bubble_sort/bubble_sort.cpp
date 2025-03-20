#include "bubble_sort.h"


/**
 * Bubble Sort algorithm.
 *
 * @param array the unsorted array.
 */
void Bubble_Sort::bubble_Sort(vector<int>& array) {
    int n = (int) array.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
        }
    }
}
