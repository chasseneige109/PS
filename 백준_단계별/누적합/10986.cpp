#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> cnt(M, 0); // ������ �� ���� ����
    long long sum = 0, result = 0;
    cnt[0] = 1; // ������ ��ü�� ������ 0�� ��츦 ����

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        sum = (sum + num) % M;
        cnt[sum]++;
    }

    for (int i = 0; i < M; ++i) {
        result += cnt[i] * (cnt[i] - 1) / 2;
    }

    cout << result << '\n';
    return 0;
}
