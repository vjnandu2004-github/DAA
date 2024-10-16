#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Floyd-Warshall function
void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>>& dist, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

// Driver code
int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    // Initialize the distance matrix with INT_MAX (infinity)
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

    cout << "Enter edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;  // Set the weight for the directed edge
    }

    // Set distance to self as 0
    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }

    // Run Floyd-Warshall algorithm
    floydWarshall(dist, V);

    // Print the shortest distance matrix
    cout << "Shortest distance matrix:" << endl;
    printMatrix(dist, V);

    return 0;
}
