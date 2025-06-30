#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;
const int MOD = 1000;

// Çà·Ä °ö¼À
matrix multiply(matrix& a, matrix& b, int n) {
    matrix result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
    return result;
}

// Çà·Ä °ÅµìÁ¦°ö
matrix power(matrix a, long long b, int n) {
    if (b == 1) {
        // ¸ðµç ¿ø¼Ò¿¡ mod Àû¿ë
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                a[i][j] %= MOD;
        return a;
    }

    matrix half = power(a, b / 2, n);
    matrix result = multiply(half, half, n);

    if (b % 2 == 1)
        result = multiply(result, a, n);

    return result;
}

int main() {
    int n;
    long long b;
    cin >> n >> b;

    matrix A(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    matrix ans = power(A, b, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << ans[i][j] << " ";
        cout << '\n';
    }

    return 0;
}
