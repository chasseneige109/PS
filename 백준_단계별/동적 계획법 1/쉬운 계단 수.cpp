#include <iostream>
using namespace std;

long long dp[101][10]; // int → long long (누적합 커짐)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int j = 1; j <= 9; ++j)
        dp[1][j] = 1;  // 1자리 수는 1~9만 가능

    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            if (j - 1 >= 0)
                dp[i][j] += dp[i - 1][j - 1];
            if (j + 1 <= 9)
                dp[i][j] += dp[i - 1][j + 1];

            dp[i][j] %= 1000000000;
        }
    }

    long long ans = 0;
    for (int j = 0; j <= 9; ++j)
        ans = (ans + dp[N][j]) % 1000000000;

    cout << ans << '\n';
    return 0;
}
