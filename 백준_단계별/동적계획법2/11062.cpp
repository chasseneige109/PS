#include <iostream>
#include <vector>
#include <cstring> // memset
using namespace std;

int card[1001];
int dp[1001][1001]; // dp[l][r]: l~r���� A�� ���� �� �ִ� �ִ� ����
int sum[1001];

int dfs(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    int total = sum[r] - sum[l - 1];

    // ���� ���� �Ǵ� �������� ����� �� ��밡 ���� �� �ִ� ������ ����
    return dp[l][r] = max(
        card[l] + (total - card[l] - dfs(l + 1, r)),  // ���� ����
        card[r] + (total - card[r] - dfs(l, r - 1))   // ������ ����
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
