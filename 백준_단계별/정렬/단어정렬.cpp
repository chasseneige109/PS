#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    set<string> wordSet; // 중복 제거용
    string s;
    while (N--) {
        cin >> s;
        wordSet.insert(s);
    }

    vector<string> words(wordSet.begin(), wordSet.end());

    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        if (a.length() != b.length()) return a.length() < b.length();
        return a < b;
        });

    for (const auto& word : words) {
        cout << word << '\n';
    }

    return 0;
}
