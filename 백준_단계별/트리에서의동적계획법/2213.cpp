#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[10001];
int resident[10001];
int dp[10001][2];
vector<int> tree[10001];
vector<int> result;

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

void trace(int node, int parent, bool parentselected)
{
	//�θ� ���õǾ��ٸ�, node�� �������� �ʰ�, result�� pushback ���� �ʰ� �ѱ�.
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

	//�θ� ���õ��� �ʾҴٸ�,
	else
	{
		// ���� ��带 ���� �ϴ� ���� �̵��̶��,
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
		//���� ��� ���� ���ϴ� ���� �̵��̶��,
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