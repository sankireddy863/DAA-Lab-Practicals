#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    const long long INF = 1e15;
    vector<vector<long long>> dist(n, vector<long long>(n));

    cout << "Enter the adjacency matrix (use INF for no edge):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string value;
            cin >> value;

            if (value == "INF" || value == "inf") {
                dist[i][j] = INF;
            } else {
                dist[i][j] = stoll(value);
            }
        }
    }

    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    cout << "\nShortest-distance matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                cout << setw(8) << "INF";
            } else {
                cout << setw(8) << dist[i][j];
            }
        }
        cout << '\n';
    }

    return 0;
}
