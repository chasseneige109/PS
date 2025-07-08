#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<int> component_sizes;

// ╩С, го, аб, ©Л
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dfs_stack(int x, int y) {
    stack<pair<int, int>> s;
    s.push({ x, y });
    visited[x][y] = true;

    int cnt = 1;

    while (!s.empty()) {
        auto [cx, cy] = s.top(); s.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (!visited[nx][ny] && map[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    s.push({ nx, ny });
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int main() {
    cin >> N;
    map.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < N; ++j) {
            map[i][j] = line[j] - '0';
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (map[i][j] == 1 && !visited[i][j]) {
                int size = dfs_stack(i, j);
                component_sizes.push_back(size);
            }
        }
    }

    sort(component_sizes.begin(), component_sizes.end());

    cout << component_sizes.size() << '\n';
    for (int size : component_sizes) {
        cout << size << '\n';
    }

    return 0;
}
