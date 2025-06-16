#include <iostream>
using namespace std;

long long tail_factorial(int n, long long acc = 1) {
    if (n <= 1) return acc;
    return tail_factorial(n - 1, acc * n);
}

int main() {
    int N;
    cin >> N;
    cout << tail_factorial(N) << '\n';
    return 0;
}
