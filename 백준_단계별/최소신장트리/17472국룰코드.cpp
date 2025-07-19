#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int board[10][10];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct Edge {
    int u, v, w;
    bool operator<(const Edge& e) const {
        return w < e.w;
    }
};

vector<Edge> edges;
int parent[7]; // 최대 섬 수는 6

bool in_map(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

// BFS로 섬 라벨링
void bfs_label(int sy, int sx, int label) {
    queue<pair<int, int>> q;
    q.push({ sy, sx });
    board[sy][sx] = label;

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();

        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (!in_map(ny, nx)) continue;
            if (board[ny][nx] == 1) {
                board[ny][nx] = label;
                q.push({ ny, nx });
            }
        }
    }
}

// 각 섬에서 4방향으로 다리 탐색
void build_bridges(int island) {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (board[y][x] != island) continue;

            for (int d = 0; d < 4; ++d) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                int len = 0;

                while (in_map(ny, nx) && board[ny][nx] == 0) {
                    ny += dy[d];
                    nx += dx[d];
                    len++;
                }

                if (!in_map(ny, nx)) continue;
                int to = board[ny][nx];
                if (to != 0 && to != island && len >= 2) {
                    edges.push_back({ island, to, len });
                }
            }
        }
    }
}

// Union-Find
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}

int main() {
    cin >> N >> M;
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
            cin >> board[y][x];

    int label = 2; // 섬 번호는 2부터 시작
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
            if (board[y][x] == 1)
                bfs_label(y, x, label++);

    int island_count = label - 2;

    // 다리 후보 생성
    for (int i = 2; i < label; ++i)
        build_bridges(i);

    sort(edges.begin(), edges.end());

    // MST
    for (int i = 0; i <= island_count + 1; ++i)
        parent[i] = i;

    int total = 0, count = 0;
    for (auto& e : edges) {
        if (unite(e.u, e.v)) {
            total += e.w;
            count++;
            if (count == island_count - 1) break;
        }
    }

    if (count == island_count - 1)
        cout << total << '\n';
    else
        cout << -1 << '\n';

    return 0;
}
