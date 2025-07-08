#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
vector<vector<int>> graph;
vector<int> visited;
int order = 1;

void dfs(int node) {
    visited[node] = order++;
    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> R;

    graph.resize(N + 1);
    visited.resize(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 내림차순 정렬
    for (int i = 1; i <= N; ++i) {
        sort(graph[i].rbegin(), graph[i].rend());  // 내림차순
    }

    dfs(R);

    for (int i = 1; i <= N; ++i) {
        cout << visited[i] << '\n';
    }

    return 0;
}
