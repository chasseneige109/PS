#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string& s) {
    stack<char> stk;

    for (char c : s) {
        if (c == '(' || c == '[') {
            stk.push(c);
        }
        else if (c == ')') {
            if (stk.empty() || stk.top() != '(') return false;
            stk.pop();
        }
        else if (c == ']') {
            if (stk.empty() || stk.top() != '[') return false;
            stk.pop();
        }
        // 다른 문자는 무시
    }

    return stk.empty();
}

int main() {
    string line;
    while (true) {
        getline(cin, line);
        if (line == ".") break;

        cout << (isBalanced(line) ? "yes" : "no") << '\n';
    }

    return 0;
}
