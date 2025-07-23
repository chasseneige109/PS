#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);

    int lo = 1, hi = N;
    for (int i = 0; i < N; ++i) {
        // Ȧ�� ��°�� ū ��, ¦�� ��°�� ���� ��
        if (i % 2 == 0)
            A[i] = hi--;
        else
            A[i] = lo++;
    }

    for (int x : A)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
