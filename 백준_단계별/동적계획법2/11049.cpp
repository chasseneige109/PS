#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    pair<int, int> matrix[500];

    for (int i = 0; i < N; ++i)
    {
        cin >> matrix[i].first >> matrix[i].second;
    }

	vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int len = 2; len <= N; ++len)
    {
        for (int i = 0; i < N - len + 1; ++i)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + matrix[i].first * matrix[k].second * matrix[j].second);
            }
        }
    }

    cout << dp[0][N - 1] << '\n';
    return 0;
}

            
    