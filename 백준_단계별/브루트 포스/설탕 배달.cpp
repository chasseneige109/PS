#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int count = 0;

	if (N<=2 or N==4 or N==7)
	{
		cout << -1 << '\n';
		return 0;
	}

	while (true)
	{
		if (N >= 5)
		{
			N -= 5;
			count++;
		}
		else if (N >= 3)
		{
			N -= 3;
			count++;
		}
		else if (N >= 1)
		{
			N += 5;
			count--;
			N -= 3;
			count++;
		}
		else
		{
			break;
		}
	}
	cout << count << '\n';

	return 0;

}