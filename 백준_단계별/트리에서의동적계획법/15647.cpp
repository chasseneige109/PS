#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<pair<int, int>>> tree;
vector<long long> subtreeSize;
vector<long long> distSum;

void dfs1(int node, int parent) {
    subtreeSize[node] = 1;
    for (auto [next, w] : tree[node]) {
        if (next == parent) continue;
        dfs1(next, node);
        subtreeSize[node] += subtreeSize[next];
        distSum[node] += distSum[next] + subtreeSize[next] * w;
    }
}

void dfs2(int node, int parent) {
    for (auto [next, w] : tree[node]) {
        if (next == parent) continue;
        // �ٽ� ���� ����
        distSum[next] = distSum[node] + (N - 2 * subtreeSize[next]) * w;
        dfs2(next, node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    // ���� ũ�� �ʱ�ȭ
    tree.resize(N + 1);
    subtreeSize.resize(N + 1);
    distSum.resize(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    dfs1(1, 0); // ��Ʈ �������� ����Ʈ�� ũ��, �Ÿ��� ���
    dfs2(1, 0); // ��Ʈ���� �ڽĵ�� �Ÿ� ����

    for (int i = 1; i <= N; ++i) {
        cout << distSum[i] << '\n';
    }

    return 0;
}