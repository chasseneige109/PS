#include <iostream>
using namespace std;

// �ִ����� (��Ŭ���� ȣ����)
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

    // �� �м� ��ġ��
    int numerator = a1 * b2 + a2 * b1;
    int denominator = b1 * b2;

    // ���м��� ���
    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;

    cout << numerator << " " << denominator << '\n';
    return 0;
}
