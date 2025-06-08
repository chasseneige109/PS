#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, i;
	cin >> T;
	for (i = 0; i < T; i++)
	{
		string s;
		cin >> s;
		cout << s[0] << s[s.size() - 1] << "\n";
	}

return 0;

}