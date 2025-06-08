#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += s[i] - '0';
	}

	cout << sum << "";
	return 0;
}
