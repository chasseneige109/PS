#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<int> A;
    A.reserve(n);  // 리해시 방지
    int x;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        A.insert(x);
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        if (A.find(x) != A.end()) {
            A.erase(x);  // A ∩ B → 둘 다에 있으니 제외
        }
        else {
            ++count;     // B에만 있는 값 → 대칭 차집합
        }
    }

    // A에 남은 값 = A에만 있는 값 → 대칭 차집합
    count += A.size();

    cout << count << '\n';
    return 0;
}
