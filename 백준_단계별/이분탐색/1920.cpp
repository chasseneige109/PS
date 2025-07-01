#include <iostream>
using namespace std;

const int MAX = 100000;
int A[MAX];

// 퀵 정렬 구현
void quickSort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }

    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

// 이진 탐색 구현
bool binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    quickSort(A, 0, N - 1);  // 정렬

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        cout << binarySearch(A, N, x) << '\n';
    }

    return 0;
}
