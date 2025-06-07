#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	getline(cin, s);

	// Create a stringstream object 'ss' from the string 's'
	stringstream ss(s);

	// �Է� ������ '>>' is used to extract words from the stringstream 
	// ���� �Է� ������������, Ű���忡�� �޴� �Է��� ������ ����.
	
	string word;
	int count = 0;

	while (ss >> word)
	{
		count++;
	}
	
	cout << count << '\n';

	return 0;
}