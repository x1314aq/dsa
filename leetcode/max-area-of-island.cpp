/**
 * Leetcode 695 Max area of island
 * brutal BFS
 */

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int row;
    int column;
    int maximum;

    bool is_valid(vector<vector<int>> &grid, int i, int j) {
        if(i < 0 || i >= row)
            return false;
        if(j < 0 || j >= column)
            return false;
        if(grid[i][j] != 1)
            return false;
        return true;
    }

    void bfs(vector<vector<int>> &grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        int temp = 0;
        grid[i][j] |= 0x10000000;

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            temp++;

            if(is_valid(grid, i - 1, j)) {
                q.push(make_pair(i - 1, j));
                grid[i - 1][j] |= 0x10000000;
            }
            if(is_valid(grid, i + 1, j)) {
                q.push(make_pair(i + 1, j));
                grid[i + 1][j] |= 0x10000000;
            }
            if(is_valid(grid, i, j - 1)) {
                q.push(make_pair(i, j - 1));
                grid[i][j - 1] |= 0x10000000;
            }
            if(is_valid(grid, i, j + 1)) {
                q.push(make_pair(i, j + 1));
                grid[i][j + 1] |= 0x10000000;
            }
        }

        if(temp > maximum)
            maximum = temp;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        maximum = 0;
        row = grid.size();
        if(row == 0) return maximum;
        column = grid[0].size();

        for(int i = 0; i < row; i++)
            for(int j = 0; j < column; j++)
                if(grid[i][j] == 1)
                    bfs(grid, i, j);
        
        return maximum;
    }
};

