#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    deque<pair<int, int>> dq; // (ǳ�� ��ȣ, ���̿� ���� ��)

    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;
        dq.push_back({ i, num });
    }

    while (!dq.empty()) {
        auto [idx, move] = dq.front();
        dq.pop_front();
        cout << idx << " ";

        if (dq.empty()) break;

        if (move > 0) {
            // move-1�� ������ ȸ��
            for (int i = 0; i < move - 1; ++i) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            // abs(move)�� ���� ȸ��
            for (int i = 0; i < -move; ++i) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}
