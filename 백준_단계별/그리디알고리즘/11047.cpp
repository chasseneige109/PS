#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> coins(N);
    for (int i = 0; i < N; ++i) {
        cin >> coins[i];
    }

    int count = 0;
    // ū �������� ���
    for (int i = N - 1; i >= 0; --i) {
        if (K >= coins[i]) {
            count += K / coins[i];
            K %= coins[i];
        }
    }

    cout << count << '\n';
    return 0;
}
