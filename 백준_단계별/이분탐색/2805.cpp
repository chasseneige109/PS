#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int N;
ll M;

// height �������� ������ �߶��� �� ��� ���� ���� ����
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
            result = mid;       // ���� ���� ���̵� ���� ���� �� �ϴ� ����
            left = mid + 1;     // �� ������ �� �ڸ� �� �ֳ� �õ�
        }
        else
        {
            right = mid - 1;    // �ʹ� ���� �߸� �� ���� ���� ����� ��
        }
    }

    cout << result << '\n';
    return 0;
}
