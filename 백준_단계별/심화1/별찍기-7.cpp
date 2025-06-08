#include <iostream>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    int total = 2 * N - 1;

    for (int i = 1; i <= total; i++)
    {
        int stars = i < N ? 2 * i - 1 : 2 * N - 1 - 2*(i - N);
        int spaces = i < N ? N - i : i - N;


        for (int j = 0; j < spaces; j++)
        {
            cout << ' ';
        }
        for (int k = 0; k < stars; k++)
        {
            cout << '*';
        }
        cout << '\n';

    }
    return 0;
}