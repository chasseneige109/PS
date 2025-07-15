#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int len1 = s1.length();
    int len2 = s2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    // 1. LCS 길이 계산
    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 2. 역추적
    int x = len1;
    int y = len2;
    vector<char> result;

    while (x > 0 && y > 0)
    {
        if (s1[x - 1] == s2[y - 1])
        {
            result.push_back(s1[x - 1]);
            --x;
            --y;
        }
        else if (dp[x - 1][y] > dp[x][y - 1])
        {
            --x;
        }
        else
        {
            --y;
        }
    }

    reverse(result.begin(), result.end());

    // 3. 출력
    cout << dp[len1][len2] << '\n';
    for (char c : result)
        cout << c;
    cout << '\n';

    return 0;
}
