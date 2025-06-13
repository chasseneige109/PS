#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    unordered_map<int, int> freq;

    for (int i = 0; i < N; i++) {
        int card;
        cin >> card;
        freq[card]++;
    }

    int M;
    cin >> M;

    for (int j = 0; j < M; j++) {
        int p;
        cin >> p;

        if (freq.find(p) == freq.end()) {
            cout << 0 << " ";
        }
        else {
            cout << freq[p] << " ";
        }
    }

    cout << "\n";
    return 0;
}
