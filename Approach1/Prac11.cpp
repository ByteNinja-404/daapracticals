#include <iostream>

using namespace std;

struct Job {
    int id, start, finish, profit;
};

// Custom Bubble Sort to sort jobs by finish time
void sortJobs(Job* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].finish > arr[j + 1].finish) {
                Job temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int myMax(int a, int b) { return (a > b) ? a : b; }

int latestNonConflict(Job* arr, int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (arr[j].finish <= arr[i].start)
            return j;
    }
    return -1;
}

void weightedInterval(Job* arr, int n) {
    sortJobs(arr, n);

    int* table = new int[n];
    table[0] = arr[0].profit;

    for (int i = 1; i < n; i++) {
        int incl = arr[i].profit;
        int l = latestNonConflict(arr, i);
        if (l != -1) incl += table[l];
        table[i] = myMax(incl, table[i - 1]);
    }

    cout << "Max Profit: " << table[n - 1] << endl;
    delete[] table;
}

int main() {
    Job arr[] = {{1, 3, 5, 20}, {2, 1, 2, 50}, {3, 6, 19, 100}, {4, 2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Jobs (Start, Finish, Profit): \n";
    for(int i=0; i<n; i++) 
        cout << "(" << arr[i].start << ", " << arr[i].finish << ", " << arr[i].profit << ")\n";

    weightedInterval(arr, n);
    return 0;
}