#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    queue<int> q;
    for (int i = 1; i <= N; ++i) q.push(i);   // 1, 2, ��, N

    vector<int> result;
    while (!q.empty()) {
        // K-1���� �ڷ� ������
        for (int i = 1; i < K; ++i) {
            q.push(q.front());
            q.pop();
        }
        // K��° ��� ����
        result.push_back(q.front());
        q.pop();
    }

    // ��� ����: <a, b, c, ...>
    cout << '<';
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i + 1 != result.size()) cout << ", ";
    }
    cout << ">\n";
    return 0;
}
