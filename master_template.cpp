#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

// ==========================================
// UTILITIES (For Sorting Practicals 1, 2, 3)
// ==========================================
long long comparison_count = 0;

void generateRandomArray(vector<int>& arr, int n) {
    arr.clear();
    for (int i = 0; i < n; i++) arr.push_back(rand() % 10000);
}

// Function to run analysis for sorting algorithms (Graph Plotting Data)
// pass function pointer to sort algorithm
void runSortAnalysis(void (*sortFunc)(vector<int>&), string name) {
    cout << "\n--- Analysis for " << name << " ---\n";
    cout << "Size, Comparisons\n";
    for (int n = 30; n <= 1000; n += 50) {
        long long total = 0;
        int trials = 5;
        for (int t = 0; t < trials; t++) {
            vector<int> arr;
            generateRandomArray(arr, n);
            comparison_count = 0;
            sortFunc(arr);
            total += comparison_count;
        }
        cout << n << ", " << (total / trials) << endl;
    }
}

// ==========================================
// PRACTICAL 1: INSERTION SORT
// ==========================================
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparison_count++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

// ==========================================
// PRACTICAL 2: MERGE SORT
// ==========================================
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparison_count++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortRec(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRec(arr, left, mid);
        mergeSortRec(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Wrapper for analysis
void mergeSortWrapper(vector<int>& arr) {
    mergeSortRec(arr, 0, arr.size() - 1);
}

// ==========================================
// PRACTICAL 3: HEAP SORT
// ==========================================
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comparison_count++;
        if (arr[left] > arr[largest]) largest = left;
    }
    if (right < n) {
        comparison_count++;
        if (arr[right] > arr[largest]) largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// ==========================================
// PRACTICAL 4: STRASSEN'S MATRIX MULTIPLICATION
// ==========================================
typedef vector<vector<int>> matrix;

matrix add(const matrix& A, const matrix& B) {
    int n = A.size();
    matrix C(n, vector<int>(n));
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) C[i][j] = A[i][j] + B[i][j];
    return C;
}

matrix sub(const matrix& A, const matrix& B) {
    int n = A.size();
    matrix C(n, vector<int>(n));
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) C[i][j] = A[i][j] - B[i][j];
    return C;
}

matrix strassen(const matrix& A, const matrix& B) {
    int n = A.size();
    if (n == 1) return {{A[0][0] * B[0][0]}};

    int k = n / 2;
    matrix a11(k, vector<int>(k)), a12(k, vector<int>(k)), a21(k, vector<int>(k)), a22(k, vector<int>(k));
    matrix b11(k, vector<int>(k)), b12(k, vector<int>(k)), b21(k, vector<int>(k)), b22(k, vector<int>(k));

    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            a11[i][j] = A[i][j]; a12[i][j] = A[i][j+k]; a21[i][j] = A[i+k][j]; a22[i][j] = A[i+k][j+k];
            b11[i][j] = B[i][j]; b12[i][j] = B[i][j+k]; b21[i][j] = B[i+k][j]; b22[i][j] = B[i+k][j+k];
        }
    }

    matrix p1 = strassen(add(a11, a22), add(b11, b22));
    matrix p2 = strassen(add(a21, a22), b11);
    matrix p3 = strassen(a11, sub(b12, b22));
    matrix p4 = strassen(a22, sub(b21, b11));
    matrix p5 = strassen(add(a11, a12), b22);
    matrix p6 = strassen(sub(a21, a11), add(b11, b12));
    matrix p7 = strassen(sub(a12, a22), add(b21, b22));

    matrix c11 = add(sub(add(p1, p4), p5), p7);
    matrix c12 = add(p3, p5);
    matrix c21 = add(p2, p4);
    matrix c22 = add(sub(add(p1, p3), p2), p6);

    matrix C(n, vector<int>(n));
    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            C[i][j] = c11[i][j]; C[i][j+k] = c12[i][j];
            C[i+k][j] = c21[i][j]; C[i+k][j+k] = c22[i][j];
        }
    }
    return C;
}

// ==========================================
// PRACTICAL 5: RADIX SORT
// ==========================================
void countSortRadix(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    int m = arr[0];
    for(int x : arr) m = max(m, x);
    for (int exp = 1; m / exp > 0; exp *= 10) countSortRadix(arr, exp);
}

// ==========================================
// PRACTICAL 6: BUCKET SORT
// ==========================================
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> b(n);
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        if (bi >= n) bi = n - 1;
        b[bi].push_back(arr[i]);
    }
    for (int i = 0; i < n; i++) sort(b[i].begin(), b[i].end());
    int index = 0;
    for (int i = 0; i < n; i++) for (float x : b[i]) arr[index++] = x;
}

// ==========================================
// PRACTICAL 7 & 8: BFS & DFS
// ==========================================
class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) : V(V), adj(V) {}
    void addEdge(int v, int w) { adj[v].push_back(w); } // Directed

    void BFS(int s) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[s] = true;
        q.push(s);
        cout << "BFS: ";
        while(!q.empty()) {
            s = q.front(); q.pop();
            cout << s << " ";
            for(auto i : adj[s]) if(!visited[i]) { visited[i] = true; q.push(i); }
        }
        cout << endl;
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for(int i : adj[v]) if(!visited[i]) DFSUtil(i, visited);
    }
    void DFS(int s) {
        vector<bool> visited(V, false);
        cout << "DFS: ";
        DFSUtil(s, visited);
        cout << endl;
    }
};

