#include <iostream>
using namespace std;

int paper[100][100];  // 0: ���, 1: ����

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        int x, y;
        cin >> x >> y;

        // ������ ���� 10x10 ��ŭ 1�� ä���
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                paper[i][j] = 1;
            }
        }
    }

    int area = 0;
    // ��ü ��ȭ������ ���� ����(1) ���� ����
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (paper[i][j] == 1) {
                area++;
            }
        }
    }

    cout << area << '\n';
    return 0;
}
