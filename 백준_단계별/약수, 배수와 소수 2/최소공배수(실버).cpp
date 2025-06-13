#include <iostream>
using namespace std;

// 최대공약수 (유클리드 호제법)
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 최소공배수
int lcm(int a, int b) {
    return a / gcd(a, b) * b;  // 오버플로 방지: 먼저 나눠
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;
        cout << lcm(A, B) << '\n';
    }

    return 0;
}
