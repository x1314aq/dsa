using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int target, int k, vector<int>& cur) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        for (int i = k; i < nums.size(); i++) {
            if (target >= nums[i]) {
                cur.push_back(nums[i]);
                dfs(nums, target - nums[i], i, cur);
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        dfs(candidates, target, 0, cur);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> v{2,3,6,7};
    Solution s;
    auto ans = s.combinationSum(v, 7);
    return 0;
}
