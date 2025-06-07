#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;

	int a = (s1[2] - '0') * 100 + (s1[1] - '0') * 10 + (s1[0] - '0');
	int b = (s2[2] - '0') * 100 + (s2[1] - '0') * 10 + (s2[0] - '0');

	cout << max(a,b) << '\n';

	return 0;
}