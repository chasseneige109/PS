#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (dist[u] < cost) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[v] > cost + w) {
                dist[v] = cost + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m, t;
        cin >> n >> m >> t;

        int s, g, h;
        cin >> s >> g >> h;

        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i < m; ++i) {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].emplace_back(b, d);
            graph[b].emplace_back(a, d);
        }

        vector<int> candidates(t);
        for (int i = 0; i < t; ++i)
            cin >> candidates[i];

        // 다익스트라 3번
        auto distS = dijkstra(s, graph);
        auto distG = dijkstra(g, graph);
        auto distH = dijkstra(h, graph);

        vector<int> answer;

        for (int x : candidates) {
            int viaGH = distS[g] + distG[h] + distH[x];
            int viaHG = distS[h] + distH[g] + distG[x];

            if (distS[x] == viaGH || distS[x] == viaHG)
                answer.push_back(x);
        }

        sort(answer.begin(), answer.end());
        for (int x : answer) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
