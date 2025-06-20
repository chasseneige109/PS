#include <iostream>
using namespace std;

int board[9][9];

bool is_valid(int row, int col, int num)
{
	for (int i = 0; i < 9; ++i)
	{
		if (board[row][i] == num || board[i][col] == num)
			return false;
	}

	int x_start = (row / 3) * 3;
	int y_start = (col / 3) * 3;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (board[x_start + i][y_start + j] == num)
			{
				return false;
			}
		}
	}

	return true;
}

bool sdoq()
{
	for (int row = 0; row < 9; ++row)
	{
		for (int col = 0; col < 9; ++col)
		{
			if (board[row][col] == 0)
			{
				for (int num = 1; num <= 9; ++num)
				{
					if (is_valid(row, col, num))
					{
						board[row][col] = num;
						if (sdoq()) return true;
						board[row][col] = 0;
						
					}
				}
				return false;
			}
		}
	}
	return true;
}

int main() {
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			cin >> board[i][j];

	sdoq();

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j)
			cout << board[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}