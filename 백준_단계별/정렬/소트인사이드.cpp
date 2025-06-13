#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string N;
    cin >> N;

    sort(N.begin(), N.end(), greater<char>());

    cout << N << '\n';
    return 0;
}
