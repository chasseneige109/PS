#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> freq(1000001, 0);  // A[i] ≤ 1,000,000
    vector<int> answer(N, -1);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        freq[A[i]]++;
    }

    stack<int> s;  // 인덱스를 저장

    for (int i = 0; i < N; ++i) {
        while (!s.empty() && freq[A[s.top()]] < freq[A[i]]) {
            answer[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < N; ++i)
        cout << answer[i] << " ";
    cout << "\n";

    return 0;
}
