#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXW = 1000;
int N, W;
vector<pair<int, int>> events;
int dp[MAXW + 2][MAXW + 2];
int trace[MAXW + 2][MAXW + 2];

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int i, int j) {
    if (i == W || j == W) return 0;
    int& ret = dp[i][j];
    if (ret != -1) return ret;

    int nxt = max(i, j) + 1;
    int d1 = dist((i == 0 ? make_pair(1, 1) : events[i]),
        events[nxt]);
    int d2 = dist((j == 0 ? make_pair(N, N) : events[j]),
        events[nxt]);
    if (solve(nxt, j) + d1 < solve(i, nxt) + d2) {
        trace[i][j] = 1;
        ret = solve(nxt, j) + d1;
    }
    else {
        trace[i][j] = 2;
        ret = solve(i, nxt) + d2;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> W;
    events.resize(W + 1);
    for (int i = 1; i <= W; i++)
        cin >> events[i].first >> events[i].second;

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0) << "\n";

    int i = 0, j = 0;
    for (int k = 1; k <= W; ++k) {
        int who = trace[i][j];
        cout << who << "\n";
        if (who == 1) i = k;
        else j = k;
    }
    return 0;
}
