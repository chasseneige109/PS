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

        // 가장 긴 패턴부터 검사 (dz=는 반드시 3글자)
        for (const string& pat : patterns) {
            if (s.substr(i, pat.length()) == pat) {
                i += pat.length();
                count++;
                matched = true;
                break;
            }
        }

        if (!matched) {
            i++;  // 그냥 한 글자짜리
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}
