#include <iostream>
using namespace std;

int main() {
    bool submitted[31] = { false };  // 1������ 30������ �ε��� ���

    for (int i = 0; i < 28; i++) {
        int n;
        cin >> n;
        submitted[n] = true;  // ���� ���� ǥ��
    }

    for (int i = 1; i <= 30; i++) {
        if (!submitted[i]) {
            cout << i << '\n';  // ���� �� �� ��� ���
        }
    }

    return 0;
}
