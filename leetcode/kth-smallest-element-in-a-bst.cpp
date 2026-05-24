using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int target;
    int index = 0;
    int ans;
    void traverse(TreeNode *root) {
        if (root->left) {
            traverse(root->left);
        }
        index++;
        if (index == target) {
            ans = root->val;
            return;
        }
        if (root->right) {
            traverse(root->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        target = k;
        traverse(root);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
