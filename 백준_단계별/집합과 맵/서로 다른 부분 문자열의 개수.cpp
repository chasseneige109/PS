#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;

    unordered_set<string> substrings;

    int n = S.size();
    for (int i = 0; i < n; ++i) {
        string temp = "";
        for (int j = i; j < n; ++j) {
            temp += S[j];           // ���ӵ� ���ڿ� ����
            substrings.insert(temp); // �ߺ� ���� ����
        }
    }

    cout << substrings.size() << '\n';
    return 0;
}
