#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> types(N);
    for (int i = 0; i < N; ++i)
        cin >> types[i];

    deque<int> dq;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (types[i] == 0)  // ť�� ���� deque�� ����
            dq.push_back(x);
    }

    int M;
    cin >> M;
    while (M--) {
        int c;
        cin >> c;
        dq.push_front(c);        // �� ���� ���� ������ �ڷᱸ������ ���ϱ� �տ� ����
        cout << dq.back() << " "; // �������� ������ ���� dq�� back
        dq.pop_back();
    }

    return 0;
}
