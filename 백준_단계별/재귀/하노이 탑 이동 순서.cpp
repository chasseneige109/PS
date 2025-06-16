#include <iostream>
using namespace std;

void hanoi(int n, int from, int to, int via)
{
	if (n == 1)
	{
		cout << from << ' ' << to << '\n';
		return;
	}

	hanoi(n - 1, from, via, to);
	cout << from << ' ' << to << '\n';
	hanoi(n - 1, via, to, from);
}

int main()
{
	int N;
	cin >> N;
	cout << (1 << N) - 1 << "\n";
	hanoi(N, 1, 3, 2);
	return 0;
}