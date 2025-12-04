#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Global counter for comparisons
long long comparison_count = 0;

// --- MERGE SORT ---
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temp arrays
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparison_count++; // Count comparison
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy remaining elements
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// --- UTILITIES ---
void generateRandomArray(vector<int>& arr, int n) {
    arr.clear();
    for (int i = 0; i < n; i++) arr.push_back(rand() % 10000);
}

void runAnalysis() {
    cout << "Size,Merge_Comparisons\n";
    // Loop from 30 to 1000 as per syllabus
    for (int n = 30; n <= 1000; n += 10) { 
        long long totalComparisons = 0;
        int trials = 10; // Average over 10 instances

        for (int t = 0; t < trials; t++) {
            vector<int> arr;
            generateRandomArray(arr, n);

            comparison_count = 0; // Reset counter
            mergeSort(arr, 0, n - 1);
            totalComparisons += comparison_count;
        }
        // Print average comparisons for this size
        cout << n << "," << (totalComparisons / trials) << endl;
    }
}

int main() {
    srand(time(0));
    int choice;
    cout << "--- Practical 2: Merge Sort ---\n";
    cout << "1. Run specific test (single input)\n2. Run Analysis (Data for Graph Plotting)\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        // Specific Test
        vector<int> data = {12, 11, 13, 5, 6, 7};
        cout << "Original: "; for(int x : data) cout << x << " "; cout << endl;
        
        comparison_count = 0;
        mergeSort(data, 0, data.size() - 1);
        
        cout << "Sorted:   "; for(int x : data) cout << x << " "; cout << endl;
        cout << "Comparisons: " << comparison_count << endl;
    } else {
        // Benchmark Mode
        runAnalysis();
    }
    return 0;
}