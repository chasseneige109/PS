#include <iostream>
#include <string>
using namespace std;

void cantor(string& s, int start, int len)
{
	if (len == 1) return;

	int third = len / 3;
	for (int i = start + third; i < start + 2 * third; ++i)
	{
		s[i] = " ";
	}

	cantor(string & s, start, third);
	cantor(string & s, 2 * third, third);
}

int main()
{
	int N;
	while (cin >> N)
	{
		int len = 1;
		for (int j = 0; j < N; j++)
		{
			len *= 3
		}

		string s(len, '-');
		cantor(s, 0, len);
		cout << s << '\n';
	}
	return 0;
}