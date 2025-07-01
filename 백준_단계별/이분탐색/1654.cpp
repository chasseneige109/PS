#include <iostream>
using namespace std;
typedef long long ll;

ll cable[10001];
ll K, N;

bool possible(ll length)
{
    ll count = 0;
    for (int i = 0; i < K; ++i)
    {
        count += cable[i] / length;
    }
    return count >= N;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> K >> N;

    ll maxLength = 0;
    for (int i = 0; i < K; ++i)
    {
        cin >> cable[i];
        if (cable[i] > maxLength)
            maxLength = cable[i];
    }

    ll left = 1, right = maxLength;
    ll answer = 0;

    while (left <= right)
    {
        ll mid = (left + right) / 2;
        if (possible(mid))
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer << "\n";
    return 0;
}
