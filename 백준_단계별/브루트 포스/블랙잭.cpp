#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<int> cards;
	int max_sum = 0;
	int current_sum = 0;

	for (int i = 0; i < M; i++)
	{
		int card;
		cin >> card;
		cards.push_back(card);
	}

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				current_sum = cards[i] + cards[j] + cards[k];
				if (current_sum <= M && current_sum >= max_sum)
				{
					max_sum = current_sum;
				}
			}
		}
	}
	cout << max_sum << '\n';
	return 0;
}