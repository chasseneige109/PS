#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
int board[50][50];
bool used[50][50];
int answer = 1000000;

int min_d(int x, int y) {
    int dist = 10000;
    for (int k = 0; k < N; ++k) {
        for (int m = 0; m < N; ++m) {
            if (used[k][m]) {
                dist = min(dist, abs(x - k) + abs(y - m));
            }
        }
    }
    return dist;
}

void dfs(int depth, int r_idx, int c_idx) {
    if (depth == M) {
        int current_answer = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == 1) {
                    current_answer += min_d(i, j);
                }
            }
        }
        answer = min(current_answer, answer);
        return;
    }

    for (int i = r_idx; i < N; ++i) {
        int current_j_start = (i == r_idx) ? c_idx : 0;

        for (int j = current_j_start; j < N; ++j) {
            if (board[i][j] == 2 && !used[i][j]) {
                used[i][j] = true;

                int next_r_idx = i;
                int next_c_idx = j + 1;
                if (next_c_idx == N) {
                    next_r_idx++;
                    next_c_idx = 0;
                }

                dfs(depth + 1, next_r_idx, next_c_idx);

                used[i][j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int k;
            cin >> k;
            board[i][j] = k;
        }
    }

    dfs(0, 0, 0);

    cout << answer << "\n";
    return 0;
}