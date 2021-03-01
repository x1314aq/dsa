//
// common algorithms implemented by C
//
#include <stdio.h>

/**
 * find first index between [left, right) of a sorted array, which is >= target.
 * The array must be sorted in ascending order.

 * @return: index of target if found, or right if not found
 */
int lower_bound(int *array, int left, int right, int target) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (array[mid] >= target) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

/**
 * find first index between [left, right) of a sorted array, which is > target.
 * The array must be sorted in ascending order.
 *
 * @return: index of *target* if found, or *right* if not found
 */
int upper_bound(int *array, int left, int right, int target) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (array[mid] > target) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

#define swap(p, i, j)   \
    do {    \
        __typeof__(p[i]) t = p[i];      \
        p[i] = p[j];                \
        p[j] = t;                   \
    } while (0)

void reverse(int *array, int left, int right) {
    int i, j;
    for (i = left, j = left + right - 1 - i; i < j; i++, j--) {
        swap(array, i, j);
    }
}

/**
 * Transform range [left, right) to next permutation.
 * It changes the given permutation just in place
 *
 * @return: true or false
 * true if the function could rearrange the object as a lexicographicaly greater permutation.
 * Otherwise, the function returns false to indicate that the arrangement is not greater than the previous,
 * but the lowest possible (sorted in ascending order)
 */
bool next_permutation(int *array, int left, int right) {
    if (right - left < 2) {
        return false;
    }
    int cur = right - 1;
    while (1) {
        int pre = cur - 1;
        if (array[pre] < array[cur]) {
            int last = right;
            while (!(array[pre] < array[--last]));
            swap(array, pre, last);
            reverse(array, cur, right);
            return true;
        }

        if (pre == left) {
            reverse(array, left, right);
            return false;
        }
        cur = pre;
    }
}

/**
 * Depth-First-Search print C(n, k) and A(n, k)
 */
int n, k;
int a[25];
bool vis[25];

void combination_dfs(int m, int startx) {
    if (m == k) {
        for (int i = 0; i < m; i++)
            printf("%3d", a[i]);
        putchar('\n');
        return;
    }
    for (int i = startx + 1; i < n; i++) {
        a[m] = i;
        combination_dfs(m + 1, i);
    }
}

void arrangement_dfs(int m) {
    if (m == k) {
        for (int i = 0; i < m; i++)
            printf("%3d", a[i]);
        putchar('\n');
        return;
    }
    for (int i = 1; i <= n; i++) {
        a[m] = i;
        vis[i] = true;
        arrangement_dfs(m + 1);
        vis[i] = false;
    }
}

/**
 * Breadth-First-Search template
 */
void bfs() {

}

/**
 * heap implementation
 */
void make_heap(int *array, int left, int right) {

}

void pop_heap(int *array, int left, int right) {

}

void push_heap(int *array, int left, int right) {

}
