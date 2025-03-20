#include <algorithm>

#include "bubble_sort/bubble_sort.h"
#include "odd-even_transposition_sort/odd_even_transposition_sort.h"
#include "odd-even_mergesort/odd_even_mergesort.h"
#include "bitonic_sor/bitonic_sort.h"

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


int main() {
    cout << "Which sorting network algorithm do you want to test?\n"
            "1. Bubble bitonic_sort\n"
            "2. Odd-even transposition bitonic_sort\n"
            "3. Odd-even mergesort\n"
            "4. Bitonic sort\n\n"
            "Insert your choice: ";

    int choice = 0;

    cin >> choice;

    vector<int> array = {};
    array = create_vector();

    switch (choice) {
        case 1:
            cout << "Before sorting it:\n";
            print_vector(array);
            Bubble_Sort::bubble_Sort(array);
            cout << "\nAfter sorting it:\n";
            print_vector(array);
            break;
        case 2:
            cout << "Before sorting it:\n";
            print_vector(array);
            Odd_Even_Transposition_Sort::odd_even_transposition_sort(array);
            cout << "\nAfter sorting it:\n";
            print_vector(array);
            break;
        case 3:
            Odd_Even_Mergesort oddEvenMergesort;

            cout << "Before sorting it:\n";
            print_vector(array);
            oddEvenMergesort.odd_even_mergesort(array);
            cout << "\nAfter sorting it:\n";
            print_vector(array);
            break;
        case 4:
            Bitonic_Sort bitonicSort;

            cout << "Before sorting it:\n";
            print_vector(array);
            bitonicSort.bitonic_sort(array);
            cout << "\nAfter sorting it:\n";
            print_vector(array);
            break;
        default:
            break;
    }

    return 0;
}