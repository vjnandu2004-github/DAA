#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, vector<pair<int, int>>> minCostPath(const vector<vector<int>>& C) {
    int n = C.size();      // Number of rows
    int m = C[0].size();   // Number of columns

    vector<vector<int>> F(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> direction(n, vector<pair<int, int>>(m, {-1, -1}));

    F[0][0] = C[0][0];

    for (int j = 1; j < m; j++) {
        F[0][j] = F[0][j - 1] + C[0][j];
        direction[0][j] = {0, j - 1}; 
    }

    for (int i = 1; i < n; i++) {
        F[i][0] = F[i - 1][0] + C[i][0];
        direction[i][0] = {i - 1, 0}; 
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (F[i - 1][j] <= F[i][j - 1] && F[i - 1][j] <= F[i - 1][j - 1]) {
                F[i][j] = F[i - 1][j] + C[i][j];
                direction[i][j] = {i - 1, j};
            } else if (F[i][j - 1] <= F[i - 1][j] && F[i][j - 1] <= F[i - 1][j - 1]) {
                F[i][j] = F[i][j - 1] + C[i][j];
                direction[i][j] = {i, j - 1}; 
            } else {
                F[i][j] = F[i - 1][j - 1] + C[i][j];
                direction[i][j] = {i - 1, j - 1}; 
            }
        }
    }

    vector<pair<int, int>> path;
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
        path.push_back({i + 1, j + 1}); 
        auto prev = direction[i][j];
        i = prev.first;
        j = prev.second;
    }

    reverse(path.begin(), path.end()); 
    return {F[n - 1][m - 1], path}; 
}

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> C(n, vector<int>(m));
    cout << "Enter the cost matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> C[i][j];
        }
    }

    auto result = minCostPath(C);
    int minCost = result.first;
    vector<pair<int, int>> path = result.second;

    cout << "Minimum cost to reach cell (" << n - 1 << ", " << m - 1 << "): " << minCost << endl;
    cout << "Path of optimal decisions (1-based indices): ";
    for (const auto& p : path) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
