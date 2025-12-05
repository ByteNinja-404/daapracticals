#include <iostream>
using namespace std;

// Custom Queue implementation
struct Queue {
    int* arr;
    int front, rear, capacity;

    Queue(int c) {
        capacity = c;
        arr = new int[c];
        front = 0; rear = 0;
    }

    void push(int x) { arr[rear++] = x; }
    int pop() { return arr[front++]; }
    bool empty() { return front == rear; }

    ~Queue() { delete[] arr; }
};

class Graph {
    int V; // Number of vertices
    int** adj; // Adjacency list
public:
    Graph(int V) {
        this->V = V;
        adj = new int*[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new int[V];
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
        }
    }

    void addEdge(int v, int w) {
        adj[v][w] = 1; // Directed Edge
    }
    void BFS(int s) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        Queue q(V);
        visited[s] = true;
        q.push(s);

        cout << "BFS Traversal starting from node " << s << ": ";
        while (!q.empty()) {
            s = q.pop();
            cout << s << " ";

            for (int i = 0; i < V; i++) {
                if (adj[s][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
        delete[] visited;
    }
    ~Graph() {
        for (int i = 0; i < V; i++)
            delete[] adj[i];
        delete[] adj;
    }
};

int main() {
    // Hardcode graph for demonstration
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Graph structure created (0->1, 0->2, 1->2, 2->0, 2->3, 3->3)" << endl;
    g.BFS(2);

    return 0;
}