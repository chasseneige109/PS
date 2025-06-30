#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1'000'000'007;

typedef vector<vector<ll>> matrix;

// Çà·Ä °ö¼À
matrix multiply(matrix& a, matrix& b) {
    matrix result(2, vector<ll>(2));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
    return result;
}

// Çà·Ä °ÅµìÁ¦°ö
matrix power(matrix a, ll n) {
    if (n == 1) return a;
    matrix half = power(a, n / 2);
    matrix result = multiply(half, half);
    if (n % 2 == 1)
        result = multiply(result, a);
    return result;
}

int main() {
    ll n;
    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    matrix base = { {1, 1}, {1, 0} };
    matrix ans = power(base, n);
    cout << ans[0][1] << '\n';  // F(n)
    return 0;
}
