#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}

void uni (int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
	{
		parent[y] = x;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	parent.resize(n + 1);
	for (int i = 0; i <= n; ++i)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; ++i)
	{
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 0)
		{
			uni(a, b);
		}

		else
		{
			if (find(a) == find(b))
			{
				cout << "YES" << "\n";
			}
			
			else
			{
				cout << "NO" << "\n";
			}
		}
	}
}