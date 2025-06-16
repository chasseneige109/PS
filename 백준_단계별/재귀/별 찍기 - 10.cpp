#include <iostream>
#include <vector>
#include <string>
using namespace std;

void stars(vector<vector<char>>& data, int x, int y, int size)
{
    if (size == 1)
    {
        data[x][y] = '*';
        return;
    }

    int next = size / 3;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == 1 && j == 1) continue;

            stars(data, x + i * next, y + j * next, next);
        }
    }


}

int main()
{
    int N;
    cin >> N;
    vector<vector<char>> board(N, vector<char>(N, ' '));

    stars(board, 0, 0, N);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;

}