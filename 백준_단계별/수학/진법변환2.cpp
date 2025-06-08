#include <iostream>
#include <string>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, B;
    cin >> N >> B;

    string result = "";

    while (N > 0) {
        int remainder = N % B;
        if (remainder < 10)
            result = char('0' + remainder) + result;
        else
            result = char('A' + (remainder - 10)) + result;

        N /= B;
    }

    cout << result << '\n';
    return 0;
}
