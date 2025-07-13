#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[1000000];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> arr[i];
    }

    int x;
    cin >> x;

    sort(arr, arr+n);

    int* start = arr;
    int* end = arr + n - 1;
    int cnt = 0;

    while (start < end)
    {
        if (*start + *end > x)
        {
            end -= 1;
        }

        else if (*start + *end < x)
        {
            start += 1;
        }

        else
        {
            cnt += 1;
            start++;
            end--;
        }

    }
    cout << cnt << "\n";

    return 0;

}