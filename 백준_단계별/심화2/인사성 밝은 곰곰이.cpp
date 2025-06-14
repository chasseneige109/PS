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
            users.clear();  // 새로운 방 입장 → 이전 유저 리셋
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
