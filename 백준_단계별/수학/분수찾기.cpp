#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int X;
	cin >> X;
	
	int n = 1;
	while ( X > n*(n+1)/2 )
	{
		n++;
	}
	int index = X - n * (n - 1) / 2;
	if (n % 2 == 0) // Â¦¼ö
	{
		cout << index << "/" << n + 1 - index;
	}
	else // È¦¼ö
	{
		cout << n + 1 - index << "/" << index;
	}
	
	return 0;

}
