#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = 1e9;

int V, E;
vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(int start) {
    vector<int> dist(V + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] < d) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;
    graph.resize(V + 1);

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c); // ¾ç¹æÇâ
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> from1 = dijkstra(1);
    vector<int> fromV1 = dijkstra(v1);
    vector<int> fromV2 = dijkstra(v2);

    // 1 ¡æ v1 ¡æ v2 ¡æ N
    int path1 = from1[v1] + fromV1[v2] + fromV2[V];
    // 1 ¡æ v2 ¡æ v1 ¡æ N
    int path2 = from1[v2] + fromV2[v1] + fromV1[V];

    int result = min(path1, path2);
    if (result >= INF || result < 0)
        cout << -1 << '\n';
    else
        cout << result << '\n';

    return 0;
}
