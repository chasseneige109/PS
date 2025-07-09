#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> order(N + 1);  // 인접 리스트: a → b
    vector<int> indegree(N + 1, 0);    // 진입 차수
    queue<int> q;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        order[a].push_back(b);  // a가 b보다 앞에 서야 함
        indegree[b]++;
    }

    // 진입 차수가 0인 정점부터 큐에 넣기
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // 위상 정렬
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
