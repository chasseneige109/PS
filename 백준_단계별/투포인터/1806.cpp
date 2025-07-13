#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
long long prefix[100001];  // prefix[0] = 0, prefix[i] = arr[0] + ... + arr[i-1]

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long S;
    cin >> N >> S;

    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    prefix[0] = 0;
    for (int i = 1; i <= N; ++i)
        prefix[i] = prefix[i - 1] + arr[i - 1];

    int result = N + 1;
    int left = 0, right = 1;

    while (left <= N)
    {
        while (right <= N && prefix[right] - prefix[left] < S)
        {
            ++right;
        }

        if (right > N) break;

        result = min(result, right - left);
        ++left;
    }

    if (result == N + 1)
        cout << 0 << "\n";
    else
        cout << result << "\n";

    return 0;
}
