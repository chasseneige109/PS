#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;
const int INF = numeric_limits<int>::max();

int main() 
{
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> graph(n + 1);
	vector<int> pre(n + 1, -1);
	
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
	}

	int start, end;
	cin >> start >> end;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	vector<int> dist(n + 1, INF);

	//거리, 정점
	pq.emplace(0 , start);
	dist[start] = 0;

	while (!pq.empty())
	{
		int d = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (dist[curr] < d)
		{
			continue;
		}

		for (auto& p : graph[curr])
		{
			//  현재 1에서 p까지 VS 1에서 curr까지 + curr에서 p까지
			if (dist[p.first] > d + p.second)
			{
				dist[p.first] = d + p.second;
				pre[p.first] = curr;
				pq.emplace(dist[p.first], p.first);
			}
		}
	}
	vector<int> result;
	int now = end;
	while (true)
	{
		result.push_back(now);
		now = pre[now];
		
		if (now == -1)
			break;
	}

	reverse(result.begin(), result.end());
	cout << dist[end] << "\n";
	cout << result.size() << "\n";
	for (int x : result)
	{
		cout << x << " ";
	}

	cout << "\n";
	return 0;
}