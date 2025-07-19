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

// Union-Find
vector<int> parent;
vector<int> rnk;

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]); // 경로 압축
}

bool uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return false;

    if (rnk[a] > rnk[b])
        parent[b] = a;
    else {
        parent[a] = b;
        if (rnk[a] == rnk[b])
            rnk[b]++;
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    vector<pair<double, double>> stars(N);
    for (int i = 0; i < N; ++i)
        cin >> stars[i].first >> stars[i].second;

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

    // union-find 초기화
    parent.resize(N);
    rnk.resize(N, 0);
    for (int i = 0; i < N; ++i)
        parent[i] = i;

    sort(edges.begin(), edges.end());

    double total = 0;
    int edgeCount = 0;
    for (const auto& edge : edges) {
        if (uni(edge.u, edge.v)) {
            total += edge.w;
            edgeCount++;
            if (edgeCount == N - 1)
                break;
        }
    }

    cout << fixed << setprecision(2) << total << "\n";
    return 0;
}
