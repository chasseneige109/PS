#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int ans[6] = { 1,1,2,2,2,8 };
	int q[6];

	for (int& x : q)
	{
		cin >> x;
	}

	for (int i = 0; i < 6; i++)
	{
		cout << ans[i] - q[i] << "\n";
	}

	return 0;

}