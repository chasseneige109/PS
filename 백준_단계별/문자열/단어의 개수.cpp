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

	// 입력 연산자 '>>' is used to extract words from the stringstream 
	// 말은 입력 연산자이지만, 키보드에서 받는 입력을 뜻하진 않음.
	
	string word;
	int count = 0;

	while (ss >> word)
	{
		count++;
	}
	
	cout << count << '\n';

	return 0;
}