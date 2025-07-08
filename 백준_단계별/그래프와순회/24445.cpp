#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, R;
vector<vector<int>> graph;
vector<int> visited;
int order = 1;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = order++;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr]) {
            if (visited[next] == 0) {
                visited[next] = order++;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> R;
    graph.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // ���� ���� �������� ����
    for (int i = 1; i <= N; ++i) {
        sort(graph[i].rbegin(), graph[i].rend());
    }

    bfs(R);

    for (int i = 1; i <= N; ++i) {
        cout << visited[i] << '\n';
    }

    return 0;
}
