#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    long long ccw = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (ccw > 0) cout << 1 << "\n";
    else if (ccw < 0) cout << -1 << "\n";
    else cout << 0 << "\n";

    return 0;
}
