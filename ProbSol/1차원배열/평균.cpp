#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    double scores[1000];
    double max_score = 0;

    for (int i = 0; i < N; i++) {
        cin >> scores[i];
        if (scores[i] > max_score)
            max_score = scores[i];
    }

    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (scores[i] / max_score) * 100;
    }

    double avg = sum / N;
    cout << avg << "\n";

    return 0;
}
