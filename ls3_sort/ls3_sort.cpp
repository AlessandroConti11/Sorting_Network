#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void shuffleRows(vector<vector<int>>& arr, int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            reverse(arr[i].begin(), arr[i].end());
        }
    }
}

void oddEvenTranspositionSort(vector<int>& arr) {
    int n = arr.size();
    bool sorted = false;
    while (!sorted) {
        sorted = true;

        for (int i = 1; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }

        for (int i = 0; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }
    }
}

void sortDoubleColumns(vector<vector<int>>& arr, int n) {
    for (int j = 0; j < n; j += 2) {
        vector<int> column;
        for (int i = 0; i < n; i++) {
            column.push_back(arr[i][j]);
            if (j + 1 < n) column.push_back(arr[i][j + 1]);
        }
        oddEvenTranspositionSort(column);
        int index = 0;
        for (int i = 0; i < n; i++) {
            arr[i][j] = column[index++];
            if (j + 1 < n) arr[i][j + 1] = column[index++];
        }
    }
}

void applyOETS(vector<vector<int>>& arr, int n) {
    vector<int> flattened;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            flattened.insert(flattened.end(), arr[i].begin(), arr[i].end());
        } else {
            flattened.insert(flattened.end(), arr[i].rbegin(), arr[i].rend());
        }
    }
    oddEvenTranspositionSort(flattened);
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = flattened[index++];
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                arr[i][j] = flattened[index++];
            }
        }
    }
}

void ls3_merge(vector<vector<int>>& arr, int k) {
    shuffleRows(arr, k);
    sortDoubleColumns(arr, k);
    applyOETS(arr, k);
}

void ls3_sort(vector<vector<int>>& arr, int n) {
    if (n <= 1) return;
    int half = n / 2;
    vector<vector<int>> sub1(half, vector<int>(half));
    vector<vector<int>> sub2(half, vector<int>(half));
    vector<vector<int>> sub3(half, vector<int>(half));
    vector<vector<int>> sub4(half, vector<int>(half));

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            sub1[i][j] = arr[i][j];
            sub2[i][j] = arr[i][j + half];
            sub3[i][j] = arr[i + half][j];
            sub4[i][j] = arr[i + half][j + half];
        }
    }

    ls3_sort(sub1, half);
    ls3_sort(sub2, half);
    ls3_sort(sub3, half);
    ls3_sort(sub4, half);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            arr[i][j] = sub1[i][j];
            arr[i][j + half] = sub2[i][j];
            arr[i + half][j] = sub3[i][j];
            arr[i + half][j + half] = sub4[i][j];
        }
    }

    ls3_merge(arr, n);
}

void printArray(const vector<vector<int>>& arr) {
    for (const auto& row : arr) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    vector<vector<int>> arr = {
        {10,  20,  30,  40},
        {90,  80,  70,  60},
        {50,  55,  65,  75},
        {85,  95,  99,  100},
        {85,  95,  99,  100}
    };

    cout << arr.size(); //rows
    cout << "\n";
    cout << arr[0].size(); //columns
    cout << "\n";

    cout << "Original array:\n";
    printArray(arr);

    ls3_sort(arr, n);

    cout << "\nSorted array:\n";
    printArray(arr);

    return 0;
}

