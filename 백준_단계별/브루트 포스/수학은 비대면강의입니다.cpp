#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int x, y;

	for (int i = -999; i <= 999; i++)
	{
		for (int j = -999; j <= 999; j++)
		{
			if (a * i + b * j == c && d * i + e * j == f)
			{
				x = i;
				y = j;
				cout << x << ' ' << y << '\n';
				return 0; // 첫 번째 해를 찾으면 바로 종료
			}

		}
	}
}
