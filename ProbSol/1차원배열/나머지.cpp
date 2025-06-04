#include <iostream>
using namespace std;

int main() {
    bool rest[42] = { false };  // 0~41까지 나머지 여부 체크
    int n;

    for (int i = 0; i < 10; i++) {
        cin >> n;
        rest[n % 42] = true;  // 해당 나머지를 체크
    }

    int count = 0;
    for (int i = 0; i < 42; i++) {
        if (rest[i]) count++;  // true인 개수 세기
    }

    cout << count << "\n";
    return 0;
}
