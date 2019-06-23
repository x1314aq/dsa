/**
 * hihoCoder 1049  后序遍历
 * BST
 */

#include <cstring>
#include <iostream>

using namespace std;

char preorder[32];
char inorder[32];
char lc[32], rc[32];

char build(int l1, int r1, int l2, int r2) {
    if(l1 > r1) return '0';
    char root = preorder[l1];
    int p = l2;
    while(inorder[p] != root) p++;
    lc[root - 'A'] = build(l1 + 1, p - l2 + l1, l2, p - 1);
    rc[root - 'A'] = build(p - l2 + l1 + 1, r1, p + 1,  r2);
    return root;
}

void post(char root) {
    if(root == '0') return;
    post(lc[root - 'A']);
    post(rc[root - 'A']);
    cout << root;
}

int main() {
    int len;

    cin >> preorder >> inorder;
    len = strlen(preorder);
    build(0, len - 1, 0, len - 1);
    post(preorder[0]);

    cout << endl;
    return 0;
}
