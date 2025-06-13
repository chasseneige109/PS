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
        points[i] = { y, x };  // y, x ������ ����!
    }

    sort(points.begin(), points.end());  // y �켱 ���ĵ�

    for (int i = 0; i < N; ++i)
        cout << points[i].second << ' ' << points[i].first << '\n';  // �ٽ� x y ������ ���

    return 0;
}
