#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k = nums[0];
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            int x = nums[mid];
            if (x > k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int p = l == 0 ? 1 : l;  // 特殊处理k = nums.size() - 1的情况
        auto it = lower_bound(nums.begin(), nums.begin() + p, target);
        if (it != nums.begin() + p && *it == target) {
            return it - nums.begin();
        }
        it = lower_bound(nums.begin() + p, nums.end(), target);
        if (it != nums.end() && *it == target) {
            return it - nums.begin();
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{3, 1};
    int ans = s.search(v, 1);
    return 0;
}
