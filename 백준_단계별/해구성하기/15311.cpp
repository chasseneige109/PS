#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;  // N이 입력되지만 실제로는 항상 <=1,000,000임

    // 봉지 개수: 2000
    cout << 2000 << "\n";

    // 앞 1000개: 1
    for (int i = 0; i < 1000; i++)
        cout << 1 << " ";
    // 뒤 1000개: 1000
    for (int i = 0; i < 1000; i++)
        cout << 1000 << " ";
    cout << "\n";

    return 0;
}
