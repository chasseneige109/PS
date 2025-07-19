#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> netsize;
vector<int> ran;

int find(int x)
{
	if (parent[x] == x)
		return x;

	return parent[x] = find(parent[x]);
}


int uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return netsize[a];

	if (ran[a] < ran[b])
	{
		parent[a] = b;
		netsize[b] += netsize[a];
		return netsize[b];
	}

	else
	{
		parent[b] = a;
		netsize[a] += netsize[b];
		if (ran[a] == ran[b])
			ran[a]++;
		return netsize[a];
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int F;
		cin >> F;

		unordered_map <string, int> translater;
		parent.clear();
		ran.clear();
		netsize.clear();
		int idx = 0;
		
		for (int i = 0; i < F; ++i)
		{
			string a, b;
			cin >> a >> b;


			if (translater.count(a) == 0)
			{
				translater[a] = idx++;
				parent.push_back(translater[a]);
				netsize.push_back(1);
				ran.push_back(0);
			}

			if (translater.count(b) == 0)
			{
				translater[b] = idx++;
				parent.push_back(translater[b]);
				netsize.push_back(1);
				ran.push_back(0);
			}

			cout << uni(translater[a], translater[b]) << "\n";
		}
	}

	return 0;
}