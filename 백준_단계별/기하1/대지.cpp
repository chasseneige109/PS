#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int max_x = -10000;
    int max_y = -10000;
    int min_x = 10000;
    int min_y = 10000;

    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;

        if (x > max_x) max_x = x;
        if (y > max_y) max_y = y;
        if (x < min_x) min_x = x;
        if (y < min_y) min_y = y;
    }
    int width = max_x - min_x;
    int height = max_y - min_y;
    cout << width * height << '\n';
    return 0;
}