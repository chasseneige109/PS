#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
vector<vector<pair<int, int>>> graph(100001, vector<pair<int, int>>());

pair<int,int> dfs(int start)
{
	vector<int> len(100001, -1);
	stack<int> s;
	int node = start;

	int max_dist = 0;
	s.push(start);
	len[start] = 0;

	while (!s.empty())
	{
		int curr = s.top();
		s.pop();

		for (auto& next : graph[curr])
		{
			//next의 좌표
			int to = next.first;
			//curr에서 next까지 거리
			int d = next.second;

			if (len[to] == -1)
			{
				len[to] = len[curr] + d;
				if (max_dist < len[to])
				{
					max_dist = len[to];
					node = to;
				}
				s.push(to);
			}
		}
	}

	return make_pair(node, max_dist);
}

int main() 
{
	int V;
	cin >> V;

	while (V--)
	{
		int n;
		cin >> n;
		while (true)
		{
			int a;
			cin >> a;
			if (a == -1) break;

			int b;
			cin >> b;
			graph[n].push_back({ a, b });
		}

	}

	pair<int,int> a = dfs(1);
	pair<int,int> b = dfs(a.first);
	cout << b.second << " ";
	return 0;
}