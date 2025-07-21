#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
vector<vector<int>> dp;
int k;

// node가 root 일 때 필요한 얼리어답터 수
void dfs(int node)
{
	dp[node][0] = 0;
	dp[node][1] = 1;
	visited[node] = true;

	for (int next : tree[node])
	{
		if (!visited[next])
		{
			dfs(next);
			dp[node][0] += dp[next][1];
			dp[node][1] += min(dp[next][0], dp[next][1]);
		}
	}
}

int main()
{
	int N;
	cin >> N;

	tree.resize(N + 1);
	for (int i = 1; i <= N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	dp.resize(N + 1, vector<int>(2));
	visited.resize(N + 1);
	dfs(1);

	cout << min(dp[1][1], dp[1][0]) << "\n";

	return 0;
}
	