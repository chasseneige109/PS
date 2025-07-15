#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BS(const vector<int>& vec, int element)
{
    int left = 0;
    int right = vec.size() - 1;
    int answer = vec.size();
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (vec[mid] >= element)
        {
            right = mid - 1;
            answer = mid;
        }

        else if (vec[mid] < element)
        {
            left = mid + 1;
        }
    }

    return answer;
}

int main() {
    int N;
    cin >> N;

    vector<int> answer;
    vector<int> dp(N);
    vector<int> arr(N);
    vector<int> tracker;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    tracker.push_back(arr[0]);

    for (int i = 1; i < N; ++i)
    {
        if (tracker.back() < arr[i])
        {
            tracker.push_back(arr[i]);
            dp[i] = tracker.size() - 1;
        }

        else
        {
            //arr[i]가 it 단계이다.
            auto it = BS(tracker, arr[i]);
            tracker[it] = arr[i];
            dp[i] = it;
        }
    }

    int idx = tracker.size() - 1;
    for (int i = N - 1; i >= 0; --i)
    {
        if (dp[i] == idx)
        {
            answer.push_back(arr[i]);
            idx--;
        }
    }

    reverse(answer.begin(), answer.end());
    cout << tracker.size() << "\n";
    for (int x : answer)
    {
        cout << x << " ";
    }

    return 0;
}

        