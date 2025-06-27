#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<string> board;

// 누적합 배열: 시작이 W, 시작이 B일 때 각각
vector<vector<int>> w_sum, b_sum;

// 누적합 계산 함수
void compute_prefix_sum(const vector<vector<int>>& diff, vector<vector<int>>& psum) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            psum[i][j] = diff[i][j]
                + psum[i - 1][j]
                + psum[i][j - 1]
                - psum[i - 1][j - 1];
        }
    }
}

// K×K 구간의 잘못된 칸 수 구하는 함수
int get_sum(const vector<vector<int>>& psum, int x1, int y1, int x2, int y2) {
    return psum[x2][y2]
        - psum[x1 - 1][y2]
        - psum[x2][y1 - 1]
        + psum[x1 - 1][y1 - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    board.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        string row;
        cin >> row;
        board[i] = " " + row;  // 1-based indexing
    }

    // diff[i][j] = (현재 색과 예상 체스판 색이 다르면 1, 아니면 0)
    vector<vector<int>> w_diff(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> b_diff(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            char expected_w = ((i + j) % 2 == 0) ? 'W' : 'B'; // 시작이 W
            char expected_b = ((i + j) % 2 == 0) ? 'B' : 'W'; // 시작이 B

            if (board[i][j] != expected_w) w_diff[i][j] = 1;
            if (board[i][j] != expected_b) b_diff[i][j] = 1;
        }
    }

    w_sum = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
    b_sum = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));

    compute_prefix_sum(w_diff, w_sum);
    compute_prefix_sum(b_diff, b_sum);

    int answer = 1e9;

    for (int i = K; i <= N; ++i) {
        for (int j = K; j <= M; ++j) {
            int repaint_w = get_sum(w_sum, i - K + 1, j - K + 1, i, j);
            int repaint_b = get_sum(b_sum, i - K + 1, j - K + 1, i, j);
            answer = min({ answer, repaint_w, repaint_b });
        }
    }

    cout << answer << '\n';
    return 0;
}
