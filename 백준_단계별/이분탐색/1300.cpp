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
            count += min(mid / i, N);  // i�࿡�� mid���� �۰ų� ���� ���� ����

        if (count >= K) {
            answer = mid;
            right = mid - 1;  // �� ���� �� �߿����� ���� �����ϴ��� Ž��
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer << "\n";
    return 0;
}