using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> visited;

    void dfs(vector<int>& nums, vector<int>& cur) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                cur.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, cur);
                visited[i] = false;
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        visited.resize(nums.size(), false);
        dfs(nums, cur);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{1,2,3};
    auto ans = s.permute(v);
    return 0;
}
