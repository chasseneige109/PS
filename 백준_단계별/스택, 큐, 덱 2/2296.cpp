#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string S, P;
    cin >> S >> P;
    int plen = P.size();

    vector<char> stk;

    for (char c : S) {
        stk.push_back(c);

        // 스택에서 끝부분이 폭발 문자열과 일치하는지 확인
        if (stk.size() >= plen) {
            bool match = true;
            for (int i = 0; i < plen; ++i) {
                if (stk[stk.size() - plen + i] != P[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                // 폭발 문자열만큼 pop
                for (int i = 0; i < plen; ++i)
                    stk.pop_back();
            }
        }
    }

    if (stk.empty()) {
        cout << "FRULA\n";
    }
    else {
        for (char c : stk)
            cout << c;
        cout << '\n';
    }

    return 0;
}
