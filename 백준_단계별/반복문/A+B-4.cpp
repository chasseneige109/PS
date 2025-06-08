#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B;
	while (cin >> A >> B)  // 입력이 끝날 때까지 반복
	{
		cout << A + B << "\n";
	}
	return 0;
}
