#include <iostream>
using namespace std;

int fib_count = 0;

int fib(int n) {
    if (n == 1 || n == 2) {
        fib_count++;
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int fib_dp(int n) {
    int dp[41] = { 0 };
    dp[1] = dp[2] = 1;
    int count = 0;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
        count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    fib(n); // Àç±Í
    int dp_count = fib_dp(n); // DP

    cout << fib_count << '\n';
    cout << dp_count << '\n';

    return 0;
}
