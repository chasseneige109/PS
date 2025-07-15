#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int D(int d) {
    return (2 * d) % 10000;
}

int S(int s) {
    if (s == 0) return 9999;
    return s - 1;
}

int L(int l) {
    return (l % 1000) * 10 + (l / 1000);
}

int R(int r) {
    return (r % 10) * 1000 + (r / 10);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        queue<int> q;
        vector<bool> visited(10000, false);
        vector<pair<int, char>> tracker(10000, {-1, 0});

        visited[A] = true;
        q.push(A);

        while (!q.empty()) {
            int curr = q.front(); q.pop();

            if (curr == B) break;

            //구조 분해 할당
            for (auto [next, op] : {
                make_pair(D(curr), 'D'),
                make_pair(S(curr), 'S'),
                make_pair(L(curr), 'L'),
                make_pair(R(curr), 'R')
            }) {
                if (!visited[next]) {
                    visited[next] = true;
                    tracker[next] = {curr, op};
                    q.push(next);
                }
            }
        }

        vector<char> result;
        int now = B;
        while (now != A) {
            result.push_back(tracker[now].second);
            now = tracker[now].first;
        }

        reverse(result.begin(), result.end());
        for (char c : result) cout << c;
        cout << "\n";
    }

    return 0;
}
