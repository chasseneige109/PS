#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;

        // �ﰢ�� ����: ���� �� �� < ������ �� ���� ��
        if (a + b <= c || a + c <= b || b + c <= a) {
            cout << "Invalid\n";
        }
        else if (a == b && b == c) {
            cout << "Equilateral\n";
        }
        else if (a == b || b == c || a == c) {
            cout << "Isosceles\n";
        }
        else {
            cout << "Scalene\n";
        }
    }

    return 0;
}
