#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[10001];
int resident[10001];
int dp[10001][2];
vector<int> tree[10001];
vector<int> result;

//dfs는 dp[node]를 최신화하는 함수.
void dfs(int node)
{

	dp[node][0] = 0; // 이번 꺼 안마심
	dp[node][1] = resident[node]; // 마심
	visited[node] = true;

	for (int next : tree[node])
	{
		if (!visited[next])
		{
			// dfs(next)를 통해 dp[next]를 최신화하고, dp[node]를 최신화. --> 추상화의 중요성
			dfs(next);
			dp[node][0] += max(dp[next][0], dp[next][1]);
			dp[node][1] += dp[next][0];
		}
	}
}

void trace(int node, int parent, bool parentselected)
{
	//부모가 선택되었다면, node는 선택하지 않고, result에 pushback 하지 않고 넘김.
	if (parentselected)
	{
		for (int next : tree[node])
		{
			if (next == parent)
				continue;
			else
				trace(next, node, false);
		}
	}

	//부모가 선택되지 않았다면,
	else
	{
		// 현재 노드를 선택 하는 것이 이득이라면,
		if (dp[node][1] > dp[node][0])
		{
			result.push_back(node);
			for (int next : tree[node])
			{
				if (next == parent)
					continue;
				else
				{
					trace(next, node, true);
				}
			}
		}
		//현재 노드 선택 안하는 것이 이득이라면,
		else
		{
			for (int next : tree[node])
			{
				if (next == parent)
					continue;
				else
				{
					trace(next, node, false);
				}
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N - 1; ++i)
	{
		cin >> resident[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);
	trace(1, 0, false);


	cout << max(dp[1][1], dp[1][0]) << "\n";
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << "\n";
	return 0;

}