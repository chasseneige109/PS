#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int totalMinutes = A * 60 + B + C;

    // �Ϸ縦 �ѱ�� �ڵ����� 0~1439������ �����
    totalMinutes %= 1440;

    int hour = totalMinutes / 60;
    int minute = totalMinutes % 60;

    cout << hour << " " << minute << endl;
    return 0;
}
