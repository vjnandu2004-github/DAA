#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Add Edge  as edges are undirectional
void addEdge(vector<vector<int>> &mat, int i ,int j){
    mat[i][j]=1;
    mat[j][i]=1;

}

void displayMatrix(vector<vector<int>> &mat){
    int V=mat.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;

        
    }
    
}

void BFS(vector<vector<int>> &mat,int startvertex){

    int V=mat.size(); 
    vector<bool> visited(V,false);
    queue<int> q;

    visited[startvertex]=true;
    q.push(startvertex);

    while(!q.empty()){
        int vertex=q.front();
        q.pop();

        cout<<vertex<<" ";

        for (int i = 0; i < V; i++)
        {
            if(mat[vertex][i]==1 && !visited[i]){
                visited[i]=true;
                q.push(i);
            }
        } 

    }
    
}

void DFSu(vector<vector<int>> &mat, int vertex, vector<bool> &visited)
{
    visited[vertex]=true;
    cout<<vertex<<" ";


    for (int i = 0; i < mat.size(); i++)
    {
        if(mat[vertex][i]==1 && !visited[i]){
            DFSu(mat,i,visited);
        }    
    }
    
}

void DFS(vector<vector<int>> &mat, int startvertex){
    int V =mat.size();
    vector<bool> visited(V,false);
    
    DFSu(mat,startvertex,visited);

}

int main(){

    int V, E;
    
    cout << "Enter the number of vertices: ";
    cin >> V;
    
    vector<vector<int>> mat(V, vector<int>(V, 0));
    
    cout << "Enter the number of edges: ";
    cin >> E;
    
    // Input each edge and add it to the graph
    for (int i = 0; i < E; i++) {
        int u, v;
        cout << "Enter edge " << i + 1 << " (u v): ";
        cin >> u >> v;
        addEdge(mat, u, v);
    }
    displayMatrix(mat);

    
    int startvertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startvertex;
    BFS(mat, startvertex);
    cout << endl;

    cout << "Enter the starting vertex for DFS: ";
    cin >> startvertex;
    DFS(mat, startvertex);
    cout << endl;

    return 0;

}