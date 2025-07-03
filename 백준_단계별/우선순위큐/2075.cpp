#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < N * N; ++i) {
        int x;
        cin >> x;

        if (minHeap.size() < N) {
            minHeap.push(x);
        }
        else if (x > minHeap.top()) {
            minHeap.pop();
            minHeap.push(x);
        }
    }

    cout << minHeap.top() << '\n';

    return 0;
}
