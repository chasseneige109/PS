#include <iostream>
#include <cmath> // sqrt �Լ� ����� ���� �ʿ�
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int count = 0;

    // 1���� sqrt(N)������ ��� i ó��
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            count++;
            if (count == K) {
                cout << i << '\n';
                return 0;
            }
        }
    }

    // ������ ��� ó�� (N / i ����)
    for (int i = (int)sqrt(N); i >= 1; i--) {
        if (N % i == 0 && i != N / i) {
            count++;
            if (count == K) {
                cout << N / i << '\n';
                return 0;
            }
        }
    }

    // K��° ����� �������� ���� ���
    cout << 0 << '\n';
    return 0;
}
