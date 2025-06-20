#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int board[20][20];
bool used[20];
int min_result = 1e9;



void match(int depth, int idx) 
{
	if (depth == N/2)
	{
		int start = 0;
		int link = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (used[i] && used[j]) start += board[i][j];
				else if (!used[i] && !used[j]) link += board[i][j];
			}
		}
		min_result = min(min_result, abs(start - link));
		return;
	}

	for (int i = idx; i < N; ++i) 
	{
		if (!used[i])
		{
			used[i] = true;
			match(depth + 1, i + 1);
			used[i] = false;
		}
	}
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int k;
			cin >> k;
			board[i][j] = k;
		}
	}
	match(0, 0);
	cout << min_result << '\n';
	return 0;
}