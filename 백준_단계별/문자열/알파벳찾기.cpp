#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int pos[26];  // a~z�� ��ġ
    for (int i = 0; i < 26; i++) pos[i] = -1;  // ���� -1�� �ʱ�ȭ

    for (int i = 0; i < s.length(); i++) {
        int idx = s[i] - 'a';  // ���ĺ� �ε���
        if (pos[idx] == -1) {  // ó�� ������ ��쿡�� ���
            pos[idx] = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << pos[i] << " ";
    }

    cout << "\n";
    return 0;
}
