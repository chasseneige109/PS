#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = { y, x };  // y, x 순서로 저장!
    }

    sort(points.begin(), points.end());  // y 우선 정렬됨

    for (int i = 0; i < N; ++i)
        cout << points[i].second << ' ' << points[i].first << '\n';  // 다시 x y 순으로 출력

    return 0;
}
