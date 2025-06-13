#include <iostream>
using namespace std;

bool is_prime(long long x) {
    if (x < 2) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (long long i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    int N;
    cin >> N;
    for (int n = 0; n < N; ++n) {
        for (int i = N; i <= 2 * N; ++i) {
            if (is_prime(i))
            {
                count++;
            }
        }
    }
    cout << count << '\n';
    return 0;
}