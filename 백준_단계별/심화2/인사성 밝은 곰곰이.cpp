#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_set<string> users;
    int count = 0;

    while (N--) {
        string msg;
        cin >> msg;

        if (msg == "ENTER") {
            users.clear();  // ���ο� �� ���� �� ���� ���� ����
        }
        else {
            if (users.find(msg) == users.end()) {
                users.insert(msg);
                ++count;
            }
        }
    }

    cout << count << '\n';
    return 0;
}
