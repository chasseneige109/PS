#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int basket[101];  // N �ִ� 100�����ϱ� �˳��� 101

    // �ʱ�ȭ: �ٱ��� ��ȣ = 1~N
    for (int i = 1; i <= N; i++) {
        basket[i] = i;
    }

    // M�� ���� i~j ������ ����
    for (int m = 0; m < M; m++) {
        int i, j;
        cin >> i >> j;

        // ���ʿ��� ����� swap
        while (i < j) {
            int temp = basket[i];
            basket[i] = basket[j];
            basket[j] = temp;
            i++;
            j--;
        }
    }

    // ��� ���
    for (int i = 1; i <= N; i++) {
        cout << basket[i] << " ";
    }

    cout << "\n";
    return 0;
}
