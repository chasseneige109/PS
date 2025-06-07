#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int pos[26];  // a~z의 위치
    for (int i = 0; i < 26; i++) pos[i] = -1;  // 전부 -1로 초기화

    for (int i = 0; i < s.length(); i++) {
        int idx = s[i] - 'a';  // 알파벳 인덱스
        if (pos[idx] == -1) {  // 처음 등장한 경우에만 기록
            pos[idx] = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << pos[i] << " ";
    }

    cout << "\n";
    return 0;
}
