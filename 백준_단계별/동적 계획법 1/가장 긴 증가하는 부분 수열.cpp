#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        answer = max(answer, dp[i]);
    }
    cout << answer << "\n";
    return 0;
}