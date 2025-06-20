#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> nums;
int op[4]; // +, -, *, /
int max_result = -1e9;
int min_result = 1e9;

void dfs(int depth, int current) {
    if (depth == N) {
        max_result = max(max_result, current);
        min_result = min(min_result, current);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (op[i] > 0) {
            op[i]--;

            int next = current;
            if (i == 0) next += nums[depth];
            else if (i == 1) next -= nums[depth];
            else if (i == 2) next *= nums[depth];
            else if (i == 3) {
                if (next < 0)
                    next = -(-next / nums[depth]);
                else
                    next /= nums[depth];
            }

            dfs(depth + 1, next);
            op[i]++; // 백트래킹 복구
        }
    }
}

int main() {
    cin >> N;
    nums.resize(N);
    for (int i = 0; i < N; ++i) cin >> nums[i];
    for (int i = 0; i < 4; ++i) cin >> op[i];

    dfs(1, nums[0]);

    cout << max_result << '\n' << min_result << '\n';

    return 0;
}
