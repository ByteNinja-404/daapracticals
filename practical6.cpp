#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to sort arr[] of size n using bucket sort
void bucketSort(vector<float>& arr) {
    int n = arr.size();

    // 1. Create n empty buckets
    vector<vector<float>> b(n);

    // 2. Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        // Boundary check (e.g. if arr[i] is exactly 1.0)
        if(bi >= n) bi = n-1; 
        b[bi].push_back(arr[i]);
    }

    // 3. Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    // 4. Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float x : b[i]) {
            arr[index++] = x;
        }
    }
}

int main() {
    cout << "--- Practical 6: Bucket Sort ---\n";
    // Bucket sort is typically used for floating point numbers in range [0, 1)
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    
    cout << "Original array: ";
    for (float x : arr) cout << x << " ";
    cout << endl;

    bucketSort(arr);

    cout << "Sorted array:   ";
    for (float x : arr) cout << x << " ";
    cout << endl;

    return 0;
}