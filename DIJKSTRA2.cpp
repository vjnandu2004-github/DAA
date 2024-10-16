#include <iostream>
#include <vector>
using namespace std;
#include <limits.h>

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(vector<int>& dist, vector<bool>& sptSet, int V)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(vector<int>& dist, int V)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(vector<vector<int>>& graph, int src, int V)
{
    // Initialize all distances as INFINITE and sptSet[] as false
    vector<int> dist(V,INT_MAX); // The output array. dist[i] will hold the shortest
                         // distance from src to i

    vector<bool> sptSet(V,false); // sptSet[i] will be true if vertex i is included
                            // in shortest path tree


    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed.
        int u = minDistance(dist, sptSet, V);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)

            // Update dist[v] only if not in sptSet, there is an edge from u to v,
            // and total weight of path from src to v through u is smaller than
            // current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist, V);
}

// Driver code
int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter the edges (start end weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // Assuming an undirected graph
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    // Function call
    dijkstra(graph, src, V);

    return 0;
}
