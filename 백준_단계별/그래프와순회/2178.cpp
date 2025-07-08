#include <iostream>
#include <vector>
#include <queue>
#include <string> // ���ڿ� �Է��� ���� �߰�
#include <algorithm> // ������ �����Ƿ� ���� ���� (���� �ڵ忡 �־����� �ϴ� ����)
using namespace std;

// ���� ������ ����� vector�� main �Լ� ������ resize/�ʱ�ȭ ���Ѿ� �մϴ�.
// �̶�, 2���� ���ʹ� ��� �� ��� ũ�⸦ �����ؾ� �մϴ�.
vector<vector<int>> map_grid; // 'map'�� ǥ�� ���̺귯�� map�� �̸��� ��ġ�Ƿ� 'map_grid'�� ���� (�������)
vector<vector<bool>> visited;

int main()
{
	// ����� �ӵ� ���
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M; // N: �� (����), M: �� (����)
	cin >> N >> M;

	// *** ���� ���� 1: 2���� ������ ũ�� �ùٸ��� �ʱ�ȭ ***
	// N���� ���� �����, �� ���� M���� int/bool�� �ʱ�ȭ�մϴ�.
	map_grid.resize(N, vector<int>(M));
	visited.resize(N, vector<bool>(M, false)); // ��� visited�� false�� �ʱ�ȭ

	// �� �Է� �ޱ�
	// ���� 2178���� ������ ���� ���� �پ��ִ� ���ڿ��� �־����Ƿ�,
	// �� ���� string���� ���� �� �� ���ڸ� ���ڷ� ��ȯ�ؾ� �մϴ�.
	for (int i = 0; i < N; ++i)
	{
		string row_str; // �� ���� ������ ���ڿ��� ����
		cin >> row_str;
		for (int j = 0; j < M; ++j)
		{
			map_grid[i][j] = row_str[j] - '0'; // '0'�� ���� char�� int�� ��ȯ
		}
	}

	// BFS ���� ���� ����
	queue<pair<int, int>> q;
	// *** ���� ���� 2: 'cnt' ������ ũ�� �ùٸ��� �ʱ�ȭ ***
	// �Ÿ��� ������ ����. N�� M���� 0 �ʱ�ȭ.
	vector<vector<int>> cnt_dist(N, vector<int>(M, 0)); // 'cnt'�� ���������� ��ġ�� �ʰ� 'cnt_dist'�� ����

	// ������ (0,0)�� ť�� �ְ� �Ÿ� �� �湮 ���� �ʱ�ȭ
	q.push({ 0,0 });
	cnt_dist[0][0] = 1;      // �������� �Ÿ��� 1
	visited[0][0] = true;    // *** ���� ���� 3: ������ �湮 ǥ�� ���� �ذ� ***

	// �����¿� �̵��� ���� ���� �迭
	int dx[4] = { -1, 1, 0, 0 }; // �� (row) ��ȭ��
	int dy[4] = { 0, 0, -1, 1 }; // �� (col) ��ȭ��

	// BFS ����
	while (!q.empty())
	{
		// 'pair<int, int> curr;' �� ���ʿ��� ������ �����߽��ϴ�.
		pair<int, int> curr_pos = q.front(); // ť�� �� �� ���� ��������
		q.pop(); // ť���� ����

		int cx = curr_pos.first;  // ���� x ��ǥ (��)
		int cy = curr_pos.second; // ���� y ��ǥ (��)

		// 4���� Ž��
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cx + dx[dir]; // ���� x ��ǥ
			int ny = cy + dy[dir]; // ���� y ��ǥ

			// ���� ������ ����� �ʴ��� Ȯ��
			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				// ���� ĭ�� ���� �湮���� �ʾҰ�, �� �� �ִ� ��(1)�� ���
				if (!visited[nx][ny] && map_grid[nx][ny] == 1)
				{
					visited[nx][ny] = true; // ���� ĭ �湮 ǥ��
					q.push({ nx, ny });       // ���� ĭ�� ť�� �߰�
					// ���� ĭ������ �Ÿ��� ���� ĭ������ �Ÿ� + 1
					cnt_dist[nx][ny] = cnt_dist[cx][cy] + 1;
				}
			}
		}
	}

	// ������ (N-1, M-1)������ �ִ� �Ÿ� ���
	cout << cnt_dist[N - 1][M - 1] << "\n";

	return 0;
}