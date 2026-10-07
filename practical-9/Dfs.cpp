#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;

    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {

            DFS(neighbor, graph, visited);
        }
    }
}

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    vector<vector<int>> graph(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v) using vertices 0 to "
         << vertices - 1 << ":\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u); 
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<bool> visited(vertices, false);

    cout << "DFS Traversal: ";
    DFS(start, graph, visited);

    return 0;
}
