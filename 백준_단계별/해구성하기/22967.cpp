#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> graph;
vector<int> answer;

pair<int, vector<int>> check(vector<vector<bool>>& graph, int a)
{
	int cnt = 0;
	vector<int> list;

	for (int i = 1; i < graph.size(); ++i)
	{
		if (graph[a][i])
		{
			cnt++;
		}
		else
			list.push_back(i);

	}

	return make_pair(cnt, list);
}

int main()
{
	int N;
	cin >> N;

	graph.resize(N + 1, vector<bool>(N + 1, false));

	for (int i = 0; i < N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}

	switch (N) {

	case 2:
	{
		cout << 0 << "\n";
		cout << 1 << "\n";
		break;
	}

	case 3:
	{
		cout << 1 << "\n";
		cout << 1 << "\n";
		int i = 1;
		while (true)
		{
			if (check(graph, i).first == 2)
			{
				cout << check(graph, i).second[0] << " " << check(graph, i).second[1] << "\n";
			}
			++i;
		}
		break;
	}

	case 4:
	{
		cout << 1 << "\n";
		cout << 1 << "\n";
		int i = 1;
		while (i <= 4)
		{
			if (check(graph, i).first == 2)
			{
				cout << i << " " << check(graph, i).second[0] << "\n";
				graph[i][check(graph, i).second[0]] = true;
			}

			else if (check(graph, i).first == 1)
			{
				cout << i << " " << check(graph, i).second[0] << "\n";
				graph[i][check(graph, i).second[0]] = true;
				cout << i << " " << check(graph, i).second[1] << "\n";
				graph[i][check(graph, i).second[1]] = true;
			}
			++i;
		}
		break;
	}

	default:
	{

		cout << check(graph, 1).first << "\n";
		cout << 2 << "\n";

		for (int i = 2; i <= N; ++i)
		{
			if (!graph[1][i])
			{
				cout << 1 << " " << i << "\n";
				graph[1][i] = true;
			}
		}

		break;
	}

	}
	return 0;
}