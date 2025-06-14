#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> stack;
    while (N--) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int x;
            cin >> x;
            stack.push_back(x);
        }
        else if (cmd == 2) {
            if (stack.empty()) cout << -1 << '\n';
            else {
                cout << stack.back() << '\n';
                stack.pop_back();
            }
        }
        else if (cmd == 3) {
            cout << stack.size() << '\n';
        }
        else if (cmd == 4) {
            cout << (stack.empty() ? 1 : 0) << '\n';
        }
        else if (cmd == 5) {
            if (stack.empty()) cout << -1 << '\n';
            else cout << stack.back() << '\n';
        }
    }

    return 0;
}
