#include <iostream>
using namespace std;

int main()
{
	int H, M;
	cin >> H >> M;

	if (M < 45) {
		M += 60;
		H -= 1;
		if (H < 0) {
			H = 23;
		}
	}
	M -= 45;
	cout << H << " " << M << endl;

	return 0;
}