#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            // 입력만 받음, 실제 연결 여부는 필요 없음
        }

        cout << N - 1 << "\n";
    }

    return 0;
}
