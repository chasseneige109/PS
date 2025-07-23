#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> result(N);

	int left = 0;
	int right = N - 1;
	int q = 1;
	int cnt = 0;
	while(cnt != N)
	{
		if (q % 2 == 0)
		{
			result[right] = q;
			right--;
			q++;
			cnt++;
		}

		
		if (q % 2 == 1)
		{
			result[left] = q;
			left++;
			q++;
			cnt++;
		}
	}

	for (int x : result)
	{
		cout << x << " ";
	}

	return 0;
}