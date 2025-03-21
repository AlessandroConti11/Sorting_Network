#include <iostream>

#include "odd-even_transposition_sort/odd_even_transposition_sort.h"
#include "odd-even_mergesort/odd_even_mergesort.h"
#include "bitonic_sort/bitonic_sort.h"
#include "adapted_bitonic_sort/adapted_bitonic_sort.h"
#include "ls3_sort/ls3_sort.h"
#include "4-way_mergesort/four_way_mergesort.h"
#include "rotatesort/rotatesort.h"

using namespace std;


/**
 * Function that creates a vector reading the user input.
 *
 * @return a vector.
 */
vector<int> create_vector() {
    cout << "We create the array to be reordered.\n"
            "Insert one number at a time (to finish -1): ";

    int number = -1;
    vector<int> array = {};

    while (true) {
        cin >> number;
        if (number == -1) {
            return array;
        }
        array.push_back(number);
    }
}

/**
 * Function that prints a vector.
 *
 * @param vector the vector to print.
 */
void print_vector(vector<int>& vector) {
    ranges::for_each(vector, [](int num) { cout << num << " "; });
}


/**
 * Function that creates a matrix reading the user input.
 *
 * @return a matrix.
 */
vector<vector<int>> create_matrix() {
    int n;
    cout << "Insert the square matrix size: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Insert the matrix elements: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

/**
 * Function that prints a matrix.
 *
 * @param matrix the matrix to print.
 */
void print_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}


int main() {
    cout << "Which sorting network algorithm do you want to test?\n"
            "1. Odd-even transposition sort\n"
            "2. Odd-even mergesort\n"
            "3. Bitonic sort\n"
            "4. Bitonic sort for arbitrary n\n"
            "5. LS3 sort\n"
            "6. 4-way mergesort\n"
            "7. Rotatesort\n\n"
            "Insert your choice: ";

    int choice = 0;

    cin >> choice;

    vector<int> array = {};
    vector<vector<int>> matrix = {};

    switch (choice) {
        case 1:
            array = create_vector();

            cout << "Before sorting it:\n";
            print_vector(array);
            Odd_Even_Transposition_Sort::odd_even_transposition_sort(array);
            cout << "\nAfter sorting it:\n";
            print_vector(array);
            break;
        case 2:
            array = create_vector();

            cout << "Before sorting it:\n";
            print_vector(array);
            Odd_Even_Mergesort::odd_even_mergesort(array);
            cout << "\nAfter sorting it:\n";
            print_vector(array);
            break;
        case 3:
            array = create_vector();

            cout << "Before sorting it:\n";
            print_vector(array);
            Bitonic_Sort::bitonic_sort(array);
            cout << "\nAfter sorting it:\n";
            print_vector(array);
            break;
        case 4:
            array = create_vector();

            cout << "Before sorting it:\n";
            print_vector(array);
            Adapted_Bitonic_Sort::adapted_bitonic_sort(array);
            cout << "\nAfter sorting it:\n";
            print_vector(array);
            break;
        case 5:
            matrix = create_matrix();

            cout << "Before sorting it:\n";
            print_matrix(matrix);
            LS3_Sort::ls3_sort(matrix);
            cout << "\nAfter sorting it:\n";
            print_matrix(matrix);
            break;
        case 6:
            matrix = create_matrix();

            cout << "Before sorting it:\n";
            print_matrix(matrix);
            Four_Way_Mergesort::four_way_mergesort(matrix);
            cout << "\nAfter sorting it:\n";
            print_matrix(matrix);
            break;
        case 7:
            matrix = create_matrix();

            cout << "Before sorting it:\n";
            print_matrix(matrix);
            Rotatesort::rotatesort(matrix);
            cout << "\nAfter sorting it:\n";
            print_matrix(matrix);
            break;
        default:
            break;
    }

    return 0;
}