#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<vector<bool>> adj(N + 1, vector<bool>(N + 1));
        vector<int> indegree(N + 1, 0);
        vector<int> last(N + 1);  // 작년 순위

        for (int i = 1; i <= N; ++i) {
            cin >> last[i];
        }

        // 작년 순위 기반 간선 구성
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                int higher = last[i];
                int lower = last[j];
                adj[higher][lower] = true;
                indegree[lower]++;
            }
        }

        int M;
        cin >> M;
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;

            if (adj[a][b]) {
                adj[a][b] = false;
                adj[b][a] = true;
                indegree[b]--;
                indegree[a]++;
            }
            else {
                adj[b][a] = false;
                adj[a][b] = true;
                indegree[a]--;
                indegree[b]++;
            }
        }

        // 위상 정렬
        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> result;
        bool ambiguous = false;
        bool impossible = false;

        for (int i = 0; i < N; ++i) {
            if (q.empty()) {
                impossible = true;
                break;
            }

            if (q.size() > 1) {
                ambiguous = true;
            }

            int curr = q.front(); q.pop();
            result.push_back(curr);

            for (int next = 1; next <= N; ++next) {
                if (adj[curr][next]) {
                    indegree[next]--;
                    if (indegree[next] == 0) {
                        q.push(next);
                    }
                }
            }
        }

        if (impossible) {
            cout << "IMPOSSIBLE\n";
        }
        else if (ambiguous) {
            cout << "?\n";
        }
        else {
            for (int x : result) cout << x << " ";
            cout << '\n';
        }
    }
    return 0;
}
