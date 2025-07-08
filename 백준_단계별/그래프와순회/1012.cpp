#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int M, N, K;
vector<vector<int>> field;
vector<vector<bool>> visited;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs_stack(int x, int y) {
    stack<pair<int, int>> s;
    s.push({ x, y });
    visited[x][y] = true;

    while (!s.empty()) {
        pair<int, int> curr = s.top(); s.pop();
        int cx = curr.first;
        int cy = curr.second;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (field[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    s.push({ nx, ny });
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> M >> N >> K;

        field.assign(M, vector<int>(N, 0));
        visited.assign(M, vector<bool>(N, false));

        for (int i = 0; i < K; ++i) {
            int x, y;
            cin >> x >> y;
            field[x][y] = 1;
        }

        int worm_count = 0;

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (field[i][j] == 1 && !visited[i][j]) {
                    dfs_stack(i, j);
                    worm_count++;
                }
            }
        }

        cout << worm_count << '\n';
    }

    return 0;
}
