#include <iostream>

using namespace std;

// Helper to allocate 2D array
int** createMatrix(int n) {
    int** mat = new int*[n];
    for(int i = 0; i < n; i++)
        mat[i] = new int[n];
    return mat;
}

void freeMatrix(int** mat, int n) {
    for(int i = 0; i < n; i++)
        delete[] mat[i];
    delete[] mat;
}

int** add(int** A, int** B, int n) {
    int** C = createMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

int** subtract(int** A, int** B, int n) {
    int** C = createMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

int** strassen(int** A, int** B, int n) {
    if (n == 1) {
        int** C = createMatrix(1);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int k = n / 2;
    int** a11 = createMatrix(k); int** a12 = createMatrix(k);
    int** a21 = createMatrix(k); int** a22 = createMatrix(k);
    int** b11 = createMatrix(k); int** b12 = createMatrix(k);
    int** b21 = createMatrix(k); int** b22 = createMatrix(k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a11[i][j] = A[i][j];     a12[i][j] = A[i][j + k];
            a21[i][j] = A[i + k][j]; a22[i][j] = A[i + k][j + k];
            b11[i][j] = B[i][j];     b12[i][j] = B[i][j + k];
            b21[i][j] = B[i + k][j]; b22[i][j] = B[i + k][j + k];
        }
    }

    int** p1 = strassen(add(a11, a22, k), add(b11, b22, k), k);
    int** p2 = strassen(add(a21, a22, k), b11, k);
    int** p3 = strassen(a11, subtract(b12, b22, k), k);
    int** p4 = strassen(a22, subtract(b21, b11, k), k);
    int** p5 = strassen(add(a11, a12, k), b22, k);
    int** p6 = strassen(subtract(a21, a11, k), add(b11, b12, k), k);
    int** p7 = strassen(subtract(a12, a22, k), add(b21, b22, k), k);

    int** c11 = add(subtract(add(p1, p4, k), p5, k), p7, k);
    int** c12 = add(p3, p5, k);
    int** c21 = add(p2, p4, k);
    int** c22 = add(subtract(add(p1, p3, k), p2, k), p6, k);

    int** C = createMatrix(n);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = c11[i][j]; C[i][j + k] = c12[i][j];
            C[i + k][j] = c21[i][j]; C[i + k][j + k] = c22[i][j];
        }
    }

    // Free intermediate memory
    freeMatrix(a11, k); freeMatrix(a12, k); freeMatrix(a21, k); freeMatrix(a22, k);
    freeMatrix(b11, k); freeMatrix(b12, k); freeMatrix(b21, k); freeMatrix(b22, k);
    freeMatrix(p1, k); freeMatrix(p2, k); freeMatrix(p3, k); freeMatrix(p4, k);
    freeMatrix(p5, k); freeMatrix(p6, k); freeMatrix(p7, k);
    freeMatrix(c11, k); freeMatrix(c12, k); freeMatrix(c21, k); freeMatrix(c22, k);

    return C;
}

int main() {
    int n = 4; // Size must be power of 2
    int** A = createMatrix(n);
    int** B = createMatrix(n);
    
    // Hardcoded input for demonstration
    cout << "Initializing 4x4 Matrices...\n";
    int val = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            A[i][j] = val++; 
            B[i][j] = (i==j) ? 1 : 0; // Identity Matrix
        }
    }

    cout << "Matrix A:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cout << A[i][j] << "\t";
        cout << endl;
    }

    cout << "Matrix B:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cout << B[i][j] << "\t";
        cout << endl;
    }

    int** C = strassen(A, B, n);
    
    cout << "Result Matrix C (Strassen):\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cout << C[i][j] << "\t";
        cout << endl;
    }

    freeMatrix(A, n); freeMatrix(B, n); freeMatrix(C, n);
    return 0;
}