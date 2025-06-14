#include <iostream>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isVPS(const string& s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(') {
            stk.push(c);
        }
        else if (c == ')') {
            if (stk.empty()) return false;
            stk.pop();
        }
    }
    return stk.empty();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        cout << (isVPS(str) ? "YES" : "NO") << '\n';
    }
    return 0;
}
