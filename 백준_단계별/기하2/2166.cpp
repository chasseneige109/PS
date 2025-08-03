#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    long double area = 0;
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N; // 마지막 점에서 첫 번째 점으로 연결
        area += (long double)(x[i] * y[j]) - (long double)(x[j] * y[i]);
    }

    area = fabsl(area) / 2.0;

    cout << fixed << setprecision(1) << area << "\n";
    return 0;
}
