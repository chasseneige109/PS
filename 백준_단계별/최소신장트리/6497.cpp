#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<int> parent;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int m, n; // m: 집 개수, n: 도로 개수
        cin >> m >> n;
        if (m == 0 && n == 0) break;

        parent.assign(m, 0);
        for (int i = 0; i < m; ++i)
            parent[i] = i;

        vector<Edge> edges;
        int total = 0;

        for (int i = 0; i < n; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({ x, y, z });
            total += z; // 전체 비용 누적
        }

        sort(edges.begin(), edges.end());

        int mst = 0;
        for (const auto& edge : edges) {
            if (uni(edge.u, edge.v))
                mst += edge.w;
        }

        cout << (total - mst) << '\n';
    }

    return 0;
}
