#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> block(N);
    for (int i = 0; i < N; ++i) {
        cin >> block[i];
    }

    stack<int> s;
    long long answer = 0;

    for (int i = 0; i <= N; ++i) {
        long long current_height = (i == N) ? 0 : block[i];

        while (!s.empty() && block[s.top()] > current_height) {
            int h = block[s.top()];
            s.pop();

            long long w;
            if (s.empty()) {
                w = i;
            }
            else {
                w = i - s.top() - 1;
            }
            answer = max(answer, h * w);
        }
        s.push(i);
    }

    cout << answer << "\n";

    return 0;
}