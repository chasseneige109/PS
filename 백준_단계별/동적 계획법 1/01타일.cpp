#include <iostream>
using namespace std;

int dp[1000000];
const int MOD = 15746;

int tile (int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (dp[n] != 0) return dp[n];
	return dp[n] = (tile(n - 1) +  tile(n - 2))% MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	cout << tile(N) % 15746 << "\n";
	return 0;
}