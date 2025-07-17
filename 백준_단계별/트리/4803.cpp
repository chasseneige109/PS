#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 501;
vector<int> adj[MAX];
bool visited[MAX];

bool dfs(int curr, int parent) {
    visited[curr] = true;
    for (int next : adj[curr]) {
        if (!visited[next]) {
            if (dfs(next, curr)) return true;
        }
        else if (next != parent) {
            return true;  // ����Ŭ �߰�
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, caseNum = 1;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        // �ʱ�ȭ
        for (int i = 1; i <= n; ++i) adj[i].clear();
        memset(visited, false, sizeof(visited));

        // ���� �Է�
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int treeCount = 0;

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                if (!dfs(i, 0)) {
                    treeCount++;
                }
            }
        }

        // ���
        cout << "Case " << caseNum++ << ": ";
        if (treeCount == 0)
            cout << "No trees.\n";
        else if (treeCount == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << treeCount << " trees.\n";
    }

    return 0;
}
