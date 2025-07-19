#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

// 다리 구조체 생성
struct Bridge
{
	int u, v, w;

	bool operator< (const Bridge& other) const
	{
		return w < other.w;
	}
};

vector<vector<pair<int, int>>> islands;
vector<vector<bool>> visited;
vector<vector<int>> board;
vector<int> parent;
vector<int> rnk;
int N, M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// island 만들기 (BFS)
void make_island(pair<int,int> p, vector<pair<int,int>>& island)
{
	queue<pair<int, int>> q;

	// queue 시작 조건
	int py = p.first;
	int px = p.second;
	q.push(make_pair(py, px));
	visited[py][px] = true;

	// queue로 상하좌우 BFS 탐색
	while (!q.empty())
	{
		pair<int,int> curr = q.front(); q.pop();
		int cy = curr.first;
		int cx = curr.second;
		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (nx >= M || nx < 0 || ny >= N || ny < 0)
				continue;

			if (!visited[ny][nx] && board[ny][nx] == 1)
			{
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
				island.push_back(make_pair(ny, nx));
			}
		}
	}
}

// dist 함수에서 다리 건설 가능 여부 
bool check_path_y(int c1, int c2, int cx)
{
	int dy = (c2 > c1) ? 1 : -1;
	for (int y = c1 + dy; y != c2; y += dy)
	{
		if (visited[y][cx])
			return false;
	}
	return true;
}

// dist 함수에서 다리 건설 가능 여부
bool check_path_x(int c1, int c2, int cy)
{
	int dx = (c2 > c1) ? 1 : -1;
	for (int x = c1 + dx; x != c2; x += dx)
	{
		if (visited[cy][x])
			return false;
	}
	return true;
}


// island 끼리의 거리 구하기 (Brute Force)
int dist(vector<pair<int, int>> island1, vector<pair<int, int>> island2)
{
	int min_d = 100;
	for (auto& p1 : island1)
	{
		for (auto& p2 : island2)
		{
			const int& p1y = p1.first, & p1x = p1.second;
			const int& p2y = p2.first, & p2x = p2.second;

			if (p1x == p2x)
			{
				if (!check_path_y(p1y, p2y, p1x))
					continue;
				
				int d = abs(p1y - p2y) - 1;
				if (d <= 1)
					continue;
				min_d = min(min_d, d);
			}

			else if (p1y == p2y)
			{
				if (!check_path_x(p1x, p2x, p1y))
					continue;

				int d = abs(p1x - p2x) - 1;

				if (d <= 1)
					continue;
				min_d = min(min_d, d);
			}
		}
	}

	return min_d;
}

//Union find의 find 함수
int find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}

bool uni(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
		return false;
	
	if (rnk[a] > rnk[b])
		parent[b] = a;
	else
	{
		parent[a] = b;
		if (rnk[a] == rnk[b])
			rnk[b]++;
	}

	return true;
}

int main()
{
	cin >> N >> M;

	board.resize(N, vector<int>(M));
	visited.resize(N, vector<bool>(M));

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cin >> board[y][x];
		}
	}

	// island 1개씩 만들고 islands에 추가하기
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (!visited[y][x] && board[y][x] == 1)
			{
				islands.push_back({ { y, x } });
				make_island(make_pair(y, x), islands.back());
			}
		}
	}

	// 가능한 모든 다리 입력 후 짧은 순 정렬
	vector<Bridge> bridges;
	int n = islands.size();

	for (int i = 0; i < n; ++i) 
	{
		for (int j = i + 1; j < n; ++j) 
		{
			auto& island1 = islands[i];
			auto& island2 = islands[j];
			
			int d = dist(island1, island2);
			if (d == 100)
				continue;
			else
			{
				//i번째 bri와 j번째 bri를 잇는 d짜리 다리
				bridges.push_back({ i, j, d });
			}
		}
	}
	//짧은 순 정렬
	sort(bridges.begin(), bridges.end());

	//현재 bridges vector에는 bn개 만큼의 가능한 bridge가 있음.
	
	//Union find
	int bn = bridges.size();
	int total = 0;
	parent.resize(n);

	for (int i = 0; i < n; ++i)
	{
		parent[i] = i;
	}

	rnk.resize(n , 0);

	int brig_count = 0;
	for (int i = 0; i < bn; ++i)
	{
		if (uni(bridges[i].u, bridges[i].v))
		{
			total += bridges[i].w;
			brig_count++;
		}

		if (brig_count == n - 1)
		{
			cout << total << "\n";
			return 0;
		}
	}

	cout << -1 << "\n";
	return 0;
}