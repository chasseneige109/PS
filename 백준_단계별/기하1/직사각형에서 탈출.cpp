#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int min_dist = min({ x, y, w - x, h - y });
    cout << min_dist << '\n';

    return 0;
}

	