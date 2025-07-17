#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> inorder, postorder;
unordered_map<int, int> inorder_idx; // 값 → 인덱스 매핑
int n;

void buildPreorder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return;

    int root = postorder[postEnd];         // 후위의 마지막 값이 루트
    cout << root << " ";

    int rootIdx = inorder_idx[root];       // 중위 순회에서 루트 위치 찾기
    int leftSize = rootIdx - inStart;      // 왼쪽 서브트리 크기

    // 왼쪽 서브트리
    buildPreorder(inStart, rootIdx - 1, postStart, postStart + leftSize - 1);

    // 오른쪽 서브트리
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
        inorder_idx[inorder[i]] = i;  // 빠른 검색을 위한 map
    }
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }

    buildPreorder(0, n - 1, 0, n - 1);

    return 0;
}
