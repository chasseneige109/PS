#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
const int INF = numeric_limits<int>::max();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> graph(V + 1);
    vector<int> dist(V + 1, INF);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[K] = 0;
    pq.emplace(0, K);  // (거리, 정점)

    while (!pq.empty())
    {
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (dist[curr] < d) continue;

        for (auto& p : graph[curr])
        {
            if (dist[p.first] > d + p.second)
            {
                dist[p.first] = d + p.second;
                pq.emplace(dist[p.first], p.first);
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}
    
