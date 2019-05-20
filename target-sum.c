/**
 * Leetcode 494 Target Sum
 * brutal DFS
 */

#include <stdlib.h>
#include <limits.h>


/**
 * C++ implementation
 * brtual force algorithm.
 */
/*
using namespace std;

class Solution {
public:
    int total;
    int size;
    void dfs(vector<int> &nums, int S, int i, int sum) {
        if(i == size){
            if(sum == S)
                total++;
        }
        else{
            dfs(nums, S, i + 1, sum + nums[i]);
            dfs(nums, S, i + 1, sum - nums[i]);
        }
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        size = nums.size();
        if(size == 0) return 0;
        total = 0;
        dfs(nums, S, 0, 0);
        return total;
    }
};
*/

/**
 * C implementation
 * dfs with memorization
 */
/*
int size = 0;
int memo[21][2001];

int dfs_with_memory(int *nums, int S, int i, int sum) {
    if(i == size) {
        if(sum == S)
            return 1;
        return 0;
    }
    else {
        if(memo[i][sum + 1000] != INT_MIN) {
            return memo[i][sum + 1000];
        }
        int a = dfs_with_memory(nums, S, i + 1, sum + nums[i]);
        int b = dfs_with_memory(nums, S, i + 1, sum - nums[i]);
        memo[i][sum + 1000] = a + b;
        return a + b;
    }
}

int findTargetSumWays(int* nums, int numsSize, int S){
    size = numsSize;
    for(int i = 0; i < numsSize; i++) {
        for(int j = 0; j < 2001; j++)
            memo[i][j] = INT_MIN;
    }
    return dfs_with_memory(nums, S, 0, 0);
}
*/

/**
 * dynamic programming
 * seems slower than above algorithm...
 */
int dp[21][4001];

int findTargetSumWays(int* nums, int numsSize, int S){
    int offset = 2000;
    int last = nums[numsSize - 1];

    for(int sum = -1000; sum < 1001; sum++)
        dp[numsSize - 1][sum + offset] = (sum + last == S ? 1 : 0) + (sum - last == S ? 1 : 0);

    for(int i = numsSize - 2; i >= 0; i--) {
        for(int sum = -1000; sum < 1001; sum++) {
            dp[i][sum + offset] = dp[i + 1][sum + nums[i] + offset] + dp[i + 1][sum - nums[i] + offset];
        }
    }
    return dp[0][offset];
}

int main() {
    int input[5] = {1, 1, 1, 1, 1};
    findTargetSumWays(input, 5, 3);
    return 0;
}
