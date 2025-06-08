#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N; 
	int count = 0;
	
	for (int j = 0; j < N; j++)
	{
		string s;
		cin >> s;

		bool alphabet[26] = { false };
		bool check = true;

		for (int i = 0; i < s.length(); i++)
		{
			if (!alphabet[s[i] - 'a'])
			{
				alphabet[s[i] - 'a'] = true;
			}
			else if (i > 0 && alphabet[s[i] - 'a'] && s[i] != s[i - 1])
			{
				check = false;
				break;
			}


		}
		if (check)
		{
			count++;
		}
		

	}
	

	cout << count << '\n';

	return 0;
}