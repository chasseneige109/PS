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

        // ���ÿ��� ���κ��� ���� ���ڿ��� ��ġ�ϴ��� Ȯ��
        if (stk.size() >= plen) {
            bool match = true;
            for (int i = 0; i < plen; ++i) {
                if (stk[stk.size() - plen + i] != P[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                // ���� ���ڿ���ŭ pop
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
