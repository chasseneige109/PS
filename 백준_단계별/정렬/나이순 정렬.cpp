#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, string>> members(N);

    for (int i = 0; i < N; ++i) 
    {
        cin >> members[i].first >> members[i].second;
        // first: 나이, second: 이름
    }

    stable_sort(members.begin(), members.end(), [](const pair<int, string>& a, const pair<int, string>& b) 
        {
        return a.first < b.first; // 나이 순 정렬, 같은 나이면 순서 유지
        });

    for (const auto& member : members) {
        cout << member.first << ' ' << member.second << '\n';
    }

    return 0;
}
