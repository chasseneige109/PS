#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	stack<int> stk;
	int count = 1;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;

		// 현재 번호가 count와 같다면 pass
		if (num == count)
		{
			count++;
		}
		else
		{
			// 스택의 top이 다음 번호이면 pop
			while (!stk.empty() && stk.top() == count)
			{
				stk.pop();
				count++;
			}

			// num보다 작은 숫자가 스택 위에 오면 불가능
			if (!stk.empty() && num > stk.top())
			{
				cout << "Sad\n";
				return 0;
			}

			stk.push(num);
		}
	}

	// 마지막으로 스택 정리
	while (!stk.empty())
	{
		if (stk.top() == count)
		{
			stk.pop();
			count++;
		}
		else
		{
			cout << "Sad\n";
			return 0;
		}
	}

	cout << "Nice\n";
	return 0;
}
