#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    queue<int> cards;
    for (int i = 1; i <= N; ++i) cards.push(i);

    while (cards.size() > 1) {
        cards.pop();                  // 버리고
        cards.push(cards.front());    // 앞을 뒤로 복사
        cards.pop();                  // 원본 제거
    }

    cout << cards.front() << '\n';
    return 0;
}
