#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Edge {
    int u, v;
    double w;
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
    int N, M;
    cin >> N >> M;

    vector<pair<double, double>> stars(N);
    for (int i = 0; i < N; ++i)
        cin >> stars[i].first >> stars[i].second;

    parent.resize(N);
    for (int i = 0; i < N; ++i)
        parent[i] = i;

    // 이미 연결된 간선
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        uni(a - 1, b - 1); // 1-indexed → 0-indexed
    }

    vector<Edge> edges;

    // 거리 계산 후 간선 저장
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            double dx = stars[i].first - stars[j].first;
            double dy = stars[i].second - stars[j].second;
            double dist = sqrt(dx * dx + dy * dy);
            edges.push_back({ i, j, dist });
        }
    }

    sort(edges.begin(), edges.end());

    double total = 0;
    for (auto& edge : edges) {
        if (uni(edge.u, edge.v)) {
            total += edge.w;
        }
    }

    cout << fixed << setprecision(2) << total << '\n';
    return 0;
}
