#include <iostream>
using namespace std;

int N, M;
bool used[9];
int arr[9];

void dfs(int n)
{
    if (n == M)
    {
        for (int i = 0; i < M; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }


    for (int i = 1; i <= N; ++i)
    {
        if (!used[i])
        {
            used[i] = true;
            arr[n] = i;
            dfs(n + 1);
            used[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    dfs(0);
    return 0;
}