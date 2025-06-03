#include <iostream>
using namespace std;

int main()
{
	int X, N;
	cin >> X >> N;
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		sum += a * b;
	}

	if (sum == X) cout << "Yes" << endl;
	else cout << "No" << endl;
}