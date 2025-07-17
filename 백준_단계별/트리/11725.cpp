#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;
vector<int> tree[MAX]; // 인접 리스트
int parent[MAX];       // 각 노드의 부모 저장
bool visited[MAX];     // 방문 여부

// DFS 함수
void dfs(int curr) {
    visited[curr] = true; // 현재 노드 방문 표시

    // 현재 노드와 연결된 이웃 노드들 검사
    for (int next : tree[curr]) {
        if (!visited[next]) {
            parent[next] = curr;   // 자식의 부모로 현재 노드를 저장
            dfs(next);             // 자식 노드로 재귀 호출
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 간선 입력 받기 (무방향 그래프)
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // DFS 시작 (루트는 항상 1번 노드)
    dfs(1);

    // 결과 출력 (2번부터)
    for (int i = 2; i <= n; ++i) {
        cout << parent[i] << "\n";
    }

    return 0;
}
