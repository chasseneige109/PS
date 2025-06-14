#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_set<string> dancers;
    dancers.insert("ChongChong"); // 처음부터 춤추는 유일한 사람

    for (int i = 0; i < N; ++i) {
        string a, b;
        cin >> a >> b;

        if (dancers.count(a) || dancers.count(b)) {
            dancers.insert(a);
            dancers.insert(b);
        }
    }

    cout << dancers.size() << '\n';
    return 0;
}
