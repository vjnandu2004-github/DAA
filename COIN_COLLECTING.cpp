#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, vector<pair<int, int>>> robotCoinCollection(const vector<vector<int>>& C) {
    int n = C.size();
    int m = C[0].size();
    
    // DP matrix to store maximum coins up to each cell
    vector<vector<int>> F(n, vector<int>(m, 0));
    // Direction matrix to reconstruct the path
    vector<vector<pair<int, int>>> direction(n, vector<pair<int, int>>(m, {-1, -1}));
    
    // Initialize starting point
    F[0][0] = C[0][0];
    
    // Fill first row (only right moves are possible)
    for (int j = 1; j < m; j++) {
        F[0][j] = F[0][j - 1] + C[0][j];
        direction[0][j] = {0, j - 1}; // came from the left
    }
    
    // Fill first column (only down moves are possible)
    for (int i = 1; i < n; i++) {
        F[i][0] = F[i - 1][0] + C[i][0];
        direction[i][0] = {i - 1, 0}; // came from above
    }
    
    // Fill the rest of the matrix
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (F[i - 1][j] > F[i][j - 1]) {
                F[i][j] = F[i - 1][j] + C[i][j];
                direction[i][j] = {i - 1, j}; // came from above
            } else {
                F[i][j] = F[i][j - 1] + C[i][j];
                direction[i][j] = {i, j - 1}; // came from the left
            }
        }
    }
    
    // Reconstruct the path
    vector<pair<int, int>> path;
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
        path.push_back({i + 1, j + 1}); // Store 1-based index
        auto prev = direction[i][j];
        i = prev.first;
        j = prev.second;
    }
    
    reverse(path.begin(), path.end()); // Reverse to get the path from start to end
    return {F[n - 1][m - 1], path}; // Return the maximum coins and the path
}

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    
    vector<vector<int>> C(n, vector<int>(m));
    cout << "Enter the coin matrix (0 or 1 values only): " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> C[i][j];
        }
    }
    
    auto result = robotCoinCollection(C);
    int maxCoins = result.first;
    vector<pair<int, int>> path = result.second;
    
    cout << "Maximum coins collected: " << maxCoins << endl;
    cout << "Path of optimal decisions (1-based indices): ";
    for (const auto& p : path) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
