#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];

    cin >> M >> K;
    vector<vector<int>> B(M, vector<int>(K));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < K; ++j)
            cin >> B[i][j];

    // 결과 행렬 C[N][K]
    vector<vector<int>> C(N, vector<int>(K, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < K; ++j)
            for (int l = 0; l < M; ++l)
                C[i][j] += A[i][l] * B[l][j];

    // 출력
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j)
            cout << C[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
