#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int board[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= 100; ++i) board[i] = i;

    for (int i = 0; i < N + M; ++i) {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    vector<int> dist(101, -1);
    queue<int> q;

    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int curr = q.front(); q.pop();

        for (int dice = 1; dice <= 6; ++dice) {
            int next = curr + dice;
            if (next > 100) continue;

            next = board[next];

            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    cout << dist[100] << "\n";
    return 0;
}
