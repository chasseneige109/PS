#include <iostream>
using namespace std;

// �ִ����� (��Ŭ���� ȣ����)
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// �ּҰ����
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;  // �����÷� ���� ���� ������ ����
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    cin >> A >> B;

    cout << lcm(A, B) << '\n';

    return 0;
}
