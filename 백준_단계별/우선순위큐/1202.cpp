#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> jewels(N); // (무게, 가격)
    for (int i = 0; i < N; ++i)
        cin >> jewels[i].first >> jewels[i].second;

    vector<int> bags(K);
    for (int i = 0; i < K; ++i)
        cin >> bags[i];

    sort(jewels.begin(), jewels.end());     // 무게 기준 오름차순
    sort(bags.begin(), bags.end());         // 가방 무게 오름차순

    priority_queue<int> pq; // 가격 기준 max-heap
    int j = 0;
    long long total = 0;

    for (int i = 0; i < K; ++i) {
        // 현재 가방에 들어갈 수 있는 모든 보석 추가
        while (j < N && jewels[j].first <= bags[i]) {
            pq.push(jewels[j].second); // 가격 push
            j++;
        }
        // 가장 비싼 보석 꺼내기
        if (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }
    }

    cout << total << '\n';
    return 0;
}
