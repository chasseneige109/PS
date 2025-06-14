#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> types(N);
    for (int i = 0; i < N; ++i)
        cin >> types[i];

    deque<int> dq;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (types[i] == 0)  // 큐일 때만 deque에 보관
            dq.push_back(x);
    }

    int M;
    cin >> M;
    while (M--) {
        int c;
        cin >> c;
        dq.push_front(c);        // 새 값은 제일 마지막 자료구조부터 들어가니까 앞에 넣음
        cout << dq.back() << " "; // 마지막에 나오는 값은 dq의 back
        dq.pop_back();
    }

    return 0;
}
