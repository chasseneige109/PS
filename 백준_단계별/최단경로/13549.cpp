#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
const int INF = numeric_limits<int>::max();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> dist(100001, INF);
    dist[N] = 0;

    pq.push(N);

    while (!pq.empty())
    {
        int curr = pq.top();
        pq.pop();

        if (dist[curr + 1] > dist[curr] + 1 && curr + 1 <= 100000)
        {
            dist[curr + 1] = dist[curr] + 1;
            pq.push(curr + 1);
        }

        if (curr - 1 >= 0 && dist[curr - 1] > dist[curr] + 1)
        {
            dist[curr - 1] = dist[curr] + 1;
            pq.push(curr - 1);
        }
        if (curr * 2 <= 100000 && dist[curr * 2] > dist[curr])
        {
            dist[curr * 2] = dist[curr];
            pq.push(curr * 2);
        }

    }

    cout << dist[K] << '\n';
    return 0;

}

