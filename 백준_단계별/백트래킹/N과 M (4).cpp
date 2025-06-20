#include <iostream>
using namespace std;

int N, M;
bool used[9];
int arr[9] = { -1 };

void dfs(int n, int start)
{
    if (n == M)
    {
        for (int i = 0; i < M; ++i)
        {
            cout << arr[i] << " ";
        }
        return;
    }

    for (int i = start; i <= N; ++i)
    {
        arr[n] = i;
        dfs(n + 1, i);
    }
}

int main()
{
    cin >> N >> M;
    dfs(0, 1);
    return 0;
}