#include <iostream>
using namespace std;

int main() {
    int T; // �׽�Ʈ ���̽� ��
    cin >> T;

    while (T--) {
        int C; // �Ž����� (��Ʈ ����)
        cin >> C;

        int quarter = C / 25;
        C %= 25;

        int dime = C / 10;
        C %= 10;

        int nickel = C / 5;
        C %= 5;

        int penny = C;

        cout << quarter << ' ' << dime << ' ' << nickel << ' ' << penny << '\n';
    }

    return 0;
}
