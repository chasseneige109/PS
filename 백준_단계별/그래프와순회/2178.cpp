#include <iostream>
#include <vector>
#include <queue>
#include <string> // 문자열 입력을 위해 추가
#include <algorithm> // 사용되지 않으므로 제거 가능 (원래 코드에 있었으니 일단 유지)
using namespace std;

// 전역 변수로 선언된 vector는 main 함수 내에서 resize/초기화 시켜야 합니다.
// 이때, 2차원 벡터는 행과 열 모두 크기를 지정해야 합니다.
vector<vector<int>> map_grid; // 'map'은 표준 라이브러리 map과 이름이 겹치므로 'map_grid'로 변경 (권장사항)
vector<vector<bool>> visited;

int main()
{
	// 입출력 속도 향상
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M; // N: 행 (세로), M: 열 (가로)
	cin >> N >> M;

	// *** 오류 수정 1: 2차원 벡터의 크기 올바르게 초기화 ***
	// N개의 행을 만들고, 각 행을 M개의 int/bool로 초기화합니다.
	map_grid.resize(N, vector<int>(M));
	visited.resize(N, vector<bool>(M, false)); // 모든 visited는 false로 초기화

	// 맵 입력 받기
	// 백준 2178번은 지도가 공백 없이 붙어있는 문자열로 주어지므로,
	// 한 줄을 string으로 받은 후 각 문자를 숫자로 변환해야 합니다.
	for (int i = 0; i < N; ++i)
	{
		string row_str; // 한 줄의 지도를 문자열로 받음
		cin >> row_str;
		for (int j = 0; j < M; ++j)
		{
			map_grid[i][j] = row_str[j] - '0'; // '0'을 빼서 char를 int로 변환
		}
	}

	// BFS 관련 변수 선언
	queue<pair<int, int>> q;
	// *** 오류 수정 2: 'cnt' 벡터의 크기 올바르게 초기화 ***
	// 거리를 저장할 벡터. N행 M열로 0 초기화.
	vector<vector<int>> cnt_dist(N, vector<int>(M, 0)); // 'cnt'는 전역변수와 겹치지 않게 'cnt_dist'로 변경

	// 시작점 (0,0)을 큐에 넣고 거리 및 방문 상태 초기화
	q.push({ 0,0 });
	cnt_dist[0][0] = 1;      // 시작점의 거리는 1
	visited[0][0] = true;    // *** 오류 수정 3: 시작점 방문 표시 누락 해결 ***

	// 상하좌우 이동을 위한 방향 배열
	int dx[4] = { -1, 1, 0, 0 }; // 행 (row) 변화량
	int dy[4] = { 0, 0, -1, 1 }; // 열 (col) 변화량

	// BFS 루프
	while (!q.empty())
	{
		// 'pair<int, int> curr;' 이 불필요한 선언은 제거했습니다.
		pair<int, int> curr_pos = q.front(); // 큐의 맨 앞 원소 가져오기
		q.pop(); // 큐에서 제거

		int cx = curr_pos.first;  // 현재 x 좌표 (행)
		int cy = curr_pos.second; // 현재 y 좌표 (열)

		// 4방향 탐색
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cx + dx[dir]; // 다음 x 좌표
			int ny = cy + dy[dir]; // 다음 y 좌표

			// 맵의 범위를 벗어나지 않는지 확인
			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				// 다음 칸이 아직 방문하지 않았고, 갈 수 있는 길(1)인 경우
				if (!visited[nx][ny] && map_grid[nx][ny] == 1)
				{
					visited[nx][ny] = true; // 다음 칸 방문 표시
					q.push({ nx, ny });       // 다음 칸을 큐에 추가
					// 다음 칸까지의 거리는 현재 칸까지의 거리 + 1
					cnt_dist[nx][ny] = cnt_dist[cx][cy] + 1;
				}
			}
		}
	}

	// 목적지 (N-1, M-1)까지의 최단 거리 출력
	cout << cnt_dist[N - 1][M - 1] << "\n";

	return 0;
}