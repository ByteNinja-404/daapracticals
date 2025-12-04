#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Global counter for comparisons
long long comparison_count = 0;

// --- HEAP SORT ---
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child is larger than root
    if (left < n) {
        comparison_count++;
        if (arr[left] > arr[largest])
            largest = left;
    }

    // Check if right child is larger than largest so far
    if (right < n) {
        comparison_count++;
        if (arr[right] > arr[largest])
            largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// --- UTILITIES ---
void generateRandomArray(vector<int>& arr, int n) {
    arr.clear();
    for (int i = 0; i < n; i++) arr.push_back(rand() % 10000);
}

void runAnalysis() {
    cout << "Size,Heap_Comparisons\n";
    // Loop from 30 to 1000 as per syllabus
    for (int n = 30; n <= 1000; n += 10) { 
        long long totalComparisons = 0;
        int trials = 10; // Average over 10 instances

        for (int t = 0; t < trials; t++) {
            vector<int> arr;
            generateRandomArray(arr, n);

            comparison_count = 0; // Reset counter
            heapSort(arr);
            totalComparisons += comparison_count;
        }
        cout << n << "," << (totalComparisons / trials) << endl;
    }
}

int main() {
    srand(time(0));
    int choice;
    cout << "--- Practical 3: Heap Sort ---\n";
    cout << "1. Run specific test (single input)\n2. Run Analysis (Data for Graph Plotting)\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        vector<int> data = {12, 11, 13, 5, 6, 7};
        cout << "Original: "; for(int x : data) cout << x << " "; cout << endl;
        
        comparison_count = 0;
        heapSort(data);
        
        cout << "Sorted:   "; for(int x : data) cout << x << " "; cout << endl;
        cout << "Comparisons: " << comparison_count << endl;
    } else {
        runAnalysis();
    }
    return 0;
}