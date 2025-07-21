#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[10001];
int resident[10001];
int dp[10001][2];
vector<int> tree[10001];

//dfs�� dp[node]�� �ֽ�ȭ�ϴ� �Լ�.
void dfs(int node)
{
	
	dp[node][0] = 0; // �̹� �� �ȸ���
	dp[node][1] = resident[node]; // ����
	visited[node] = true;

	for (int next : tree[node])
	{
		if (!visited[next])
		{
			// dfs(next)�� ���� dp[next]�� �ֽ�ȭ�ϰ�, dp[node]�� �ֽ�ȭ. --> �߻�ȭ�� �߿伺
			dfs(next);
			dp[node][0] += max(dp[next][0], dp[next][1]);
			dp[node][1] += dp[next][0];
		}
	}
}

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
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

	cout << max(dp[1][1], dp[1][0]) << "\n";

	return 0;
	
}