#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n; // Number of cities
vector<vector<int>> dist;
vector<bool> visited;
int min_cost = INT_MAX;

void tsp(int curr_city, int count, int cost, int start_city) {
    // If all cities are visited, return to start and update min_cost
    if (count == n && dist[curr_city][start_city] > 0) {
        min_cost = min(min_cost, cost + dist[curr_city][start_city]);
        return;
    }

    // Try all cities as the next move
    for (int next_city = 0; next_city < n; next_city++) {
        if (!visited[next_city] && dist[curr_city][next_city] > 0) {
            visited[next_city] = true;
            tsp(next_city, count + 1, cost + dist[curr_city][next_city], start_city);
            visited[next_city] = false; // Backtrack
        }
    }
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    dist.resize(n, vector<int>(n));
    visited.resize(n, false);

    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    visited[0] = true; // Start from city 0
    tsp(0, 1, 0, 0);

    cout << "The minimum traveling cost is: " << min_cost << endl;

    return 0;
}
