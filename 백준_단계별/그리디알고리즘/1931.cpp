#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> meetings(N);
    for (int i = 0; i < N; ++i) {
        cin >> meetings[i].first >> meetings[i].second; // (시작, 끝)
    }

    // 끝나는 시간 기준 정렬
    sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
        });

    int count = 0;
    int end_time = 0;

    for (const auto& meeting : meetings) {
        if (meeting.first >= end_time) {
            ++count;
            end_time = meeting.second;
        }
    }

    cout << count << '\n';
    return 0;
}
