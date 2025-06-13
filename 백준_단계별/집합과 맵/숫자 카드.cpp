#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, num;
    cin >> N;

    unordered_set<int> cards;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        cards.insert(num);
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> num;
        cout << (cards.count(num)) << ' ';
    }

    return 0;
}
