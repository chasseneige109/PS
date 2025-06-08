#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	getline(cin, s);

	bool inWord = false;
	int count = 0;
	for (char c : s)
	{
		if (c != ' ' && !inWord)
		{
			count++;
			inWord = true;
		}

		else if (c == ' ')
		{
			inWord = false;
		}
	}
	cout << count << '\n';
	return 0;
}