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

    vector<pair<int, int>> jewels(N); // (����, ����)
    for (int i = 0; i < N; ++i)
        cin >> jewels[i].first >> jewels[i].second;

    vector<int> bags(K);
    for (int i = 0; i < K; ++i)
        cin >> bags[i];

    sort(jewels.begin(), jewels.end());     // ���� ���� ��������
    sort(bags.begin(), bags.end());         // ���� ���� ��������

    priority_queue<int> pq; // ���� ���� max-heap
    int j = 0;
    long long total = 0;

    for (int i = 0; i < K; ++i) {
        // ���� ���濡 �� �� �ִ� ��� ���� �߰�
        while (j < N && jewels[j].first <= bags[i]) {
            pq.push(jewels[j].second); // ���� push
            j++;
        }
        // ���� ��� ���� ������
        if (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }
    }

    cout << total << '\n';
    return 0;
}
