#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) return a > b;  // 절댓값 같으면 더 작은 수 먼저
        return abs(a) > abs(b);              // 절댓값 작은 수 먼저
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, cmp> pq;

    while (N--) {
        int x;
        cin >> x;
        if (x == 0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }

    return 0;
}
