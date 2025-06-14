#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second != b.second) return a.second > b.second;           // 1. ���� ������ ��
    if (a.first.size() != b.first.size()) return a.first.size() > b.first.size(); // 2. ���� �� ��
    return a.first < b.first;  // 3. ������ (�������� �� �ڿ� �ü��� ���� ��µ�)
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
