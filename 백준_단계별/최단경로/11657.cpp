#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<pair<int, int>, int>> edges;

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({ {u, v}, w });
    }

    vector<long long> dist(N + 1, INF);
    dist[1] = 0;

    bool negative_cycle = false;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            int u = edges[j].first.first;
            int v = edges[j].first.second;
            int w = edges[j].second;

            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (i == N) negative_cycle = true;
            }
        }
    }

    if (negative_cycle) {
        cout << -1 << '\n';
    }
    else {
        for (int i = 2; i <= N; ++i) {
            if (dist[i] == INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }

    return 0;
}
