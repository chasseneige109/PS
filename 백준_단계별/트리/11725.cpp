#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;
vector<int> tree[MAX]; // ���� ����Ʈ
int parent[MAX];       // �� ����� �θ� ����
bool visited[MAX];     // �湮 ����

// DFS �Լ�
void dfs(int curr) {
    visited[curr] = true; // ���� ��� �湮 ǥ��

    // ���� ���� ����� �̿� ���� �˻�
    for (int next : tree[curr]) {
        if (!visited[next]) {
            parent[next] = curr;   // �ڽ��� �θ�� ���� ��带 ����
            dfs(next);             // �ڽ� ���� ��� ȣ��
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // ���� �Է� �ޱ� (������ �׷���)
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // DFS ���� (��Ʈ�� �׻� 1�� ���)
    dfs(1);

    // ��� ��� (2������)
    for (int i = 2; i <= n; ++i) {
        cout << parent[i] << "\n";
    }

    return 0;
}
