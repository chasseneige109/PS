#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	queue<int> q;
	vector<int> time(100001, -1);
	vector<int> pre(100001, -1);

	q.push(N);
	time[N] = 0;

	while (!q.empty())
	{
		if (time[K] != -1)
		{
			break;
		}

		int curr = q.front(); q.pop();
		
			for (int nxt : {curr + 1, curr - 1, curr * 2})
			{
				if (nxt < 0 || nxt >= 100001) continue;
				if (time[nxt] == -1)
				{
					time[nxt] = time[curr] + 1;
					pre[nxt] = curr;
					q.push(nxt);
				}
			}
		

	}

	cout << time[K]<< "\n";
	int now = K;

	vector<int> answer;
	for (int i = 0; i <= time[K]; ++i)
	{
		answer.push_back(now);
		now = pre[now];
	}

	for (int i = answer.size() - 1; i >= 0; --i)
	{
		cout << answer[i] << " ";
	}


	return 0;




}