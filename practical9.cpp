#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 5 // Number of vertices in the graph

// Function to find the vertex with minimum key value
int minKey(const vector<int>& key, const vector<bool>& mstSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to construct and print MST using Prim's algorithm
void primMST(int graph[V][V]) {
    vector<int> parent(V);      // Array to store constructed MST
    vector<int> key(V);         // Key values used to pick minimum weight edge
    vector<bool> mstSet(V);     // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include first 1st vertex in MST.
    key[0] = 0;     
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices
        for (int v = 0; v < V; v++)
            // graph[u][v] is non zero only for adjacent vertices
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    // Print the constructed MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[parent[i]][i] << " \n";
}

int main() {
    cout << "--- Practical 9: Prim's MST ---\n";
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}