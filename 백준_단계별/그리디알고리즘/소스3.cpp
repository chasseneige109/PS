#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
vector<vector<bool>> paper(128, vector<bool>(128));

void DQ(int x, int y, int length)
{
    if (length == 1)
    {
        cnt++;
        return;
    }
       

    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            if (paper[x][y] != paper[x + i][y + j])
            {
                DQ(x, y, length / 2);
                DQ(x + length / 2, y, length / 2);
                DQ(x, y + length / 2, length / 2);
                DQ(x + length / 2, y + length / 2, length / 2);
                return;
            }
        }
    }

    cnt++;
}
   

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int b;
            cin >> b;
            paper[i][j] = b;
        }
    }

    DQ(0, 0, N);

    cout << cnt << "\n";

    return 0;
}
    


