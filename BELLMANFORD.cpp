#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to run Bellman-Ford algorithm to find the shortest paths
// from the source to all other vertices in the graph
void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    // Step 1: Initialize distances from source to all vertices as infinite
    // (except the source itself, which is 0)
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Step 2: Relax all edges (V-1) times
    // This ensures that we account for the shortest paths involving at most (V-1) edges
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;

            // Relax the edge: If the distance to the source u plus the edge weight
            // is less than the current distance to the destination v, update it
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    // If we can relax an edge even after (V-1) iterations, it means we have
    // a negative-weight cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;

        // If we can still relax any edge, it indicates a negative-weight cycle
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }

    // Step 4: Print the result
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    // Input all edges of the graph
    cout << "Enter edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};  // Storing edges in the vector
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    // Run Bellman-Ford algorithm
    bellmanFord(V, E, edges, src);

    return 0;
}
