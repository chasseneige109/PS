#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        ++indegree[b];
    }

    // 번호가 작은 문제부터 풀기 위한 min-heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // 진입차수 0인 문제들부터 큐에 삽입
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        cout << curr << ' ';

        for (int next : graph[curr]) {
            if (--indegree[next] == 0) {
                pq.push(next);
            }
        }
    }

    return 0;
}
