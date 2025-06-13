#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, k;
	cin >> N >> k;
	int arr[N];
	for (int k = 0; k < N; k++)
	{
		int x;
		cin >> x;
		arr[k] = x;
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << arr[k - 1] << '\n'; // k번째 작은 수 출력


	return 0;
}