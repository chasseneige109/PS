#include <iostream>
#include <string>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string N;
    int B;
    cin >> N >> B;

    int result = 0;

    for (int i = 0; i < N.length(); i++) {
        char c = N[i];
        int digit;

        if (c >= '0' && c <= '9') {
            digit = c - '0';
        }
        else {
            digit = c - 'A' + 10;
        }

        result = result * B + digit;
    }

    cout << result << '\n';
    return 0;
}
