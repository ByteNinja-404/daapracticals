#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V; // No. of vertices
    vector<vector<int>> adj; // Adjacency List

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Directed graph
        // adj[w].push_back(v); // Uncomment for Undirected
    }

    void BFS(int s) {
        // Mark all the vertices as not visited
        vector<bool> visited(V, false);

        // Create a queue for BFS
        queue<int> queue;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push(s);

        cout << "BFS Traversal starting from vertex " << s << ": ";

        while(!queue.empty()) {
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop();

            // Get all adjacent vertices of the dequeued vertex s
            // If a adjacent has not been visited, then mark it visited and enqueue it
            for(auto i : adj[s]) {
                if(!visited[i]) {
                    visited[i] = true;
                    queue.push(i);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Practical 7: BFS Traversal ---\n";
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    return 0;
}