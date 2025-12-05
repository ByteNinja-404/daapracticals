#include <iostream>

using namespace std;

class Graph {
    int V;
    int** adj;
public:
    Graph(int V) {
        this->V = V;
        adj = new int*[V];
        for(int i=0; i<V; i++) {
            adj[i] = new int[V];
            for(int j=0; j<V; j++) adj[i][j] = 0;
        }
    }
    
    void addEdge(int v, int w) {
        adj[v][w] = 1;
    }

    void DFSUtil(int v, bool* visited) {
        visited[v] = true;
        cout << v << " ";

        for(int i = 0; i < V; i++) {
            if(adj[v][i] == 1 && !visited[i])
                DFSUtil(i, visited);
        }
    }

    void DFS(int s) {
        bool* visited = new bool[V];
        for(int i=0; i<V; i++) visited[i] = false;
        
        cout << "DFS Traversal starting from " << s << ": ";
        DFSUtil(s, visited);
        cout << endl;
        delete[] visited;
    }
    
    ~Graph() {
        for(int i=0; i<V; i++) delete[] adj[i];
        delete[] adj;
    }
};

int main() {
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1); 
    g.addEdge(0, 2);
    g.addEdge(1, 2); 
    g.addEdge(2, 0);
    g.addEdge(2, 3); 
    g.addEdge(3, 3);
    
    cout << "Graph structure created (0->1, 0->2, 1->2, 2->0, 2->3, 3->3)\n";
    g.DFS(2);
    return 0;
}