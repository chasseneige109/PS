#include <iostream>
using namespace std;

int recursion(const string& s, int l, int r, int& count) {
    count++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1, count);
}

int isPalindrome(const string& s, int& count) {
    return recursion(s, 0, s.length() - 1, count);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int count = 0;
        int result = isPalindrome(s, count);
        cout << result << " " << count << '\n';
    }

    return 0;
}
