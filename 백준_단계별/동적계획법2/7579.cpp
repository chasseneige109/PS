#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][10001]; // dp[i][j]: i��° �۱��� ������� �� j ������� ���� �� �ִ� �ִ� �޸�

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> memory(N + 1);
    vector<int> cost(N + 1);

    for (int i = 1; i <= N; ++i)
        cin >> memory[i];
    for (int i = 1; i <= N; ++i)
        cin >> cost[i];

    const int MAX_COST = 10000;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= MAX_COST; ++j) {
            if (j < cost[i]) {
                dp[i][j] = dp[i - 1][j]; // �� i �� ��
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
            }
        }
    }

    // �ּ� ��� ã��
    for (int j = 0; j <= MAX_COST; ++j) {
        if (dp[N][j] >= M) {
            cout << j << '\n';
            break;
        }
    }

    return 0;
}
