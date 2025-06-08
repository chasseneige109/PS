#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int basket[101];  // N 최대 100까지니까 넉넉히 101

    // 초기화: 바구니 번호 = 1~N
    for (int i = 1; i <= N; i++) {
        basket[i] = i;
    }

    // M번 동안 i~j 구간을 역순
    for (int m = 0; m < M; m++) {
        int i, j;
        cin >> i >> j;

        // 양쪽에서 가운데로 swap
        while (i < j) {
            int temp = basket[i];
            basket[i] = basket[j];
            basket[j] = temp;
            i++;
            j--;
        }
    }

    // 결과 출력
    for (int i = 1; i <= N; i++) {
        cout << basket[i] << " ";
    }

    cout << "\n";
    return 0;
}
