
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[10][10];

    cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];

            if (i != j && cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }

    int visited[10] = {0};
    visited[0] = 1;

    int edges = 0, totalCost = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    while (edges < n - 1) {
        int minCost = INT_MAX;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < minCost) {
                        minCost = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            cout << "Graph is disconnected!\n";
            return 0;
        }

        cout << u << " - " << v
             << " : " << minCost << endl;

        visited[v] = 1;
        totalCost += minCost;
        edges++;
    }

    cout << "Total cost of MST = " << totalCost << endl;

    return 0;
}
