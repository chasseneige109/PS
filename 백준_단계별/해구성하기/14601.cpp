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

    // �� ��и鿡�� ����ִ� ������ �ִٸ� �߾ӿ� Ʈ�ι̳� ��ġ
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

    // ��������� 4�� ��и� ó��
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
    tile[length - y][x - 1] = -1;  // ���� ǥ��

    tromino(0, 0, length);

    // ��� ���
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            cout << tile[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}