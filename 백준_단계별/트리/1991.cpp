#include <iostream>
using namespace std;

int left_child[26];  // 'A'~'Z' °Ê 0~25
int right_child[26];

void preorder(int curr) {
    cout << (char)(curr + 'A');
    if (left_child[curr] != -1) preorder(left_child[curr]);
    if (right_child[curr] != -1) preorder(right_child[curr]);
}

void inorder(int curr) {
    if (left_child[curr] != -1) inorder(left_child[curr]);
    cout << (char)(curr + 'A');
    if (right_child[curr] != -1) inorder(right_child[curr]);
}

void postorder(int curr) {
    if (left_child[curr] != -1) postorder(left_child[curr]);
    if (right_child[curr] != -1) postorder(right_child[curr]);
    cout << (char)(curr + 'A');
}

int main() {
    int n;
    cin >> n;

    // √ ±‚»≠
    fill(left_child, left_child + 26, -1);
    fill(right_child, right_child + 26, -1);

    for (int i = 0; i < n; ++i) {
        char p, l, r;
        cin >> p >> l >> r;

        int parent = p - 'A';
        if (l != '.') left_child[parent] = l - 'A';
        if (r != '.') right_child[parent] = r - 'A';
    }

    preorder(0);   // 'A' == 0
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';

    return 0;
}
