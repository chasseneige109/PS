#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    long long x, y;
};

int N;
vector<int> parent, groupSize;

int findParent(int x) {
    return parent[x] == x ? x : parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a != b) {
        parent[b] = a;
        groupSize[a] += groupSize[b];
    }
}

long long ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool intersect(Point a1, Point a2, Point b1, Point b2) {
    long long ab1 = ccw(a1, a2, b1);
    long long ab2 = ccw(a1, a2, b2);
    long long cd1 = ccw(b1, b2, a1);
    long long cd2 = ccw(b1, b2, a2);

    // 일반적인 교차
    if (ab1 * ab2 < 0 && cd1 * cd2 < 0) return true;

    // colinear (일직선)인 경우 겹치는지 확인
    auto onSegment = [](Point p, Point q, Point r) {
        return min(p.x, r.x) <= q.x && q.x <= max(p.x, r.x) &&
            min(p.y, r.y) <= q.y && q.y <= max(p.y, r.y);
        };

    if (ab1 == 0 && onSegment(a1, b1, a2)) return true;
    if (ab2 == 0 && onSegment(a1, b2, a2)) return true;
    if (cd1 == 0 && onSegment(b1, a1, b2)) return true;
    if (cd2 == 0 && onSegment(b1, a2, b2)) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<pair<Point, Point>> seg(N);
    for (int i = 0; i < N; i++) {
        cin >> seg[i].first.x >> seg[i].first.y >> seg[i].second.x >> seg[i].second.y;
    }

    parent.resize(N);
    groupSize.assign(N, 1);
    for (int i = 0; i < N; i++) parent[i] = i;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (intersect(seg[i].first, seg[i].second, seg[j].first, seg[j].second)) {
                unionParent(i, j);
            }
        }
    }

    // 그룹 수와 가장 큰 그룹 크기 계산
    int groupCnt = 0, maxSize = 0;
    for (int i = 0; i < N; i++) {
        if (findParent(i) == i) {
            groupCnt++;
            maxSize = max(maxSize, groupSize[i]);
        }
    }

    cout << groupCnt << "\n" << maxSize << "\n";
    return 0;
}
