#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> answer(N, -1);
    stack<int> s;

    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = N - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= A[i]) {
            s.pop();
        }

        if (!s.empty()) {
            answer[i] = s.top();
        }

        s.push(A[i]);
    }

    for (int x : answer)
        cout << x << " ";
    cout << "\n";

    return 0;
}
