#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    if (N == 1)
    {
        return 0;
	}

    for (int i = 2; i * i <= N; i++)
    {   
        if (N == 1)
        {
            break;
        }

        while (N % i == 0)
        {   
            cout << i << "\n";
		    N /= i;
            
        }
    }

    if (N > 1)
    {
        cout << N << "\n";
	}

    return 0;
}