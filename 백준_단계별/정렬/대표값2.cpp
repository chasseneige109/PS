#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[5];
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int x;
		cin >> x;
		arr[i] = x;
		sum += x;
	}
	cout << sum / 5 << '\n';

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << arr[2] << '\n'; // 중간값 출력

	return 0;

}