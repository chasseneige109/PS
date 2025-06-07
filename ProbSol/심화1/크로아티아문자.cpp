#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    string patterns[] = { "dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z=" };

    int count = 0;
    for (int i = 0; i < s.length(); ) {
        bool matched = false;

        // ���� �� ���Ϻ��� �˻� (dz=�� �ݵ�� 3����)
        for (const string& pat : patterns) {
            if (s.substr(i, pat.length()) == pat) {
                i += pat.length();
                count++;
                matched = true;
                break;
            }
        }

        if (!matched) {
            i++;  // �׳� �� ����¥��
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}
