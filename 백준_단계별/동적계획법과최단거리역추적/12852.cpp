#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int x;
    cin >> x;

    vector<int> dp(x + 1, 0);       // dp[i] = i를 1로 만들기 위한 최소 연산 횟수
    vector<int> before(x + 1, 0);   // 경로 추적용

    for (int i = 2; i <= x; ++i) 
    {
        dp[i] = dp[i - 1] + 1;
        before[i] = i - 1;

        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            before[i] = i / 2;
        }

        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            before[i] = i / 3;
        }
    }

    // 최소 연산 횟수 출력
    cout << dp[x] << '\n';

    // 경로 출력 (역추적)
    while (x != 0) {
        cout << x << " ";
        x = before[x];
    }

    return 0;
}
