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

void uni(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
		parent[b] = a;
}

int main()
{
	int N, M;
	cin >> N >> M;

	parent.resize(N + 1);
	for (int i = 1; i <= N; ++i)
		parent[i] = i;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int connected;
			cin >> connected;
			if (connected == 1)
				uni(i, j);
		}
	}

	vector<int> route(M);
	for (int i = 0; i < M; ++i)
		cin >> route[i];

	int root = find(route[0]);
	bool possible = true;
	for (int i = 1; i < M; ++i) {
		if (find(route[i]) != root) {
			possible = false;
			break;
		}
	}

	cout << (possible ? "YES" : "NO") << '\n';
	return 0;
}
