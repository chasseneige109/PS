#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int arr[100];  // 최대 100개까지 저장 가능
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int v;
    cin >> v;

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == v) count++;
    }

    cout << count << "\n";

    return 0;
}
