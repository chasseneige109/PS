#include <iostream>
using namespace std;

int dp[10001];

int main()
{
	int n, k;
	cin >> n >> k;

	dp[0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		int coin;
		cin >> coin;
		for (int j = coin; j <= k; ++j)
		{
			dp[j] += dp[j - coin];
		}
	}

	cout << dp[k] << "\n";

	return 0;
}