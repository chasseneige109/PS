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

// �ּҰ����
int lcm(int a, int b) {
    return a / gcd(a, b) * b;  // �����÷� ����: ���� ����
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
