#include <iostream>
#include <vector>

using namespace std;

// Function to add two matrices
vector<vector<int>> add(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Function to subtract two matrices
vector<vector<int>> subtract(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen's Algorithm
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;
    vector<int> inner(newSize);
    vector<vector<int>> 
        a11(newSize, inner), a12(newSize, inner), a21(newSize, inner), a22(newSize, inner),
        b11(newSize, inner), b12(newSize, inner), b21(newSize, inner), b22(newSize, inner);

    // Dividing the matrices into 4 sub-matrices:
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + newSize];
            a21[i][j] = A[i + newSize][j];
            a22[i][j] = A[i + newSize][j + newSize];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + newSize];
            b21[i][j] = B[i + newSize][j];
            b22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculating p1 to p7:
    vector<vector<int>> p1 = strassen(add(a11, a22), add(b11, b22));
    vector<vector<int>> p2 = strassen(add(a21, a22), b11);
    vector<vector<int>> p3 = strassen(a11, subtract(b12, b22));
    vector<vector<int>> p4 = strassen(a22, subtract(b21, b11));
    vector<vector<int>> p5 = strassen(add(a11, a12), b22);
    vector<vector<int>> p6 = strassen(subtract(a21, a11), add(b11, b12));
    vector<vector<int>> p7 = strassen(subtract(a12, a22), add(b21, b22));

    // Calculating c11, c12, c21, c22:
    vector<vector<int>> c11 = add(subtract(add(p1, p4), p5), p7);
    vector<vector<int>> c12 = add(p3, p5);
    vector<vector<int>> c21 = add(p2, p4);
    vector<vector<int>> c22 = add(subtract(add(p1, p3), p2), p6);

    // Grouping the results obtained in a single matrix:
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = c11[i][j];
            C[i][j + newSize] = c12[i][j];
            C[i + newSize][j] = c21[i][j];
            C[i + newSize][j + newSize] = c22[i][j];
        }
    }
    return C;
}

int main() {
    // Note: n must be a power of 2 for this implementation
    int n = 4; 
    vector<vector<int>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    vector<vector<int>> B = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    cout << "--- Practical 4: Strassen's Algorithm ---\n";
    cout << "Matrix A:" << endl;
    for(auto row : A) { for(int x : row) cout << x << " "; cout << endl; }
    
    cout << "Matrix B:" << endl;
    for(auto row : B) { for(int x : row) cout << x << " "; cout << endl; }

    vector<vector<int>> C = strassen(A, B);

    cout << "\nResult Matrix C (A * B):" << endl;
    for(auto row : C) { for(int x : row) cout << x << " "; cout << endl; }

    return 0;
}