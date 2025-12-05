#include <iostream>

using namespace std;

int myMax(int a, int b) { return (a > b) ? a : b; }

void knapsack(int W, int* wt, int* val, int n) {
    // Dynamically allocate 2D array [n+1][W+1]
    int** K = new int*[n + 1];
    for(int i = 0; i <= n; i++)
        K[i] = new int[W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = myMax(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    cout << "Knapsack Max Value: " << K[n][W] << endl;

    // Cleanup memory
    for(int i=0; i<=n; i++) delete[] K[i];
    delete[] K;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    int* val = new int[n];
    int* wt = new int[n];

    cout << "Enter values of " << n << " items: ";
    for(int i=0; i<n; i++) cin >> val[i];

    cout << "Enter weights of " << n << " items: ";
    for(int i=0; i<n; i++) cin >> wt[i];

    cout << "Enter Knapsack Capacity: ";
    cin >> W;

    knapsack(W, wt, val, n);

    delete[] val;
    delete[] wt;
    return 0;
}