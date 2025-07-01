#include <iostream>
#include <vector>
using namespace std;

int lowerBound(const vector<int>& vec, int n)
{
    int left = 0;
    int right = vec.size() - 1;
    int result = vec.size();

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vec[mid] >= n)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector<int> LIS;
    LIS.push_back(A[0]);

    for (int i = 1; i < N; ++i)
    {
        if (A[i] >= LIS.back())
        {
            LIS.push_back(A[i]);
        }
        else
        {
            int idx = lowerBound(LIS, A[i]);
            LIS[idx] = A[i];
        }
    }

    cout << LIS.size() << "\n";
    return 0;
}
