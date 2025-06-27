#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();

    // ������ �迭 ����: 26�� ���ĺ�, ���� n+1
    vector<vector<int>> prefix(26, vector<int>(n + 1, 0));

    // ������ �迭 ���
    for (int i = 0; i < n; ++i) {
        int curr = s[i] - 'a';
        for (int j = 0; j < 26; ++j) {
            prefix[j][i + 1] = prefix[j][i] + (j == curr ? 1 : 0);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        int idx = c - 'a';
        cout << prefix[idx][r + 1] - prefix[idx][l] << '\n';
    }

    return 0;
}
