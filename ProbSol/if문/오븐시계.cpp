#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int totalMinutes = A * 60 + B + C;

    // 하루를 넘기면 자동으로 0~1439분으로 만들기
    totalMinutes %= 1440;

    int hour = totalMinutes / 60;
    int minute = totalMinutes % 60;

    cout << hour << " " << minute << endl;
    return 0;
}
