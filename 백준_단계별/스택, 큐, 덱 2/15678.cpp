#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, D;
	cin >> N >> D;

	vector<ll> node(N + 1);
	vector<ll> dp(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		cin >> node[i];
		dp[i] = node[i];
	}

	deque<ll> dq;

	for (int i = 1; i <= N; ++i)
	{
		while (!dq.empty() && dq.front() < i - D)
		{
			dq.pop_front();
		}
		
		// 이전을 모두 고려하여 i번째를 선택하였을 때의 최대값 = max(이번노드가 첫시작, dq 가장 앞);	
		if (!dq.empty())
			dp[i] = max(dp[i], dp[dq.front()] + node[i]);
	
		while (!dq.empty() && dp[dq.back()] < dp[i])
		{
			dq.pop_back();
		}
		
		dq.emplace_back(i);
	}

	//dp 중 가장 큰 값
	ll max_result = numeric_limits<ll>::min();
	for (int i = 1; i <= N; ++i)
	{
		max_result = max(max_result, dp[i]);
	}

	cout << max_result << "\n";

	return 0;
}