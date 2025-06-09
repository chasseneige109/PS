#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		int isPrime = true;
		if (num < 2) continue;
		if (num == 2)
		{
			count++;
			continue;
		}
		for (int j = 2; j*j <= num; j++)
		{
			if (num % j == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			count++;
		}
	}
	cout << count << " ";
}