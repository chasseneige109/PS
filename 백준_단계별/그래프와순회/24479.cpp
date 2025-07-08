#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;
vector<int> graph[MAX];
int visited[MAX];  // 방문 순서 저장
int order = 1;     // 방문 순서 카운트

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

    // 간선 입력
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 양방향
    }

    // 각 정점의 인접 리스트 오름차순 정렬
    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(R);

    // 방문 순서 출력
    for (int i = 1; i <= N; ++i) {
        cout << visited[i] << '\n';
    }

    return 0;
}
