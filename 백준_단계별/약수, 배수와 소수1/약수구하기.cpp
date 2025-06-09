#include <iostream>
#include <cmath> // sqrt 함수 사용을 위해 필요
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int count = 0;

    // 1부터 sqrt(N)까지의 약수 i 처리
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            count++;
            if (count == K) {
                cout << i << '\n';
                return 0;
            }
        }
    }

    // 역방향 약수 처리 (N / i 형태)
    for (int i = (int)sqrt(N); i >= 1; i--) {
        if (N % i == 0 && i != N / i) {
            count++;
            if (count == K) {
                cout << N / i << '\n';
                return 0;
            }
        }
    }

    // K번째 약수가 존재하지 않을 경우
    cout << 0 << '\n';
    return 0;
}
