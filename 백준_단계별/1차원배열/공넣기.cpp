#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int basket[101];

    // �ʱ� ����: �ٱ��� ��ȣ == �� ��ȣ
    for (int i = 1; i <= N; i++) {
        basket[i] = i;
    }

    for (int m = 0; m < M; m++) {
        int i, j;
        cin >> i >> j;

        // �� ��ȯ
        int temp = basket[i];
        basket[i] = basket[j];
        basket[j] = temp;
    }

    // ��� ���
    for (int i = 1; i <= N; i++) {
        cout << basket[i] << " ";
    }

    cout << "\n";
    return 0;
}
