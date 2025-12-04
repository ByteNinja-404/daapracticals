#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Global counter for comparisons
long long comparison_count = 0;

// --- INSERTION SORT ---
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Loop to shift elements
        while (j >= 0) {
            comparison_count++; // Count comparison
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

// --- UTILITIES ---
void generateRandomArray(vector<int>& arr, int n) {
    arr.clear();
    for (int i = 0; i < n; i++) arr.push_back(rand() % 10000);
}

void runAnalysis() {
    cout << "Size,Insertion_Comparisons\n";
    // Loop from 30 to 1000 as per syllabus
    for (int n = 30; n <= 1000; n += 10) { 
        long long totalComparisons = 0;
        int trials = 10; // Average over 10 instances

        for (int t = 0; t < trials; t++) {
            vector<int> arr;
            generateRandomArray(arr, n);

            comparison_count = 0; // Reset counter
            insertionSort(arr);
            totalComparisons += comparison_count;
        }
        // Print average comparisons for this size
        cout << n << "," << (totalComparisons / trials) << endl;
    }
}

int main() {
    srand(time(0));
    int choice;
    cout << "--- Practical 1: Insertion Sort ---\n";
    cout << "1. Run specific test (single input)\n2. Run Analysis (Data for Graph Plotting)\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        // Specific Test
        vector<int> data = {12, 11, 13, 5, 6, 7};
        cout << "Original: "; for(int x : data) cout << x << " "; cout << endl;
        
        comparison_count = 0;
        insertionSort(data);
        
        cout << "Sorted:   "; for(int x : data) cout << x << " "; cout << endl;
        cout << "Comparisons: " << comparison_count << endl;
    } else {
        // Benchmark Mode
        runAnalysis();
    }
    return 0;
}