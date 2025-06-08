#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int R; 
		string s;
		cin >> R >> s;

        for (int j = 0; j < s.length(); j++)
        {
            for (int k = 0; k < R; k++)
            {
                cout << s[j];
            }
        }
        cout << '\n';
    }

    return 0;
}