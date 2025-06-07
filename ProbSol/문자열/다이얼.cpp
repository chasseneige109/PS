#include <iostream>
#include <string>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; 
    cin >> s;

    int d[] = {
        3,3,3, 4,4,4, 5,5,5,
        6,6,6, 7,7,7, 8,8,8,8,
        9,9,9, 10,10,10,10
    };

    int t = 0;
    for (char c : s)
    {
        t += d[c - 'A'];
    }

    cout << t;

    return 0;
}