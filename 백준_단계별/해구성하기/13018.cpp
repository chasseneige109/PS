#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	
	if (k == n)
	{
		cout << "Impossible" << '\n';
		return 0;
	}

	vector<int> result(n + 1);

	if (k == n - 1)
	{
		for (int i = 1; i <= n; ++i)
			result[i] = i;
	}
	
	else if (k == 0)
	{
		for (int i = 1; i <= n - 1; ++i)
		{
			result[i] = i + 1;
		}

		result[n] = 1;
	}

	else
	{
		for (int i = 1; i <= n - k - 1; ++i)
		{
			result[i] = i + 1;
		}

		result[n - k] = 1;

		for (int i = n - k + 1; i <= n; ++i)
		{
			result[i] = i;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << result[i] << " ";
	}

	cout << '\n';

	return 0;
}

