#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
const int INF = numeric_limits<int>::max();

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

	// �ڱ� �ڽ����� ���� ����� 0
	for (int i = 1; i <= n; ++i)
		graph[i][i] = 0;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c); // �ߺ� ���� ���� �� ����
	}

	// �÷��̵� ����
	for (int i = 1; i <= n; ++i) // i�� ���İ� ��,
	{
		for (int j = 1; j <= n; ++j) // j����
		{
			for (int k = 1; k <= n; ++k) // k����
			{
				if (graph[j][i] != INF && graph[i][k] != INF)
					graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}

	// ���
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (graph[i][j] == INF) cout << "0 ";
			else cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
