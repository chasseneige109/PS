#include <iostream>
using namespace std;

long long dp[101]; // 최대 100까지 커버, long long 안 하면 오버플로우

long long helix(int n)
{
	if (n <= 3) return 1;
	if (n == 4 || n == 5) return 2;
	if (dp[n] != 0) return dp[n];
	return dp[n] = helix(n - 1) + helix(n - 5);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int k;
		cin >> k;
		cout << helix(k) << "\n";
	}
	return 0;
}
