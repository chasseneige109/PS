#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> mass(N + 1);

    for (int i = 0; i < N; ++i)
    {
        cin >> mass[i];
    }

    int M;
    cin >> M;

    vector<int> bead(M + 1);

    for (int i = 0; i < M; ++i)
    {
        cin >> bead[i];
    }

    unordered_set<int> dp;
    dp.insert(0);
    dp.insert(mass[0]);

    for (int i = 1; i < N; ++i)
    {
		unordered_set<int> copy_dp = dp;
        for (int a : copy_dp)
        {
			if (a - mass[i] >= 0)
                dp.insert(a - mass[i]);
                dp.insert(abs(a + mass[i]));
        }
    }

    for (int i = 0; i < M; ++i)
    {
        if (dp.find(bead[i]) != dp.end())
        {
            cout << "Y ";
        }
        else
        {
            cout << "N ";
        }
    }
    cout << '\n';
    return 0;
}