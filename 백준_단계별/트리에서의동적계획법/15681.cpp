#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;
vector<int> tree[MAX];
int dp[MAX];
bool visited[MAX];

// self included, return the number of subtree
int dfs(int node)
{
	visited[node] = true;
	dp[node] = 1;

	for (int next : tree[node])
	{
		if (!visited[next])
		{
			// add the next's number of subtree 
			dp[node] += dfs(next);
		}
	}

	// return the number of subtree
	return dp[node];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, R, Q;
	cin >> N >> R >> Q;

	for (int i = 0; i < N - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(R);

	while (Q--)
	{
		int query;
		cin >> query;
		cout << dp[query] << '\n';
	}

	return 0;
}