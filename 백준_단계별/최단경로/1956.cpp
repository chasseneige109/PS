#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
const int INF = numeric_limits<int>::max();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    vector<vector<int>> dist(V + 1, vector<int>(V + 1, INF));

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c; // 방향 그래프
    }

    // 플로이드-워셜
    for (int k = 1; k <= V; ++k) {
        for (int i = 1; i <= V; ++i) {
            for (int j = 1; j <= V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int answer = INF;
    for (int i = 1; i <= V; ++i) {
        if (dist[i][i] != INF)
            answer = min(answer, dist[i][i]);
    }

    cout << (answer == INF ? -1 : answer) << '\n';

    return 0;
}
