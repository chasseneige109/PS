#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    vector<int> sortedX = X; // 복사본 만들어서 정렬
    sort(sortedX.begin(), sortedX.end());
    sortedX.erase(unique(sortedX.begin(), sortedX.end()), sortedX.end());

    unordered_map<int, int> compressed;
    for (int i = 0; i < sortedX.size(); ++i) {
        compressed[sortedX[i]] = i;
    }

    for (int i = 0; i < N; ++i) {
        cout << compressed[X[i]] << ' ';
    }

    return 0;
}
