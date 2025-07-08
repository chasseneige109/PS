#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int l;
        cin >> l;

        pair<int, int> start, goal;
        cin >> start.first >> start.second;
        cin >> goal.first >> goal.second;

        vector<vector<int>> visited(l, vector<int>(l, -1));

        queue<pair<int, int>> q;
        q.push(start);
        visited[start.first][start.second] = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == goal.first && y == goal.second) break;

            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < l && ny < l && visited[nx][ny] == -1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({ nx, ny });
                }
            }
        }

        cout << visited[goal.first][goal.second] << '\n';
    }

    return 0;
}
