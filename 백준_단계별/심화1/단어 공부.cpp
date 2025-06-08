#include <iostream>
#include <string>
using namespace std;
#define alpahbet 26

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int count[alpahbet] = { 0 };

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if (c >= 'a' && c <= 'z')
		{
			c = c + ('A' - 'a');
		}
		
		count[c - 'A']++ ;
	}

	bool same = false;
	int imax = 0;
	int maxIndex = -1;

	for (int j = 0; j < alpahbet; j++)
	{
		if (count[j] > imax)
		{
			imax = count[j];
			maxIndex = j;
			same = false;
		}

		else if (count[j] == imax)
		{
			same = true;
		}
	}

	cout << (same ? '?' : (char)(maxIndex + 'A')) << '\n';
	
	return 0;
}