#include <iostream>
using namespace std;

int N, M;
int arr[7];

void dfs(int n)
{
    if (n == M)
    {
        for (int i = 0; i < M; ++i)
        {
            cout << arr[i] << " ";
        }
        return;
    }

    for (int i = 1; i <= N; ++i)
    {
        arr[n] = i;
        dfs(n + 1);
    }
}

int main()
{
    cin >> N >> M;
    dfs(0);
    return 0;
}