#include <cstdio>

int count[10001];  // 1~10000 숫자 빈도 기록

int main() {
    int N, x;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &x);
        count[x]++;
    }

    for (int i = 1; i <= 10000; ++i) {
        while (count[i]--) {
            printf("%d\n", i);
        }
    }

    return 0;
}
