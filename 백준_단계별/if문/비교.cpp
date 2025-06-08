#include <iostream>
using namespace std;



int main()
{
	int B , A;
	cin >> B >> A;

	int a_100 = A / 100;
	int a_10 = (A / 10) % 10;
	int a_1 = A % 10;

	cout << B * a_1   << " " 
		 << B * a_10  << " " 
		 << B * a_100 << " "
		 << B * A     << endl;

	return 0;
}
