#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> inorder, postorder;
unordered_map<int, int> inorder_idx; // �� �� �ε��� ����
int n;

void buildPreorder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return;

    int root = postorder[postEnd];         // ������ ������ ���� ��Ʈ
    cout << root << " ";

    int rootIdx = inorder_idx[root];       // ���� ��ȸ���� ��Ʈ ��ġ ã��
    int leftSize = rootIdx - inStart;      // ���� ����Ʈ�� ũ��

    // ���� ����Ʈ��
    buildPreorder(inStart, rootIdx - 1, postStart, postStart + leftSize - 1);

    // ������ ����Ʈ��
    buildPreorder(rootIdx + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    inorder.resize(n);
    postorder.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
        inorder_idx[inorder[i]] = i;  // ���� �˻��� ���� map
    }
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }

    buildPreorder(0, n - 1, 0, n - 1);

    return 0;
}
