#include <iostream>
using namespace std;

int main() {
    bool submitted[31] = { false };  // 1번부터 30번까지 인덱스 사용

    for (int i = 0; i < 28; i++) {
        int n;
        cin >> n;
        submitted[n] = true;  // 과제 제출 표시
    }

    for (int i = 1; i <= 30; i++) {
        if (!submitted[i]) {
            cout << i << '\n';  // 제출 안 한 사람 출력
        }
    }

    return 0;
}
