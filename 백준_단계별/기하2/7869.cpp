#include <iostream>
#include <algorithm>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double dx = x1 - x2;
    double dy = y1 - y2;
    double d = sqrt(dx * dx + dy * dy);

    double area = 0.0;
    if (d >= r1 + r2) {
        area = 0.0; // 겹치지 않음
    }
    else if (d <= fabs(r1 - r2)) {
        // 작은 원이 완전히 포함됨
        double r = min(r1, r2);
        area = M_PI * r * r;
    }
    else {
        double alpha = acos((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));
        double beta = acos((d * d + r2 * r2 - r1 * r1) / (2 * d * r2));
        double t = (-d + r1 + r2) * (d + r1 - r2) * (d - r1 + r2) * (d + r1 + r2);
        area = r1 * r1 * alpha + r2 * r2 * beta - 0.5 * sqrt(t);
    }

    cout << fixed << setprecision(3) << area << "\n";
    return 0;
}