// ==========================================
// PRACTICAL 9 & 10: PRIM'S & DIJKSTRA
// ==========================================
#define V_CONST 5
int minKey(const vector<int>& key, const vector<bool>& set) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V_CONST; v++)
        if (!set[v] && key[v] < min) min = key[v], min_index = v;
    return min_index;
}

void primMST(int graph[V_CONST][V_CONST]) {
    vector<int> parent(V_CONST), key(V_CONST, INT_MAX);
    vector<bool> mstSet(V_CONST, false);
    key[0] = 0; parent[0] = -1;

    for (int count = 0; count < V_CONST - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V_CONST; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    cout << "Prim's MST:\nEdge \tWeight\n";
    for (int i = 1; i < V_CONST; i++) cout << parent[i] << "-" << i << " \t" << graph[parent[i]][i] << "\n";
}

void dijkstra(int graph[V_CONST][V_CONST], int src) {
    vector<int> dist(V_CONST, INT_MAX);
    vector<bool> sptSet(V_CONST, false);
    dist[src] = 0;

    for (int count = 0; count < V_CONST - 1; count++) {
        int u = minKey(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V_CONST; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    cout << "Dijkstra Paths:\nVertex \tDistance\n";
    for (int i = 0; i < V_CONST; i++) cout << i << " \t" << dist[i] << endl;
}

// ==========================================
// PRACTICAL 11: WEIGHTED INTERVAL
// ==========================================
struct Job { int id, start, finish, profit; };
bool jobComp(Job s1, Job s2) { return (s1.finish < s2.finish); }

int latestNonConflict(Job arr[], int i) {
    for (int j = i - 1; j >= 0; j--)
        if (arr[j].finish <= arr[i].start) return j;
    return -1;
}

void weightedInterval(Job arr[], int n) {
    sort(arr, arr + n, jobComp);
    vector<int> table(n);
    table[0] = arr[0].profit;
    for (int i = 1; i < n; i++) {
        int incl = arr[i].profit;
        int l = latestNonConflict(arr, i);
        if (l != -1) incl += table[l];
        table[i] = max(incl, table[i - 1]);
    }
    cout << "Max Profit (Weighted Interval): " << table[n - 1] << endl;
}

// ==========================================
// PRACTICAL 12: 0/1 KNAPSACK
// ==========================================
void knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<vector<int>> K(n + 1, vector<int>(W + 1));
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) K[i][w] = 0;
            else if (wt[i - 1] <= w) K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else K[i][w] = K[i - 1][w];
        }
    }
    cout << "Knapsack Max Value: " << K[n][W] << endl;
}

// ==========================================
// MAIN DRIVER
// ==========================================
int main() {
    srand(time(0));
    int choice;
    cout << "ENTER PRACTICAL NUMBER (1-12): ";
    cin >> choice;

    if(choice == 1) {
        vector<int> arr = {12, 11, 13, 5, 6};
        comparison_count = 0; insertionSort(arr);
        cout << "Sorted: "; for(int x:arr) cout << x << " "; cout << "\nComparisons: " << comparison_count << endl;
        runSortAnalysis(insertionSort, "Insertion Sort");
    }
    else if(choice == 2) {
        vector<int> arr = {12, 11, 13, 5, 6};
        comparison_count = 0; mergeSortWrapper(arr);
        cout << "Sorted: "; for(int x:arr) cout << x << " "; cout << "\nComparisons: " << comparison_count << endl;
        runSortAnalysis(mergeSortWrapper, "Merge Sort");
    }
    else if(choice == 3) {
        vector<int> arr = {12, 11, 13, 5, 6};
        comparison_count = 0; heapSort(arr);
        cout << "Sorted: "; for(int x:arr) cout << x << " "; cout << "\nComparisons: " << comparison_count << endl;
        runSortAnalysis(heapSort, "Heap Sort");
    }
    else if(choice == 4) {
        matrix A = {{1, 2}, {3, 4}}, B = {{5, 6}, {7, 8}};
        matrix C = strassen(A, B);
        cout << "Strassen Result:\n";
        for(auto r:C) { for(int c:r) cout << c << " "; cout << endl; }
    }
    else if(choice == 5) {
        vector<int> arr = {170, 45, 75, 90, 802, 24};
        radixSort(arr);
        cout << "Radix Sorted: "; for(int x:arr) cout << x << " "; cout << endl;
    }
    else if(choice == 6) {
        vector<float> arr = {0.897, 0.565, 0.656, 0.1234};
        bucketSort(arr);
        cout << "Bucket Sorted: "; for(float x:arr) cout << x << " "; cout << endl;
    }
    else if(choice == 7 || choice == 8) {
        Graph g(4);
        g.addEdge(0, 1); g.addEdge(0, 2); g.addEdge(1, 2);
        g.addEdge(2, 0); g.addEdge(2, 3); g.addEdge(3, 3);
        if(choice == 7) g.BFS(2);
        else g.DFS(2);
    }
    else if(choice == 9 || choice == 10) {
        int graph[V_CONST][V_CONST] = {{0, 2, 0, 6, 0}, {2, 0, 3, 8, 5}, {0, 3, 0, 0, 7}, {6, 8, 0, 0, 9}, {0, 5, 7, 9, 0}};
        if(choice == 9) primMST(graph);
        else dijkstra(graph, 0);
    }
    else if(choice == 11) {
        Job arr[] = {{1, 3, 5, 20}, {2, 1, 2, 50}, {3, 6, 19, 100}, {4, 2, 100, 200}};
        weightedInterval(arr, 4);
    }
    else if(choice == 12) {
        vector<int> val = {60, 100, 120}, wt = {10, 20, 30};
        knapsack(50, wt, val, 3);
    }
    return 0;
}
