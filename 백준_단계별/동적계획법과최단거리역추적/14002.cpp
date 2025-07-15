#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N, 1);
    vector<int> arr(N);
    vector<int> tracker(N, -1);

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                tracker[i] = j;
            }
        }
    }

    int curr = 0;
    for (int i = 0; i < N; ++i)
    {
        if (dp[i] > dp[curr])
        {
            curr = i;
        }
    }

    vector<int> result;

    cout << dp[curr] << "\n";

    while (tracker[curr] != -1)
    {
        result.push_back(arr[curr]);
        curr = tracker[curr];
    }

    cout << arr[curr] << " ";

    for (int i = result.size() - 1; i >= 0; --i)
    {
        cout << result[i] << " ";
    }

    return 0;
}