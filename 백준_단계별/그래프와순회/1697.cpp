#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<bool> visited(100001 , false);
	vector<int> cnt(100001 , 0);
	queue<int> q;

	visited[N] = true;
	q.push(N);
	cnt[N] = 0;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		if (curr + 1 < 100001)
			if (!visited[curr + 1])
			{
				visited[curr + 1] = true;
				q.push(curr + 1);
				cnt[curr + 1] = cnt[curr] + 1;
			}

		if (curr - 1 < 100001 && curr > 0)
			if (!visited[curr - 1])
			{
				visited[curr - 1] = true;
				q.push(curr - 1);
				cnt[curr - 1] = cnt[curr] + 1;
			}
		if (curr * 2 <= 100000)
			if (!visited[curr * 2])
			{
				visited[curr * 2] = true;
				q.push(curr * 2);
				cnt[curr * 2] = cnt[curr] + 1;
			}

		if (visited[K])
		{
			cout << cnt[K] << "\n";
			return 0;
		}
	}

	return 0;
}
		

			
		
	
