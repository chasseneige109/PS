#include <iostream>
using namespace std;

int main() {
    bool rest[42] = { false };  // 0~41���� ������ ���� üũ
    int n;

    for (int i = 0; i < 10; i++) {
        cin >> n;
        rest[n % 42] = true;  // �ش� �������� üũ
    }

    int count = 0;
    for (int i = 0; i < 42; i++) {
        if (rest[i]) count++;  // true�� ���� ����
    }

    cout << count << "\n";
    return 0;
}
