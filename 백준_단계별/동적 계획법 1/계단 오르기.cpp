#include <iostream>
#include <algorithm>
using namespace std;

int stair[300];
int dp[300][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> stair[i];
	}

	dp[0][0] = stair[0];
	dp[0][1] = stair[0];
	dp[1][0] = stair[1];
	dp[1][1] = stair[0] + stair[1];
	// dp[i][0] = 2Ä­ Á¡ÇÁÇÏ±â
	// dp[i][1] = 1+1Ä­ Á¡ÇÁÇÏ±â

	for (int i = 0; i < N - 1; ++i)
	{
		dp[i + 2][0] = max(dp[i][0], dp[i][1]) + stair[i + 2];
		dp[i + 2][1] = dp[i + 1][0] + stair[i + 2];
	}

	int result = max(dp[N - 1][0], dp[N - 1][1]);
	cout << result << '\n';

	return 0;
}
	
