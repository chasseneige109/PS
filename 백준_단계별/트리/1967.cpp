#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> len;

pair<int, int> DFS(int start)
{
	stack<int> s;
	len[start] = 0;
	s.push(start);
	int max_dist = 0;
	int max_node = start;

	while (!s.empty())
	{
		int curr = s.top(); s.pop();

		for (auto& p : graph[curr])
		{
			int next = p.first;
			int d = p.second;

			if (len[next] == -1)
			{
				len[next] = len[curr] + d;
				s.push(next);
				if (max_dist < len[next])
				{
					max_dist = len[next];
					max_node = next;
				}
			}
		}
	}

	return { max_node, max_dist };
}

int main()
{
	int n;
	cin >> n;

	graph.resize(n + 1);
	len.resize(n + 1, -1);

	for (int i = 0; i < n - 1; ++i)
	{
		int parent, child, weight;
		cin >> parent >> child >> weight;

		graph[parent].push_back({ child, weight });
		graph[child].push_back({ parent, weight });  //  무방향 연결 추가
	}

	int end_node = DFS(1).first;

	fill(len.begin(), len.end(), -1);  //  거리 배열 초기화

	cout << DFS(end_node).second << "\n";

	return 0;
}
