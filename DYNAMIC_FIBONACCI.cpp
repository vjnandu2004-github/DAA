#include <iostream>
#include <vector>
using namespace std;

void dynamic_fib(vector<int>& fibSeries, int n) {
    if (n > 0) fibSeries[0] = 0;
    if (n > 1) fibSeries[1] = 1;
    for (int i = 2; i < n; i++) {
        fibSeries[i] = fibSeries[i - 1] + fibSeries[i - 2];
    }
}

int main() {
    int n;
    cout << "Enter the number of Fibonacci series required: ";
    cin >> n;
    vector<int> fibSeries(n);
    dynamic_fib(fibSeries, n);

    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << fibSeries[i] << " ";
    }
    cout << "\n";
    return 0;
}
