#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int a = 2;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		a = 2*a - 1;
	}
	cout << (a * a) << ' ';
	return 0;
}