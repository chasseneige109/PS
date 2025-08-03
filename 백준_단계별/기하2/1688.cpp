#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

struct Point {
    ll x, y;
};

ll ccw(Point a, Point b, Point c) {
    ll v = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (v > 0) return 1;
    if (v < 0) return -1;
    return 0;
}

//경계 위의 점인지 체크
bool onSegment(Point a, Point b, Point p) {
    if (ccw(a, b, p) != 0) return false;
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
        min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

//내부 or 경계 위 점인지 체크
bool inPolygon(const vector<Point>& poly, Point p) {
    int n = poly.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        Point a = poly[i], b = poly[(i + 1) % n];

        // 경계 위 체크
        if (onSegment(a, b, p)) return true;

        // y좌표 조건: p.y가 a.y 이상이고 b.y보다 작은 경우만 체크
        if (a.y > b.y) swap(a, b);
        if (p.y >= a.y && p.y < b.y) {
            // 교차 x좌표
            long double xcross = (long double)(b.x - a.x) * (p.y - a.y) / (b.y - a.y) + a.x;
            if (xcross > p.x) cnt++;
        }
    }
    return cnt % 2 == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<Point> poly(N);
    for (int i = 0; i < N; i++) cin >> poly[i].x >> poly[i].y;

    for (int i = 0; i < 3; i++) {
        Point p; cin >> p.x >> p.y;
        cout << (inPolygon(poly, p) ? 1 : 0) << "\n";
    }
    return 0;
}
