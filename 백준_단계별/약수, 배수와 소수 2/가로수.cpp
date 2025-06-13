#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// �ִ�����
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> tree(N);
    for (int i = 0; i < N; ++i) {
        cin >> tree[i];
    }

    vector<int> diff;
    for (int i = 1; i < N; ++i) {
        diff.push_back(tree[i] - tree[i - 1]);
    }

    // ��ü ������ GCD ���
    int g = diff[0];
    for (int i = 1; i < diff.size(); ++i) {
        g = gcd(g, diff[i]);
    }

    // �ʿ��� ���� �� ���
    int result = 0;
    for (int d : diff) {
        result += (d / g - 1);
    }

    cout << result << '\n';
    return 0;
}
