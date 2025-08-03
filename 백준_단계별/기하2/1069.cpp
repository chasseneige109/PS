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
    else if (D > s) { // �����Ÿ��� �� �涧
        if (D - s < T) { // �����ϰ� �ȴ°� �� ���� ���
            if (D - s + T > s) { // �Ѿ �����ϰ� �ɾ�� ��찡 �ȴ°ͺ��� ������
                cout << s << endl; // �׳� �ɾ ����
            }
            // �Ѿ �����ϰ� �ɾ�� ��찡 �ȴ°ͺ��� ������
            else cout << T + D - s << endl; // �Ѿ �����ϰ� ����.
        }
        else { // �����Ÿ��� T���� Ŭ �� ��, D-s > T��� �ϸ� 
            // s�� �ι��� ������ ���� �����ϴ� ���� ������ ������ 2T
            if (2 * T > s) cout << s << endl; // �ٵ� 2T���� s�� �۴ٸ� �׳� �ɾ�°� ����.
            else cout << 2 * T << endl; // 2T���ٵ� s�� ũ�� 2T�� ����.
        }
    }
    else if (s > D) {
        if (s - int(s / D) * D < T) // ������ ������ ���� �ٰ� ���� �Ÿ��� T���� �۴ٸ� 
            cout << (s - int(s / D) * D) + int(s / D) * T << endl; // ������ ���� �� �ð� (s/D)*T �� �ٰ� �� �����Ÿ� s-int(s/D)*D �� �����ش�.
        else
            cout << (int(s / D) + 1) * T << endl; // ������ ������ ���� �ٰ� �����Ÿ��� T���� ũ�ٸ�
    }
}