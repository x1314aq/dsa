using namespace std;

class Solution {
public:
    using vvi = vector<vector<int>>;

    void dfs(int cur, vector<int> &nums, vector<int> &tmp, vvi &ans) {
        if (cur == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[cur]);
        dfs(cur + 1, nums, tmp, ans);
        tmp.pop_back();
        dfs(cur + 1, nums, tmp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vvi ans;
        vector<int> tmp;
        dfs(0, nums, tmp, ans);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{1,2,3};
    auto ans = s.subsets(v);
    return 0;
}
