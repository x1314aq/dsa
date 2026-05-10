using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(nums.size(), 1);
        vector<int> pre(nums.size(), 1);
        vector<int> suf(nums.size(), 1);
        pre[0] = nums[0];
        suf[n - 1] = nums[n - 1];
        for (int i = 1; i < nums.size(); i++) {
            pre[i] = pre[i - 1] * nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] * nums[i];
        }
        for (int i = 1; i < nums.size() - 1; i++) {
            ans[i] = pre[i - 1] * suf[i + 1];
        }
        ans[0] = suf[1];
        ans[n - 1] = pre[n - 2];
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{1,2,3,4};
    auto ans = s.productExceptSelf(v);
    return 0;
}
