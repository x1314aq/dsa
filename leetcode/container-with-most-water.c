/**
 * Leetcode 11 Container with most water
 * DP
 */

#include <stdio.h>
#include <stdlib.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int maxArea(int *height, int size)
{
    int ans = -1;
    int l = 0, r = size - 1;

    while(l < r) {
        int cur = (r - l) * min(height[l], height[r]);
        if(cur > ans)
            ans = cur;
        if(l + 1 == r)
            break;
        if(height[r] >= height[l]) {
            int tmp = height[l];
            while(l < r && height[l] <= tmp) l++;
        }
        else {
            int tmp = height[r];
            while(l < r && height[r] <= tmp) r--;
        }
    }
    return ans;
}

int array[50005];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("%d\n", maxArea(array, n));
    return 0;
}
