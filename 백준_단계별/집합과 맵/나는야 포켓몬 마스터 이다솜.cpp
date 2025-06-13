#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_map<string, int> name_to_num;
    vector<string> num_to_name(N + 1); // 1-based index

    for (int i = 1; i <= N; ++i) {
        string name;
        cin >> name;
        name_to_num[name] = i;
        num_to_name[i] = name;
    }

    while (M--) {
        string query;
        cin >> query;

        if (isdigit(query[0])) {
            // 숫자면 -> 이름
            int num = stoi(query);
            cout << num_to_name[num] << '\n';
        }
        else {
            // 이름이면 -> 숫자
            cout << name_to_num[query] << '\n';
        }
    }

    return 0;
}
