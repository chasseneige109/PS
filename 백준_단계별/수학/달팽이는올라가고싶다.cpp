#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, V;
	cin >> A >> B >> V;
	
	cout << (V - B - 1) / (A - B) + 1 << " ";
	return 0;
}