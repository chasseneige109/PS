#include <iostream>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int MAX = 4000000;

ll fact[MAX + 1];

// ���� ���� (a^b % MOD)
ll power(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    // 1. ���丮�� ���̺� �����
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    // 2. ���� = n!
    ll numerator = fact[n];

    // 3. �и� = k! * (n-k)!
    ll denominator = fact[k] * fact[n - k] % MOD;

    // 4. ��ⷯ �������� �����ֱ�
    ll result = numerator * power(denominator, MOD - 2) % MOD;

    cout << result << '\n';
    return 0;
}
