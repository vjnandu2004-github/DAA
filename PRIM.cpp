#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the vertex with minimum key value
int minKey(const vector<int>& key, const vector<bool>& mstSet, int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// Function to print the Minimum Spanning Tree (MST)
void printMST(const vector<int>& parent, const vector<vector<int>>& graph, int V) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
}

// Function to construct the MST using Prim's algorithm
void primMST(const vector<vector<int>>& graph, int V) {
    vector<int> parent(V);      // Array to store constructed MST
    vector<int> key(V, INT_MAX); // Key values to pick minimum weight edge
    vector<bool> mstSet(V, false); // To track vertices included in MST

    key[0] = 0;   // Start from the first vertex
    parent[0] = -1; // First node is always the root of the MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex not yet included in MST
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        // Update the key and parent index for adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, V);
}

// Driver's code
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    
    cout << "Enter the number of edges: ";
    cin >> E;

    // Initialize adjacency matrix with 0
    vector<vector<int>> graph(V, vector<int>(V, 0));

    // Input edges and weights
    cout << "Enter edge (u, v) and weight (w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;  // Add the weight for edge u->v
        graph[v][u] = w;  // Since the graph is undirected, add v->u as well
    }

    // Print the solution
    primMST(graph, V);

    return 0;
}
