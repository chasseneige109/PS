#include <iostream>
using namespace std;

int N, result = 0;
bool col[14]; // �� �浹 üũ
bool diag1[27]; // �� �밢�� (row + col)
bool diag2[27]; // �� �밢�� (row - col + N - 1)

void queen(int row) {
    if (row == N) {
        result++;
        return;
    }

    for (int c = 0; c < N; ++c) {
        if (!col[c] && !diag1[row + c] && !diag2[row - c + N - 1]) {
            col[c] = diag1[row + c] = diag2[row - c + N - 1] = true;

            queen(row + 1);

            col[c] = diag1[row + c] = diag2[row - c + N - 1] = false;
        }
    }
}

int main() {
    cin >> N;
    queen(0);
    cout << result << "\n";
    return 0;
}