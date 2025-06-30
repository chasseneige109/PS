#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<ll> height;

ll getMaxArea(int left, int right) {
    if (left == right) return height[left];

    int mid = (left + right) / 2;

    // ��/�� ��� ȣ��
    ll leftArea = getMaxArea(left, mid);
    ll rightArea = getMaxArea(mid + 1, right);

    // ��� ��ġ�� ���� ���ϱ�
    int lo = mid;
    int hi = mid + 1;
    ll h = min(height[lo], height[hi]);
    ll midArea = h * 2;

    // �������� Ȯ���ϸ� ���� �ִ� ����
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
