#include <iostream>
using namespace std;

int paper[2187][2187];  // ÃÖ´ë 3^7 = 2187
int cnt[3];  // cnt[0] = -1, cnt[1] = 0, cnt[2] = 1

bool check(int x, int y, int n) {
    int first = paper[x][y];
    for (int i = x; i < x + n; ++i) {
        for (int j = y; j < y + n; ++j) {
            if (paper[i][j] != first) return false;
        }
    }
    return true;
}

void divide(int x, int y, int n) {
    if (check(x, y, n)) {
        cnt[paper[x][y] + 1]++;  // -1 ¡æ 0, 0 ¡æ 1, 1 ¡æ 2
        return;
    }

    int size = n / 3;
    for (int dx = 0; dx < 3; ++dx) {
        for (int dy = 0; dy < 3; ++dy) {
            divide(x + dx * size, y + dy * size, size);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> paper[i][j];

    divide(0, 0, N);

    cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2] << '\n';
    return 0;
}
