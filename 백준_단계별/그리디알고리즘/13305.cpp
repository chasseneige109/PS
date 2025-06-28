#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> distance(N - 1);
    vector<long long> price(N);

    for (int i = 0; i < N - 1; ++i) {
        cin >> distance[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> price[i];
    }

    long long total = 0;
    long long min_price = price[0];

    for (int i = 0; i < N - 1; ++i) {
        if (price[i] < min_price) {
            min_price = price[i];
        }
        total += min_price * distance[i];
    }

    cout << total << '\n';
    return 0;
}
