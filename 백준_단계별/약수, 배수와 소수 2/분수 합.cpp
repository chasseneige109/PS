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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a1, b1, a2, b2;
    cin >> a1 >> b1;
    cin >> a2 >> b2;

    // 두 분수 합치기
    int numerator = a1 * b2 + a2 * b1;
    int denominator = b1 * b2;

    // 기약분수로 약분
    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;

    cout << numerator << " " << denominator << '\n';
    return 0;
}
