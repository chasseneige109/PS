#include <iostream>
#include <iomanip>  // setprecision�� ���� �ʿ�
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    double result = static_cast<double>(A) / B;

    cout << fixed << setprecision(10) << result << endl;

    return 0;
}