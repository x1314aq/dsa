#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

// class Solution {
// public:
//     using vpii = vector<pair<int, int>>;
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         set<vector<int>> s;
//         unordered_map<int, vpii> m;
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i + 1; j < nums.size(); j++) {
//                 m[nums[i] + nums[j]].emplace_back(make_pair(i, j));
//             }
//         }

//         for (int i = 0; i < nums.size(); i++) {
//             int target = 0 - nums[i];
//             if (m.count(target)) {
//                 auto &vp = m[target];
//                 for (auto p : vp) {
//                     if (i != p.first && i != p.second) {
//                         vector<int> v{nums[i], nums[p.first], nums[p.second]};
//                         sort(v.begin(), v.end());
//                         s.insert(v);
//                     }
//                 }
//             }
//         }
//         for (auto v : s) {
//             ans.emplace_back(v);
//         }
//         return ans;
//     }
// };

// 官方答案
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};


int main(int argc, char *argv[]) {
    // vector<int> v{-1,0,1,2,-1,-4};
    // vector<int> v{0, 0, 0};
    vector<int> v{-1, 0, 1};
    Solution s;
    auto ans = s.threeSum(v);
    return 0;
}
