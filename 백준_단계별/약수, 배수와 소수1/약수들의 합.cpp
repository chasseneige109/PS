#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != -1) {
        int sum = 1;  // 1은 무조건 약수
        vector<int> divisors = { 1 }; // 완전수일 때만 사용됨

        // 2부터 sqrt(n)까지 검사
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                int j = n / i;
                if (i != j) {
                    sum += i + j;
                    divisors.push_back(i);
                    if (j != n) divisors.push_back(j);
                }
                else {
                    sum += i;
                    divisors.push_back(i);
                }
            }
        }

        if (sum == n && n != 1) {
            sort(divisors.begin(), divisors.end());
            cout << n << " = " << divisors[0];
            for (int i = 1; i < divisors.size(); ++i)
                cout << " + " << divisors[i];
            cout << '\n';
        }
        else {
            cout << n << " is NOT perfect.\n";
        }
    }

    return 0;
}
