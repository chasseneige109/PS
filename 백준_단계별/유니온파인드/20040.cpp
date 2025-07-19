#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> rnk;

int find(int x)
{
	if (parent[x] == x)
		return x;

	else
		return parent[x] = find(parent[x]);
}

bool uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	
	if (rnk[a] > rnk[b])
	{
		parent[b] = a;
	}

	else
	{
		parent[a] = b;
		if (rnk[a] == rnk[b])
			rnk[b]++;
	}

	return true;
}

int main()
{
	int n, m;
	cin >> n >> m;

	parent.resize(n + 1);
	rnk.resize(n + 1, 0);

	for (int i = 0; i <= n; ++i)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		if (!uni(a, b))
		{
			cout << i + 1 << "\n";
			return 0;
		}
	}

	cout << 0 << "\n";
	return 0;
}