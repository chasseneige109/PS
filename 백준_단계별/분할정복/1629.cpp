#include <iostream>
using namespace std;

typedef long long ll;

ll power(ll a, ll b, ll c) {
    if (b == 0) return 1;

    ll half = power(a, b / 2, c);
    ll result = (half * half) % c;

    if (b % 2 == 1) {
        result = (result * a) % c;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll A, B, C;
    cin >> A >> B >> C;

    cout << power(A, B, C) << "\n";
    return 0;
}
