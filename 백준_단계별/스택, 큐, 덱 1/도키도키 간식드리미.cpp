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

		// ���� ��ȣ�� count�� ���ٸ� pass
		if (num == count)
		{
			count++;
		}
		else
		{
			// ������ top�� ���� ��ȣ�̸� pop
			while (!stk.empty() && stk.top() == count)
			{
				stk.pop();
				count++;
			}

			// num���� ���� ���ڰ� ���� ���� ���� �Ұ���
			if (!stk.empty() && num > stk.top())
			{
				cout << "Sad\n";
				return 0;
			}

			stk.push(num);
		}
	}

	// ���������� ���� ����
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
