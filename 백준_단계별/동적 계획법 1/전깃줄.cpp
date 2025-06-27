#include <iostream>
#include <algorithm>
using namespace std;

int dp[501];
pair<int, int> line[501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> line[i].first >> line[i].second;
    }

    sort(line, line + N);

    
    int remain = 0;
    for (int i = 0; i < N; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (line[i].second > line[j].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        remain = max(remain, dp[i]);
    }

    cout << N - remain << '\n';
    return 0;
}