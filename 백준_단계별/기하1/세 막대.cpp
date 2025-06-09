#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b <= c)
    {
        cout << 2 * (a + b) - 1 << '\n';
    }
    else if (a + c <= b)
    {
        cout << 2 * (a + c) - 1 << '\n';
    }
    else if (b + c <= a)
    {
        cout << 2 * (b + c) - 1 << '\n';
    }
    else
    {
        cout << a + b + c << '\n';
    }
    return 0;
}