#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int D = N / 2;

    for (int i = 1; i <= D; ++i) {
        cout << i + D << ' ' << i << ' ';
    }
    if (N % 2 == 1) {
        cout << N;
    }
    cout << '\n';
    return 0;
}
