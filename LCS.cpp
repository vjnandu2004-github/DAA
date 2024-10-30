#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

pair<vector<vector<int>>, vector<vector<int>>> LCS(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();
    
    vector<vector<int>> mat(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> b(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                mat[i][j] = mat[i - 1][j - 1] + 1;
                b[i][j] = 1; // Marked for diagonal move
            } else if (mat[i - 1][j] >= mat[i][j - 1]) {
                mat[i][j] = mat[i - 1][j];
                b[i][j] = 2; // Marked for move up
            } else {
                mat[i][j] = mat[i][j - 1];
                b[i][j] = 3; // Marked for move left
            }
        }
    }
    
    return make_pair(b, mat);
}

string constructLCS(const string& X, const vector<vector<int>>& b) {
    int i = X.length();
    int j = b[0].size() - 1; // Size of Y
    string lcs;

    while (i > 0 && j > 0) {
        if (b[i][j] == 1) { // Diagonal
            lcs.push_back(X[i - 1]); // Add current character to LCS
            i--;
            j--;
        } else if (b[i][j] == 2) { // Move up
            i--;
        } else { // Move left
            j--;
        }
    }
    
    reverse(lcs.begin(), lcs.end()); // Reverse the LCS string
    return lcs;
}

int main() {
    string X, Y;
    
    cout << "Enter the first sequence: ";
    cin >> X;
    cout << "Enter the second sequence: ";
    cin >> Y;

    auto [b, mat] = LCS(X, Y);
    string lcs = constructLCS(X, b);

    cout << "Length of LCS: " << mat[X.length()][Y.length()] << endl;
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
