#include <deque>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;

    deque<pair<int, int>> dq;  // {index, value}
    vector<int> result;
    result.reserve(N);

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        // 1) 윈도우 범위 벗어난 인덱스 제거
        while (!dq.empty() && dq.front().first <= i - L)
            dq.pop_front();

        // 2) 덱 내에서 더 크거나 같은 값들은 제거
        while (!dq.empty() && dq.back().second >= x)
            dq.pop_back();

        dq.emplace_back(i, x);

        // 3) 덱 앞의 값이 현재 최소값
        result.push_back(dq.front().second);
    }

    // 출력
    ostringstream oss;
    for (int v : result) {
        oss << v << ' ';
    }
    cout << oss.str();
    return 0;
}

