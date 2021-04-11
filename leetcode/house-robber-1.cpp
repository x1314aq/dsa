/**
 * Leetcode 198 House Robber
 * DP
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int rob(vector<int> &nums) {
        size_t n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int a, b, c;
        a = nums[0];
        b = max(a, nums[1]);
        c = b;

        for (size_t i = 2; i < n; i++) {
            c = max(b, a + nums[i]);
            a = b;
            b = c;
        }

        return c;
    }
};

int main() {
    return 0;
}
