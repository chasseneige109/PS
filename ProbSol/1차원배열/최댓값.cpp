#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[9];

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}

	int maxIndex = 0;
	int maxValue = arr[0];
	for (int i = 0; i < 9; i++)
	{
		if (arr[i] > maxValue)
		{
			maxValue = arr[i];
			maxIndex = i;
		}
	}
	cout << maxValue << "\n" << maxIndex + 1 << "\n";

	return 0;
}

