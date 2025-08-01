#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long ans = 0;
    stack<pair<int, int>> s;  // {height, count}

    for (int i = 0; i < N; ++i) {
        int height;
        cin >> height;

        int count = 1;

        while (!s.empty() && s.top().first <= height)
        {
            if (s.top().first == height)
            {
                count += s.top().second;
                ans += s.top().second;
            }

            else
            {
                ans += s.top().second;
            }
            s.pop();
        }
        if (!s.empty()) ans++;
        s.push({ height, count });
    }

    cout << ans << '\n';
    return 0;
}
