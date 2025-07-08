#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited_dfs;
vector<bool> visited_bfs;

void dfs_stack(int start) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int curr = s.top(); s.pop();

        if (visited_dfs[curr]) continue;

        visited_dfs[curr] = true;
        cout << curr << " ";

        // 오름차순 방문을 위해 **역순으로 push**
        for (int i = graph[curr].size() - 1; i >= 0; --i) {
            int next = graph[curr][i];
            if (!visited_dfs[next]) {
                s.push(next);
            }
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited_bfs[start] = true;

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        cout << curr << " ";

        for (int next : graph[curr]) {
            if (!visited_bfs[next]) {
                visited_bfs[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;

    graph.resize(N + 1);
    visited_dfs.resize(N + 1, false);
    visited_bfs.resize(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 오름차순 정점 방문을 위해 정렬
    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs_stack(V);
    cout << '\n';
    bfs(V);
    cout << '\n';

    return 0;
}
