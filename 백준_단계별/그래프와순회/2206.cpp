#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> map;
int visited[1000][1000][2]; // visited[x][y][0]: 안 부심, [1]: 부심

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct State {
    int x, y, broken;
};

int bfs() {
    queue<State> q;
    q.push({ 0, 0, 0 });
    visited[0][0][0] = 1; // 시작 거리 = 1

    while (!q.empty()) {
        State cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, b = cur.broken;

        if (x == N - 1 && y == M - 1)
            return visited[x][y][b];

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            // 빈 칸 이동
            if (map[nx][ny] == 0 && visited[nx][ny][b] == 0) {
                visited[nx][ny][b] = visited[x][y][b] + 1;
                q.push({ nx, ny, b });
            }

            // 벽 부수고 이동 (단, 아직 안 부쉈을 때만)
            if (map[nx][ny] == 1 && b == 0 && visited[nx][ny][1] == 0) {
                visited[nx][ny][1] = visited[x][y][0] + 1;
                q.push({ nx, ny, 1 });
            }
        }
    }

    return -1; // 도달 불가능
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    map.resize(N, vector<int>(M));

    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < M; ++j) {
            map[i][j] = row[j] - '0';
        }
    }

    cout << bfs() << '\n';
    return 0;
}
