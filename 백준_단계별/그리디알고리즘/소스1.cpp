#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// 문자열 덩어리를 '+' 기준으로 분할하고, 합을 구함
int sum_of_expression(const string& expr) {
    stringstream ss(expr);
    string token;
    int sum = 0;
    while (getline(ss, token, '+')) {
        sum += stoi(token);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stringstream ss(s);
    string segment;
    vector<int> parts;

    // '-' 기준으로 나누고, 각 덩어리에서 '+' 계산
    while (getline(ss, segment, '-')) {
        parts.push_back(sum_of_expression(segment));
    }

    // 첫 덩어리는 더하고, 나머지는 전부 빼기
    int result = parts[0];
    for (size_t i = 1; i < parts.size(); ++i) {
        result -= parts[i];
    }

    cout << result << '\n';
    return 0;
}
