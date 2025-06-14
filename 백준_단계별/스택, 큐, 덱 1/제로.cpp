#include <iostream>
#include <vector>
#include <numeric> // accumulate
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;

    vector<int> stack;

    for (int i = 0; i < K; ++i)
    {
        int num;
        cin >> num;
        if (num == 0) stack.pop_back();
        else stack.push_back(num);
    }



     
    int sum = accumulate(stack.begin(), stack.end(), 0);  // 0부터 더함
    cout << sum << '\n';  
    return 0;
}
