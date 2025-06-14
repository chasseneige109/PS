#include <iostream>
using namespace std;

int comb[31][31];

void init_comb() {
    for (int i = 0; i <= 30; ++i) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; ++j)
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init_comb();

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;
        cout << comb[M][N] << '\n';
    }

    return 0;
}
