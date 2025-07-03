#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int M;
        cin >> M;
        cout << (M + 1) / 2 << '\n';

        priority_queue<int> maxHeap; // 중앙값 이하
        priority_queue<int, vector<int>, greater<int>> minHeap; // 중앙값 초과

        int count = 0;
        for (int i = 0; i < M; ++i) {
            int x;
            cin >> x;

            if (maxHeap.empty() || x <= maxHeap.top())
                maxHeap.push(x);
            else
                minHeap.push(x);

            // 균형 유지
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // 홀수 번째 입력 → 출력
            if (i % 2 == 0) {
                cout << maxHeap.top() << ' ';
                count++;
                if (count % 10 == 0) cout << '\n';
            }
        }
        if (count % 10 != 0) cout << '\n';
    }

    return 0;
}
