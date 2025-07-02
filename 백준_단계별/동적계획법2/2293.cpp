#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> coin(N);
    for (int i = 0; i < N; ++i)
        cin >> coin[i];

    vector<int> dp(K + 1, 0);
    dp[0] = 1;  // 0���� ����� ����� 1���� (�ƹ� ������ �� ���� ��)

    for (int i = 0; i < N; ++i) {
        for (int j = coin[i]; j <= K; ++j) {
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[K] << "\n";
    return 0;
}
