#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!mst[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        if (u == -1 || key[u] == INT_MAX) {
            cout << "Graph is not connected.\n";
            return 0;
        }

        mst[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !mst[v] &&
                graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;
    cout << "\nMinimum Spanning Tree:\n";

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i
             << " : " << key[i] << endl;
        total += key[i];
    }

    cout << "Total minimum cost: " << total << endl;

    return 0;
}
