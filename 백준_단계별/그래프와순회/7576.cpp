#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
vector<vector<int>> tomato;

int dx[] = { 1, 0, -1 , 0 };
int dy[] = { 0, 1, 0, -1 };

int cnt = 0;

void bfs(int n, int m)
{

	while (!q.empty())
	{	
		queue<pair<int, int>> q_copy = q;
		while (!q_copy.empty())
		{
			pair<int, int> curr = q_copy.front();
			q.pop();
			q_copy.pop();

			int cx = curr.first;
			int cy = curr.second;
			for (int dir = 0; dir < 4; ++dir)
			{
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					if (tomato[nx][ny] == 0)
					{
						tomato[nx][ny] = 1;
						q.push(pair<int, int>{nx, ny});
					}
				}
			}
		}
		cnt++;
	}
}

int main()
{

	int M, N;
	cin >> M >> N;

	tomato.resize(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> tomato[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (tomato[i][j] == 1)
			{
				q.push(pair<int, int>{i, j});
			}
		}
	}

	bfs(N, M);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (tomato[i][j] == 0)
			{
				cout << -1 << "\n";
				return 0;
			}
		}
	}
	
	cout << cnt - 1 << "\n";
	return 0;
}