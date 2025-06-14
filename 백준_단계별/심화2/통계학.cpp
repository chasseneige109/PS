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
    int freq[8001] = { 0 };  // -4000 ~ 4000 �� +4000 offset
    int sum = 0;

    int max_freq = 0;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        sum += nums[i];
        freq[nums[i] + 4000]++;
        max_freq = max(max_freq, freq[nums[i] + 4000]);
    }

    // ������
    int avg = round((double)sum / N);

    // ����
    sort(nums.begin(), nums.end());

    // �߾Ӱ�
    int median = nums[N / 2];

    // �ֺ�
    vector<int> modes;
    for (int i = 0; i <= 8000; ++i) {
        if (freq[i] == max_freq) {
            modes.push_back(i - 4000);  // ���� ������ ����
        }
    }
    int mode = (modes.size() >= 2) ? modes[1] : modes[0];

    // ����
    int range = nums.back() - nums.front();

    // ���
    cout << avg << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << range << '\n';

    return 0;
}
