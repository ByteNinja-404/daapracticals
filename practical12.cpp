#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Returns the maximum value that can be put in a knapsack of capacity W
void knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    // K[i][w] will store maximum value with i items and w capacity
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    // Build table K[][] in bottom up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    cout << "Maximum Value that can be carried: " << K[n][W] << endl;
}

int main() {
    cout << "--- Practical 12: 0/1 Knapsack Problem ---\n";
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();

    cout << "Values: "; for(int v : val) cout << v << " "; cout << endl;
    cout << "Weights: "; for(int w : wt) cout << w << " "; cout << endl;
    cout << "Capacity: " << W << endl;

    knapsack(W, wt, val, n);

    return 0;
}