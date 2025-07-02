#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<vector<int>> matrix;
vector<vector<int>> dp;
vector<vector<bool>> visited;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dfs(int x, int y)
{
    if (x == M - 1 && y == N - 1) return 1;

    if (visited[x][y]) return dp[x][y]; // 이미 계산됨

    visited[x][y] = true;
    int& res = dp[x][y];

    for (int d = 0; d < 4; ++d)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && ny >= 0 && nx < M && ny < N)
        {
            if (matrix[nx][ny] < matrix[x][y]) // 내리막
                res += dfs(nx, ny);
        }
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;
    matrix = vector<vector<int>>(M, vector<int>(N));
    dp = vector<vector<int>>(M, vector<int>(N, 0));
    visited = vector<vector<bool>>(M, vector<bool>(N, false));

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> matrix[i][j];

    cout << dfs(0, 0) << '\n';
    return 0;
}
