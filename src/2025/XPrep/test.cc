#include <iostream>
using namespace std;

template <typename T>
void quicksort_recursive(T values[], unsigned int low, unsigned int high) {
    if (low >= high) return;

    T pivot = values[low + (high - low) / 2]; // ✅ Pivot selection remains the same
    unsigned int i = low, j = high;           // ✅ Keep unsigned int

    while (i <= j) {
        while (values[i] < pivot)
            i++;
        while (j > 0 && values[j] > pivot)
            j--; // ✅ Prevent underflow

        if (i <= j) {
            swap(values[i], values[j]);
            i++;
            if (j > 0) j--; // ✅ Only decrement if j > 0
        }
    }

    if (j > 0) quicksort_recursive(values, low, j); // ✅ Ensure no underflow
    quicksort_recursive(values, i, high);
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    quicksort_recursive(arr, 0, n - 1); // ✅ Call fixed function

    cout << "After sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}