#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long C;
vector<long long> arr;

vector<long long> get_subset_sums(int start, int end)
{
    vector<long long> sums;
    int size = end - start;
    for (int i = 0; i < (1 << size); ++i)
    {
        long long sum = 0;
        for (int j = 0; j < size; ++j)
        {
            if (i & (1 << j))
                sum += arr[start + j];
        }
        if (sum <= C) // pruning
            sums.push_back(sum);
    }
    return sums;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C;
    arr.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    // 1. 왼쪽/오른쪽 절반 나누기
    vector<long long> left_sums = get_subset_sums(0, N / 2);
    vector<long long> right_sums = get_subset_sums(N / 2, N);

    // 2. 오른쪽 정렬
    sort(right_sums.begin(), right_sums.end());

    // 3. left의 각 원소마다 right에서 C - left[i] 이하인 개수 찾기
    long long result = 0;
    for (auto left_val : left_sums)
    {
        long long remain = C - left_val;
        result += upper_bound(right_sums.begin(), right_sums.end(), remain) - right_sums.begin();
    }

    cout << result << "\n";
    return 0;
}
