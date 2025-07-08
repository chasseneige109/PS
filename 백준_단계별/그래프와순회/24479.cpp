#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;
vector<int> graph[MAX];
int visited[MAX];  // �湮 ���� ����
int order = 1;     // �湮 ���� ī��Ʈ

void dfs(int node) {
    visited[node] = order++;

    for (int next : graph[node]) {
        if (visited[next] == 0) {
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, R;
    cin >> N >> M >> R;

    // ���� �Է�
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // �����
    }

    // �� ������ ���� ����Ʈ �������� ����
    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(R);

    // �湮 ���� ���
    for (int i = 1; i <= N; ++i) {
        cout << visited[i] << '\n';
    }

    return 0;
}
