#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to get the maximum value in arr[]
int getMax(const vector<int>& arr) {
    int mx = arr[0];
    for (int x : arr)
        if (x > mx) mx = x;
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // Output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using Radix Sort
void radixSort(vector<int>& arr) {
    // Find the maximum number to know number of digits
    int m = getMax(arr);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}

int main() {
    cout << "--- Practical 5: Radix Sort ---\n";
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    radixSort(arr);

    cout << "Sorted array:   ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}