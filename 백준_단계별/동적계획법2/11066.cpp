#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> file(N + 1);
        vector<int> prefix(N + 1, 0);
        for (int i = 1; i <= N; ++i)
        {
            cin >> file[i];
            prefix[i] = prefix[i - 1] + file[i];  // 누적합
        }

        // dp[i][j]: i~j 구간 합치는 최소 비용
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

        for (int len = 2; len <= N; ++len)  // 구간 길이
        {
            for (int i = 1; i <= N - len + 1; ++i)
            {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; ++k)
                {
                    dp[i][j] = min(dp[i][j],
                        dp[i][k] + dp[k + 1][j] + prefix[j] - prefix[i - 1]);
                }
            }
        }

        cout << dp[1][N] << '\n';
    }

    return 0;
}
