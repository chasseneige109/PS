#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<char>> video;

string compress(int x, int y, int size) {
    char first = video[x][y];
    bool same = true;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (video[x + i][y + j] != first) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        return string(1, first);
    }
    else {
        int half = size / 2;
        return "("
            + compress(x, y, half)
            + compress(x, y + half, half)
            + compress(x + half, y, half)
            + compress(x + half, y + half, half)
            + ")";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    video.resize(N, vector<char>(N));

    for (int i = 0; i < N; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < N; ++j) {
            video[i][j] = line[j];
        }
    }

    cout << compress(0, 0, N) << "\n";
    return 0;
}
