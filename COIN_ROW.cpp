#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinRowProblem(const vector<int>& coins, vector<int>& final) {
    int n = coins.size();
    if (n == 0) return 0;
    if (n == 1) {
        final.push_back(coins[0]);
        return coins[0];
    }

    final.resize(n);
    final[0] = coins[0];
    final[1] = max(coins[0], coins[1]);

    for (int i = 2; i < n; i++) {
        final[i] = max(final[i - 1], coins[i] + final[i - 2]);
    }
    return final[n - 1];
}

int main() {
    vector<int> coins;
    int val;
    cout << "Enter coin values (space-separated): ";
    while (cin >> val) {
        coins.push_back(val);
        if (cin.peek() == '\n') break;
    }

    vector<int> final;
    int maxSum = coinRowProblem(coins, final);
    cout << "Maximum sum without adjacent coins: " << maxSum << endl;
    cout << "Final array: ";
    for (int value : final) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
