#include <iostream>
using namespace std;

int paper[100][100];  // 0: 흰색, 1: 검정

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        int x, y;
        cin >> x >> y;

        // 색종이 영역 10x10 만큼 1로 채우기
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                paper[i][j] = 1;
            }
        }
    }

    int area = 0;
    // 전체 도화지에서 검은 영역(1) 개수 세기
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
