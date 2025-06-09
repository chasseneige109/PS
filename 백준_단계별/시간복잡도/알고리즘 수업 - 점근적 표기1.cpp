#include <iostream>
using namespace std;

int main() {
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    if (a1 > c) {
        cout << 0 << '\n';
    }
    else {
        // check if a0 ¡Â (c - a1) * n0
        if (a0 <= (c - a1) * n0) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}
