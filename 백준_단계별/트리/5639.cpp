#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder;

void postorder(int start, int end) 
{
    if (start > end)
        return;
    int idx = start+1;
    while (preorder[idx] < preorder[start] && idx <= end)
        idx++;
    postorder(start + 1, idx - 1);
    postorder(idx, end);
    cout << preorder[start] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    while (cin >> x) {
        preorder.push_back(x);
    }

    postorder(0, preorder.size() - 1);

    return 0;
}
