#include <iostream>
#include <vector>
using namespace std;

int N;
int length;
vector<vector<int>> tile;
int num = 0;

bool check(int x, int y, int len) {
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if (tile[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

void tromino(int x, int y, int len) {
    num++;
    int half = len / 2;

    // 각 사분면에서 비어있는 영역이 있다면 중앙에 트로미노 배치
    if (check(x, y, half))
        tile[x + half - 1][y + half - 1] = num;
    if (check(x, y + half, half))
        tile[x + half - 1][y + half] = num;
    if (check(x + half, y, half))
        tile[x + half][y + half - 1] = num;
    if (check(x + half, y + half, half))
        tile[x + half][y + half] = num;

    if (len == 2) {
        return;
    }

    // 재귀적으로 4개 사분면 처리
    tromino(x, y, half);
    tromino(x, y + half, half);
    tromino(x + half, y, half);
    tromino(x + half, y + half, half);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    length = 1 << N;  // 2^N

    tile.assign(length, vector<int>(length, 0));

    int x, y;
    cin >> x >> y;
    tile[length - y][x - 1] = -1;  // 구멍 표시

    tromino(0, 0, length);

    // 결과 출력
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            cout << tile[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}