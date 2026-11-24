#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    if (n <= 0 || n > 20) {
        cout << "Please enter between 1 and 20 cities.\n";
        return 1;
    }

    const long long INF = numeric_limits<long long>::max() / 4;
    vector<vector<long long>> distance(n, vector<long long>(n));

    cout << "Enter the distance matrix (use INF where there is no route):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string value;
            cin >> value;

            if (value == "INF" || value == "inf") {
                distance[i][j] = INF;
            } else {
                distance[i][j] = stoll(value);
            }
        }
    }

    
    int states = 1 << n;
    vector<vector<long long>> dp(states, vector<long long>(n, INF));
    vector<vector<int>> parent(states, vector<int>(n, -1));

    dp[1][0] = 0;
    for (int mask = 1; mask < states; ++mask) {
        if ((mask & 1) == 0) continue; // The tour must include the start city.

        for (int city = 0; city < n; ++city) {
            if (dp[mask][city] == INF) continue;

            for (int next = 0; next < n; ++next) {
                if (mask & (1 << next)) continue;
                if (distance[city][next] == INF) continue;

                int nextMask = mask | (1 << next);
                long long newCost = dp[mask][city] + distance[city][next];

                if (newCost < dp[nextMask][next]) {
                    dp[nextMask][next] = newCost;
                    parent[nextMask][next] = city;
                }
            }
        }
    }

    int allCities = states - 1;
    long long bestCost = INF;
    int lastCity = -1;

    
    for (int city = 1; city < n; ++city) {
        if (dp[allCities][city] == INF || distance[city][0] == INF) continue;

        long long tourCost = dp[allCities][city] + distance[city][0];
        if (tourCost < bestCost) {
            bestCost = tourCost;
            lastCity = city;
        }
    }

    if (n == 1) {
        cout << "\nShortest tour cost: 0\nTour: 1 -> 1\n";
        return 0;
    }

    if (lastCity == -1) {
        cout << "\nNo complete tour exists.\n";
        return 0;
    }

    // Reconstruct the route.
    vector<int> tour;
    int mask = allCities;
    int city = lastCity;

    while (city != -1) {
        tour.push_back(city);
        int previous = parent[mask][city];
        mask ^= (1 << city);
        city = previous;
    }

    tour.push_back(0);
    
    for (int left = 0, right = static_cast<int>(tour.size()) - 1;
         left < right; ++left, --right) {
        swap(tour[left], tour[right]);
    }
    tour.push_back(0);

    cout << "\nShortest tour cost: " << bestCost << "\nTour: ";
    for (int i = 0; i < static_cast<int>(tour.size()); ++i) {
        cout << tour[i] + 1;
        if (i + 1 < static_cast<int>(tour.size())) cout << " -> ";
    }
    cout << '\n';

    return 0;
}
