#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool>visited;
int cnt = 0;

void dfs(int node)
{
	if (!visited[node])
	{
		cnt++;
		visited[node] = true;
		for (int next : graph[node])
		{
			dfs(next);
		}
	}

	else
	{
		return;
	}
}

int main()
{
	int N, K;
	cin >> N >> K;


	graph.resize(N + 1);
	visited.resize(N + 1, 0);

	for (int i = 0; i < K; ++i)
	{
		int a, b;
		cin >> a;
		cin >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	dfs(1);

	cout << cnt - 1 << "\n";
}