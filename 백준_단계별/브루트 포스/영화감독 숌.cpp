#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int count = 0;
	int num = 666;
	while (true)
	{
		if (count == N) break;

		if (to_string(num).find("666") != string::npos)
		{
			count++;
		}
		num++;
	}

	cout << num - 1 << '\n';

	return 0;
}
			