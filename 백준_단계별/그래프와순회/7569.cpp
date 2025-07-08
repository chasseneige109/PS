#include <iostream>
#include <vector>
#include <queue>
#include <tuple>  // tuple 포함
using namespace std;

int M, N, H;  // M: 열, N: 행, H: 높이
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> H;

    vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
    queue<tuple<int, int, int>> q;

    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                cin >> box[h][n][m];
                if (box[h][n][m] == 1) {
                    q.push(make_tuple(h, n, m));  // (z, x, y)
                }
            }
        }
    }

    while (!q.empty()) {
        tuple<int, int, int> curr = q.front();
        q.pop();

        int z = get<0>(curr);
        int x = get<1>(curr);
        int y = get<2>(curr);

        for (int d = 0; d < 6; ++d) {
            int nz = z + dz[d];
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nz >= 0 && nz < H && nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (box[nz][nx][ny] == 0) {
                    box[nz][nx][ny] = box[z][x][y] + 1;
                    q.push(make_tuple(nz, nx, ny));
                }
            }
        }
    }

    int max_day = 0;
    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                if (box[h][n][m] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                max_day = max(max_day, box[h][n][m]);
            }
        }
    }

    cout << max_day - 1 << '\n';  // 시작값이 1이므로 -1
    return 0;
}
