
#include <iostream>
#include <vector>

int fib[2001];
using namespace std;



int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		if (i == 1)
			fib[i] = 1;
		else if (i == 2)
			fib[i] = 1;
		else
			fib[i] = fib[i - 1] + fib[i - 2];
	}

	vector<int> a;
	vector<int> b;

	if (N % 3 == 2)
	{
		a.push_back(1);
		b.push_back(2);

		for (int i = 3 ; i <= N; i += 3)
		{
			a.push_back(i);
			
			a.push_back(i + 1);
			
			b.push_back(i + 2);
		}
	}
	else if (N % 3 == 1)
		for (int i = 2; i <= N; i += 3)
		{
			a.push_back(i);
			
			a.push_back(i + 1);
			
			b.push_back(i + 2);
		}

	else // N % 3 == 0
	{
		for (int i = 1; i <= N; i += 3)
		{
			a.push_back(i);
		
			a.push_back(i + 1);
		
			b.push_back(i + 2);
		}
	}

	cout << a.size() << '\n';
	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << ' ';
	}
	cout << '\n' << b.size() << '\n';
	for (int i = 0; i < b.size(); ++i)
	{
		cout << b[i] << ' ';
	}
	cout << '\n';
	return 0;

}