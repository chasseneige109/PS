#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, X;
	cin >> N >> X;

	int arr[N];
	for (int i = 0; i < N; i++) 
	{
		cin >> arr[i];
	}

	for (int j = 0; j < N; j++)
	{
		if (arr[j] < X)
		{
			cout << arr[j] << " ";
		}
	}

	return 0;
}