#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int n = 1;
	cin >> N;
	while (N > 3*n * (n - 1) + 1)
	{
		n++;
	}
	cout << n << '\n';
	return 0;
}