#include <iostream>
#include <vector>
#include <cstring> // memset
using namespace std;

int card[1001];
int dp[1001][1001]; // dp[l][r]: l~r에서 A가 얻을 수 있는 최대 점수
int sum[1001];

int dfs(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    int total = sum[r] - sum[l - 1];

    // 내가 왼쪽 또는 오른쪽을 골랐을 때 상대가 얻을 수 있는 점수를 빼기
    return dp[l][r] = max(
        card[l] + (total - card[l] - dfs(l + 1, r)),  // 왼쪽 선택
        card[r] + (total - card[r] - dfs(l, r - 1))   // 오른쪽 선택
    );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; ++i) {
            cin >> card[i];
            sum[i] = sum[i - 1] + card[i];
        }

        memset(dp, -1, sizeof(dp));
        cout << dfs(1, N) << '\n';
    }

    return 0;
}
