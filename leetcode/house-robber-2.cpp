/**
 * Leetcode 213 House Robber 2
 * DP
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        size_t n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        int a = one(nums, 1, n);
        int b = one(nums, 0, n - 1);
        return max(a, b);
    }

    int one(vector<int> &nums, int l, int r) {
        int a = 0, b = 0, c;
        for(int i = l; i < r; i++) {
            c = max(b, a + nums[i]);
            a = b;
            b = c;
        }

        return b;
    }
};
