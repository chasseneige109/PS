#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(vector<int> vec, int min_dis)
{
    int last = 0;
    int s = vec.size();
    int count = 1;
    for (int i = 0; i < s; ++i)
    {
        if (vec[i] - vec[last] >= min_dis)
        {
            last = i;
            count++;
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, C;
    cin >> N >> C;

    vector<int> house(N);
    for (int i = 0; i < N; ++i) {
        cin >> house[i];
    }

    sort(house.begin(), house.end());

    int answer = 0;
    int left = 0;
    int right = house[N - 1] - house[0];
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (check(house, mid) >= C)
        {
            answer = mid;
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }
    cout << answer << "\n";
    return 0;
}

        
        

    