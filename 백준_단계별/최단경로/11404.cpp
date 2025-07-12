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

	// 자기 자신으로 가는 비용은 0
	for (int i = 1; i <= n; ++i)
		graph[i][i] = 0;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c); // 중복 간선 있을 수 있음
	}

	// 플로이드 워셜
	for (int i = 1; i <= n; ++i) // i를 거쳐갈 때,
	{
		for (int j = 1; j <= n; ++j) // j에서
		{
			for (int k = 1; k <= n; ++k) // k까지
			{
				if (graph[j][i] != INF && graph[i][k] != INF)
					graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}

	// 출력
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
