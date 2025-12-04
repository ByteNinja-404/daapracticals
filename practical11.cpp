#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A job has start time, finish time and profit
struct Job {
    int id;
    int start;
    int finish;
    int profit;
};

// Comparator function for sorting jobs according to finish time
bool jobComparator(Job s1, Job s2) {
    return (s1.finish < s2.finish);
}

// Find the latest job (in sorted array) that doesn't conflict with the job[i]
// Returns -1 if no such job exists
int latestNonConflict(Job arr[], int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (arr[j].finish <= arr[i].start)
            return j;
    }
    return -1;
}

// The main function that returns the maximum profit from given array of jobs
void weightedIntervalScheduling(Job arr[], int n) {
    // Sort jobs according to finish time
    sort(arr, arr + n, jobComparator);

    // Create an array to store solutions of subproblems. table[i]
    // stores the profit for jobs till arr[i] (including arr[i])
    vector<int> table(n);
    table[0] = arr[0].profit;

    // Fill entries in table[] using recursive property
    for (int i = 1; i < n; i++) {
        // Find profit including the current job
        int inclProf = arr[i].profit;
        int l = latestNonConflict(arr, i);
        if (l != -1)
            inclProf += table[l];

        // Store maximum of including and excluding
        table[i] = max(inclProf, table[i - 1]);
    }

    cout << "Max Profit: " << table[n - 1] << endl;
}

int main() {
    cout << "--- Practical 11: Weighted Interval Scheduling ---\n";
    Job arr[] = {
        {1, 3, 5, 20},
        {2, 1, 2, 50},
        {3, 6, 19, 100},
        {4, 2, 100, 200}
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Jobs (Start, Finish, Profit): \n";
    for(int i=0; i<n; i++) 
        cout << "(" << arr[i].start << ", " << arr[i].finish << ", " << arr[i].profit << ")\n";

    weightedIntervalScheduling(arr, n);

    return 0;
}