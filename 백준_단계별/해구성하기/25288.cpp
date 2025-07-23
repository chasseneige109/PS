#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string s;
    cin >> N >> s;
    while (N--) {
        cout << s;
    }
    cout << '\n';
    return 0;
}
