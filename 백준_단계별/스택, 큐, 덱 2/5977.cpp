#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<ll> A(N + 1), psum(N + 1), dp(N + 1);
	psum[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        psum[i] = psum[i - 1] + A[i];
    }

    deque<int> dq;
    dp[0] = 0;
    dq.push_back(0);
    // dp[i] = psum[i] + max(dp[j - 1] - psum[j]) = psum[i] + max(C[j]) for j in range (i-k , i)

    for (int i = 1; i <= N; ++i)
    {
        while (!dq.empty() && dq.front() < i - K)
        {
            dq.pop_front();
        }

        if (i <= K)
        {
            dp[i] = psum[i];
        }
        else
            dp[i] = max(dp[i - 1], psum[i] + dp[dq.front() - 1] - psum[dq.front()]);

        
        while (!dq.empty() && (dp[i - 1] - psum[i]) >= (dp[dq.back() - 1] - psum[dq.back()]))
        {
            dq.pop_back();
        }
        
		dq.push_back(i);
    }

	ll max_value = 0;
    for (int i = 1; i <= N; ++i)
    {
        max_value = max(dp[i], max_value);
    }
    cout << max_value << "\n";
    return 0;
}
