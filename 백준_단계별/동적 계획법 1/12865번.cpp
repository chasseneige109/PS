#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm> 

using namespace std;

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> bundle(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> bundle[i].first >> bundle[i].second;
    }


    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; ++i) 
    {
        for (int j = 0; j <= M; ++j) 
        {
            if (j >= bundle[i].first)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - bundle[i].first] + bundle[i].second);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N][M] << "\n";

    return 0;
}