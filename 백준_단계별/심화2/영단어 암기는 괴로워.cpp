#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second != b.second) return a.second > b.second;           // 1. 자주 나오는 순
    if (a.first.size() != b.first.size()) return a.first.size() > b.first.size(); // 2. 길이 긴 순
    return a.first < b.first;  // 3. 사전순 (오름차순 → 뒤에 올수록 먼저 출력됨)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    unordered_map<string, int> freq;

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        if (word.length() >= M) {
            freq[word]++;
        }
    }

    vector<pair<string, int>> words(freq.begin(), freq.end());

    sort(words.begin(), words.end(), cmp);

    for (const auto& w : words) {
        cout << w.first << '\n';
    }

    return 0;
}
