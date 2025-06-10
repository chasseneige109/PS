#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

inline int color(char c)
{
	return c == 'W' ? 0 : 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = color(row[j]);
		}
	}

	int count_1 = 0;
	int count_0 = 0;

	int minpaint = 64; // 최대 칠해야 하는 칸 수는 64칸

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			bool manual = 0;
			int count_0 = 0;
			int count_1 = 0;
			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					if (board[i + x][j + y] != manual) count_0++;
					else count_1++;
					manual = !(manual);
				}
				manual = !(manual); // 다음 줄은 반전된 색으로 시작
			}
			minpaint = min(minpaint, min(count_0, count_1));
		}
	}


	cout << minpaint << '\n';

	return 0;
}
			