#include <iostream>
#include <vector>
using namespace std;

const int MAX = 4000001;
bool is_prime[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 소수 구하기 (에라토스테네스의 체)
    for (int i = 2; i <= N; ++i)
        is_prime[i] = true;

    for (int i = 2; i * i <= N; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }

    // 소수 배열 생성
    vector<int> primes;
    for (int i = 2; i <= N; ++i)
    {
        if (is_prime[i])
            primes.push_back(i);
    }

    // 투 포인터로 연속합 찾기
    int left = 0, right = 0, cnt = 0, sum = 0;

    while (true)
    {
        if (sum >= N)
        {
            if (sum == N) cnt++;
            sum -= primes[left++];
        }
        else
        {
            if (right == primes.size()) break;
            sum += primes[right++];
        }
    }

    cout << cnt << "\n";
    return 0;
}
