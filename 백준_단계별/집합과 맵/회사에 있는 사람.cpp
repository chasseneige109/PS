#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<string> office;
    string name, cmd;

    for (int i = 0; i < n; ++i) {
        cin >> name >> cmd;
        if (cmd == "enter") {
            office.insert(name);
        }
        else if (cmd == "leave") {
            office.erase(name);
        }
    }

    vector<string> result(office.begin(), office.end());
    sort(result.rbegin(), result.rend()); // 사전 역순 정렬

    for (const string& person : result) {
        cout << person << '\n';
    }

    return 0;
}
