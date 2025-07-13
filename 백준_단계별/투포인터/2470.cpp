#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long arr[100000];

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int left = 0;
	int right = N - 1;
	
	long long min_abs = 2e9 + 1;
	int best_l = left, best_r = right;

	while (left < right)
	{
		long long sum = arr[left] + arr[right];
		long long abs_sum = abs(sum);

		if (abs_sum < min_abs)
		{
			min_abs = abs_sum;
			best_l = left;
			best_r = right;
		}

		if (sum < 0)
			left++;
		else
			right--;
	}

	cout << arr[best_l] << " " << arr[best_r] << "\n";
	return 0;
}
