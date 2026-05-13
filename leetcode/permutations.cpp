using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &nums, int first, int n) {
        if (first == n) {
            ans.emplace_back(nums);
            return;
        }

        for (int i = first; i < n; i++) {
            swap(nums[i], nums[first]);
            dfs(ans, nums, first + 1, n);
            swap(nums[i], nums[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(ans, nums, 0, nums.size());
        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> v{1,2,3};
    Solution s;
    auto ans = s.permute(v);
    return 0;
}
