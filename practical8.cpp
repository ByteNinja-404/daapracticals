#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V; // No. of vertices
    vector<vector<int>> adj; // Adjacency List

    // Recursive helper function used by DFS
    void DFSUtil(int v, vector<bool>& visited) {
        // Mark the current node as visited and print it
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        for(int i : adj[v])
            if(!visited[i])
                DFSUtil(i, visited);
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Directed Graph
    }

    void DFS(int s) {
        // Mark all the vertices as not visited
        vector<bool> visited(V, false);

        cout << "DFS Traversal starting from vertex " << s << ": ";
        
        // Call the recursive helper function to print DFS traversal
        DFSUtil(s, visited);
        cout << endl;
    }
};

int main() {
    cout << "--- Practical 8: DFS Traversal ---\n";
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.DFS(2);

    return 0;
}