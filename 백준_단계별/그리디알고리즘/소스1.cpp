#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// ���ڿ� ����� '+' �������� �����ϰ�, ���� ����
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

    // '-' �������� ������, �� ������� '+' ���
    while (getline(ss, segment, '-')) {
        parts.push_back(sum_of_expression(segment));
    }

    // ù ����� ���ϰ�, �������� ���� ����
    int result = parts[0];
    for (size_t i = 1; i < parts.size(); ++i) {
        result -= parts[i];
    }

    cout << result << '\n';
    return 0;
}
