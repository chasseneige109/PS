#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, V, E;
vector<vector<int>> graph;
vector<int> color; // -1: �̹湮, 0/1: �׷�

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()) {
        int curr = q.front(); q.pop();

        for (int next : graph[curr]) {
            if (color[next] == -1) {
                color[next] = 1 - color[curr];
                q.push(next);
            }
            else if (color[next] == color[curr]) {
                return false; // ������ �������� ���� ����
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--) {
        cin >> V >> E;

        graph.assign(V + 1, vector<int>());
        color.assign(V + 1, -1); // ���� �� �� ĥ��

        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool isBipartite = true;

        for (int i = 1; i <= V; ++i) {
            if (color[i] == -1) {
                if (!bfs(i)) {
                    isBipartite = false;
                    break;
                }
            }
        }

        cout << (isBipartite ? "YES" : "NO") << "\n";
    }

    return 0;
}
