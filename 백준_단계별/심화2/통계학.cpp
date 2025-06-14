#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> nums(N);
    int freq[8001] = { 0 };  // -4000 ~ 4000 → +4000 offset
    int sum = 0;

    int max_freq = 0;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        sum += nums[i];
        freq[nums[i] + 4000]++;
        max_freq = max(max_freq, freq[nums[i] + 4000]);
    }

    // 산술평균
    int avg = round((double)sum / N);

    // 정렬
    sort(nums.begin(), nums.end());

    // 중앙값
    int median = nums[N / 2];

    // 최빈값
    vector<int> modes;
    for (int i = 0; i <= 8000; ++i) {
        if (freq[i] == max_freq) {
            modes.push_back(i - 4000);  // 원래 값으로 복구
        }
    }
    int mode = (modes.size() >= 2) ? modes[1] : modes[0];

    // 범위
    int range = nums.back() - nums.front();

    // 출력
    cout << avg << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << range << '\n';

    return 0;
}
