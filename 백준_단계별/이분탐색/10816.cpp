#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[500001];
int target[500001];

int lower(int x) {
    int left = 0, right = N;
    while (left < right) {
        int mid = (left + right) / 2;
        if (A[mid] >= x)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int upper(int x) {
    int left = 0, right = N;
    while (left < right) {
        int mid = (left + right) / 2;
        if (A[mid] > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    sort(A, A + N);

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        cout << upper(x) - lower(x) << ' ';
    }
    return 0;
}
