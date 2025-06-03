#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    map<int, int> freq;
    freq[a]++;
    freq[b]++;
    freq[c]++;

    int reward = 0;

    for (auto& p : freq) {
        if (p.second == 3) {
            reward = 10000 + p.first * 1000;
            break;
        }
        else if (p.second == 2) {
            reward = 1000 + p.first * 100;
            break;
        }
    }

    if (reward == 0) {
        // 모두 다를 경우: 가장 큰 값 × 100
        int max_val = max({ a, b, c });
        reward = max_val * 100;
    }

    cout << reward << endl;
    return 0;
}
