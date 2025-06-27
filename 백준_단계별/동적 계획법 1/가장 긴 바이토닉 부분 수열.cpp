#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int left_dp[1001];
int right_dp[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> arr[i];

    for (int i = 1; i <= N; ++i)
    {
        left_dp[i] = 1;
        right_dp[i] = 1;
    }

    // 왼쪽: 증가 수열
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            if (arr[j] < arr[i])
                left_dp[i] = max(left_dp[i], left_dp[j] + 1);
        }
    }

    // 오른쪽: 감소 수열 (뒤에서부터)
    for (int i = N; i >= 1; --i)
    {
        for (int j = N; j > i; --j)
        {
            if (arr[j] < arr[i])
                right_dp[i] = max(right_dp[i], right_dp[j] + 1);
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        answer = max(answer, left_dp[i] + right_dp[i] - 1);
    }

    cout << answer << "\n";

    return 0;
}
