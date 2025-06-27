#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<long long> psum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }

    while (M--) {
        int l, r;
        cin >> l >> r;
        cout << psum[r] - psum[l - 1] << '\n';
    }

    return 0;
}
