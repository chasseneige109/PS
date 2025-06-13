#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 소수 배열 만들기
    vector<bool> is_prime(MAX + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // 테스트 케이스 입력
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int count = 0;
        for (int a = 2; a <= N / 2; ++a) {
            int b = N - a;
            if (is_prime[a] && is_prime[b])
                ++count;
        }
        cout << count << '\n';
    }

    return 0;
}
