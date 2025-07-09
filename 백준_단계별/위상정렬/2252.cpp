#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> order(N + 1);  // ���� ����Ʈ: a �� b
    vector<int> indegree(N + 1, 0);    // ���� ����
    queue<int> q;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        order[a].push_back(b);  // a�� b���� �տ� ���� ��
        indegree[b]++;
    }

    // ���� ������ 0�� �������� ť�� �ֱ�
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // ���� ����
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        cout << curr << " ";

        for (int next : order[curr]) {
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }

    return 0;
}
