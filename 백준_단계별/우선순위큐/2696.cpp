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

        priority_queue<int> maxHeap; // �߾Ӱ� ����
        priority_queue<int, vector<int>, greater<int>> minHeap; // �߾Ӱ� �ʰ�

        int count = 0;
        for (int i = 0; i < M; ++i) {
            int x;
            cin >> x;

            if (maxHeap.empty() || x <= maxHeap.top())
                maxHeap.push(x);
            else
                minHeap.push(x);

            // ���� ����
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // Ȧ�� ��° �Է� �� ���
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
