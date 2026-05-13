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
    unordered_map<long long, int> map;
    int k;
    int ans;

    void dfs(TreeNode *n, long long sum) {
        if (n == nullptr) return;
        sum += n->val;
        if (map.count(sum - k)) {
            ans += map[sum - k];
        }
        map[sum]++;
        if (n->left) {
            dfs(n->left, sum);
            map[sum + n->left->val]--;
        }
        if (n->right) {
            dfs(n->right, sum);
            map[sum + n->right->val]--;
        }
    }

    int pathSum(TreeNode* root, int targetSum) {
        k = targetSum;
        ans = 0;
        map[0] = 1;
        dfs(root, 0);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
