#include <iostream>
#include <vector>
using namespace std;

int N, K;
int count = 0;
int result = -1;

void merge(vector<int>& A, int left, int mid, int right, vector<int>& temp) {
    int i = left, j = mid + 1, t = left;

    while (i <= mid && j <= right) {
        if (A[i] <= A[j]) temp[t++] = A[i++];
        else temp[t++] = A[j++];
    }

    while (i <= mid) temp[t++] = A[i++];
    while (j <= right) temp[t++] = A[j++];

    for (int k = left; k <= right; ++k) {
        A[k] = temp[k];
        count++;
        if (count == K) result = A[k];
    }
}

void mergeSort(vector<int>& A, int left, int right, vector<int>& temp) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid, temp);
        mergeSort(A, mid + 1, right, temp);
        merge(A, left, mid, right, temp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    vector<int> A(N);
    vector<int> temp(N);

    for (int i = 0; i < N; ++i) cin >> A[i];

    mergeSort(A, 0, N - 1, temp);

    cout << result << '\n';
    return 0;
}
