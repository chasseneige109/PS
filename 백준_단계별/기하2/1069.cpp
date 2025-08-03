#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int X, Y, D, T;
    cin >> X >> Y >> D >> T;
    double S = (X * X) + (Y * Y);
    double s = sqrt(S);

    cout << fixed;
    cout.precision(12);

    if (T > s) cout << s << endl;
    else if (D / T < 1) cout << s << endl;
    else if (fmod(s, D) == 0) cout << T * int(s / D) << endl;
    else if (D > s) { // 점프거리가 더 길때
        if (D - s < T) { // 점프하고 걷는게 더 빠를 경우
            if (D - s + T > s) { // 넘어서 점프하고 걸어가는 경우가 걷는것보다 느릴때
                cout << s << endl; // 그냥 걸어서 가자
            }
            // 넘어서 점프하고 걸어가는 경우가 걷는것보단 빠르다
            else cout << T + D - s << endl; // 넘어서 점프하고 걷자.
        }
        else { // 남은거리가 T보다 클 떄 즉, D-s > T라고 하면 
            // s를 두번의 점프를 통해 가야하는 것이 빠르기 떄문에 2T
            if (2 * T > s) cout << s << endl; // 근데 2T보다 s가 작다면 그냥 걸어가는게 낫다.
            else cout << 2 * T << endl; // 2T보다도 s가 크면 2T로 가자.
        }
    }
    else if (s > D) {
        if (s - int(s / D) * D < T) // 점프를 가능한 많이 뛰고 남은 거리가 T보다 작다면 
            cout << (s - int(s / D) * D) + int(s / D) * T << endl; // 가능한 많이 뛴 시간 (s/D)*T 와 뛰고 난 남은거리 s-int(s/D)*D 를 더해준다.
        else
            cout << (int(s / D) + 1) * T << endl; // 점프를 가능한 많이 뛰고 남은거리가 T보다 크다면
    }
}