#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_set<string> mem1;
    vector<string> result;

    for (int i = 0; i < N; i++) {
        string x;
        cin >> x;
        mem1.insert(x);
    }

    for (int j = 0; j < M; j++) {
        string y;
        cin >> y;
        if (mem1.find(y) != mem1.end()) {
            result.push_back(y);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (const auto& name : result) {
        cout << name << "\n";
    }

    return 0;
}
