#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, K;
    cin >> N >> K;

    ll left = 1, right = K;
    ll answer = 0;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll count = 0;

        for (ll i = 1; i <= N; ++i)
            count += min(mid / i, N);  // i행에서 mid보다 작거나 같은 수의 개수

        if (count >= K) {
            answer = mid;
            right = mid - 1;  // 더 작은 값 중에서도 조건 만족하는지 탐색
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer << "\n";
    return 0;
}