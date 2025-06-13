#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<int> A;
    A.reserve(n);  // ���ؽ� ����
    int x;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        A.insert(x);
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        if (A.find(x) != A.end()) {
            A.erase(x);  // A �� B �� �� �ٿ� ������ ����
        }
        else {
            ++count;     // B���� �ִ� �� �� ��Ī ������
        }
    }

    // A�� ���� �� = A���� �ִ� �� �� ��Ī ������
    count += A.size();

    cout << count << '\n';
    return 0;
}
