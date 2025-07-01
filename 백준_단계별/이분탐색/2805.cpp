#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int N;
ll M;

// height 기준으로 나무를 잘랐을 때 얻는 나무 길이 총합
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);ll cnt(const vector<ll>& arr, ll height) {
    ll count = 0;
    for (ll h : arr) {
        if (h > height)
            count += h - height;
    }
    return count;
}



    cin >> N >> M;
    vector<ll> line(N);

    for (int i = 0; i < N; ++i)
        cin >> line[i];

    ll left = 0;
    ll right = *max_element(line.begin(), line.end());
    ll result = 0;

    while (left <= right)
    {
        ll mid = (left + right) / 2;
        ll total = cnt(line, mid);

        if (total >= M)
        {
            result = mid;       // 지금 절단 높이도 조건 만족 → 일단 저장
            left = mid + 1;     // 더 높여서 덜 자를 수 있나 시도
        }
        else
        {
            right = mid - 1;    // 너무 적게 잘림 → 절단 높이 낮춰야 함
        }
    }

    cout << result << '\n';
    return 0;
}
