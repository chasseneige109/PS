#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	int u, v, w;
	//struct�� �⺻������ Public
	bool operator< (const Edge& other) const
	{
		return w < other.w;
	}
};

//Union Find start:
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
		if (rnk[a] = rnk[b])
			rnk[b]++;
	}

	return true;
}
//Union Find :end

int main()
{
	int V, E;
	cin >> V >> E;

	//Union Find
	parent.resize(V + 1);

	for (int i = 0; i <= V; ++i)
	{
		parent[i] = i;
	}

	//Union by rank
	rnk.resize(V + 1, 0);

	//Edges
	vector<Edge> edges(E);

	for (int i = 0; i < E; ++i)
	{
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}

	sort(edges.begin(), edges.end());

	int total_w = 0;
	int edgeCount = 0;
	for (int i = 0; i < E; ++i)
	{
		if (uni(edges[i].u, edges[i].v))
		{
			total_w += edges[i].w;
			edgeCount++;
		}

		// �ȳ־ uni���� �ɷ����� ����� ������, ���� ����ȭ�� ���� ����.
		if (edgeCount == V - 1)
			break;
	}

	cout << total_w << "\n";
	return 0;
}