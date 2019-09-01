/**
 * Leetcode 473 Matchsticks to Square
 * brutal DFS
 */

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>


/**
 * brutal DFS
 * Time Limit Exceeded
 */
int length = 0;
int arr_size = 0;
int a[4];

static int cmp(const void *a, const void *b) {
    return *(int *) a < *(int *) b;
}

bool dfs(int *nums, int i) {
    if(i == arr_size)
        return (a[0] == a[1]) && (a[1] == a[2]) && (a[2] == a[3]);
    for(int j = 0; j < 4; j++) {
        if(a[j] + nums[i] > length)
            continue;
        a[j] += nums[i];
        if(dfs(nums, i + 1))
            return true;
        a[j] -= nums[i];
    }
    return false;
}

bool makesquare(int *nums, int numsSize) {
    int sum = 0;
    arr_size = numsSize;
    if(arr_size < 4) return false;
    for(int i = 0; i < arr_size; i++)
        sum += nums[i];
    if(sum & 0x3)
        return false;
    length = sum >> 2;
    qsort(nums, numsSize, sizeof(int), cmp);

    return dfs(nums, 0);
}

int main() {
    int input[12] = {5,5,5,5,4,4,4,4,3,3,3,3};
    if(makesquare(input, 12) == true)
        return 1;
    return 0;
}
