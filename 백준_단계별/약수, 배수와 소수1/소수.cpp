#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;
    int Sum_prime = 0;
    int min_prime = 0;
    bool isprime = true;
    bool already_in = false;

    for (int i = M; i <= N; i++)
    {
        if (i == 1) continue;

        isprime = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isprime = false;
                break;
            }
        }

        if (isprime)
        {
            Sum_prime += i;
            if (!already_in)
            {
                min_prime = i;
                already_in = true;
            }
        }
        
    }
    if (already_in)
    {
        cout << Sum_prime << "\n" << min_prime << " ";
    }

    else
    {
        cout << -1 << "\n";
    }
    return 0;
}
