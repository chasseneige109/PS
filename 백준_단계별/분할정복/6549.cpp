#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<ll> height;

ll getMaxArea(int left, int right) {
    if (left == right) return height[left];

    int mid = (left + right) / 2;

    // 좌/우 재귀 호출
    ll leftArea = getMaxArea(left, mid);
    ll rightArea = getMaxArea(mid + 1, right);

    // 가운데 걸치는 넓이 구하기
    int lo = mid;
    int hi = mid + 1;
    ll h = min(height[lo], height[hi]);
    ll midArea = h * 2;

    // 양쪽으로 확장하며 넓이 최대 갱신
    while (left < lo || hi < right) {
        if (hi < right && (lo == left || height[lo - 1] < height[hi + 1])) {
            ++hi;
            h = min(h, height[hi]);
        }
        else {
            --lo;
            h = min(h, height[lo]);
        }
        midArea = max(midArea, h * (hi - lo + 1));
    }

    return max({ leftArea, rightArea, midArea });
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        height = vector<ll>(n);
        for (int i = 0; i < n; ++i) {
            cin >> height[i];
        }

        cout << getMaxArea(0, n - 1) << '\n';
    }

    return 0;
}
