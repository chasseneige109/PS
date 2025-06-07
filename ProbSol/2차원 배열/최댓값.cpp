#include <iostream>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a[9][9];
    int imax = 0;
    int maxindex_i = 0;
    int maxindex_j = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> a[i][j];
            if (a[i][j] > imax)
            {
                imax = a[i][j];
                maxindex_i = i;
                maxindex_j = j;
            }
        }
    }

    cout << imax << '\n' << maxindex_i + 1 << ' ' << maxindex_j + 1 << '\n';
    return 0;
}

