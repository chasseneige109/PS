#include <deque>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;

    deque<pair<int, int>> dq;  // {index, value}
    vector<int> result;
    result.reserve(N);

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        // 1) ������ ���� ��� �ε��� ����
        while (!dq.empty() && dq.front().first <= i - L)
            dq.pop_front();

        // 2) �� ������ �� ũ�ų� ���� ������ ����
        while (!dq.empty() && dq.back().second >= x)
            dq.pop_back();

        dq.emplace_back(i, x);

        // 3) �� ���� ���� ���� �ּҰ�
        result.push_back(dq.front().second);
    }

    // ���
    ostringstream oss;
    for (int v : result) {
        oss << v << ' ';
    }
    cout << oss.str();
    return 0;
}

