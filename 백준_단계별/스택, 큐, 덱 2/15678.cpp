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
		
		// ������ ��� ����Ͽ� i��°�� �����Ͽ��� ���� �ִ밪 = max(�̹���尡 ù����, dq ���� ��);	
		if (!dq.empty())
			dp[i] = max(dp[i], dp[dq.front()] + node[i]);
	
		while (!dq.empty() && dp[dq.back()] < dp[i])
		{
			dq.pop_back();
		}
		
		dq.emplace_back(i);
	}

	//dp �� ���� ū ��
	ll max_result = numeric_limits<ll>::min();
	for (int i = 1; i <= N; ++i)
	{
		max_result = max(max_result, dp[i]);
	}

	cout << max_result << "\n";

	return 0;
}