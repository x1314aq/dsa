/**
 * Leetcode 1034 Coloring a border
 * brutal BFS
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    int row;
    int column;
    int start_color;

    bool is_border(vector<vector<int>> &grid, int i, int j, vector<vector<int>> visited) {
        if (i == 0 || i == row - 1)
            return true;
        if (j == 0 || j == column - 1)
            return true;
        if ((grid[i - 1][j] != start_color && visited[i - 1][j] == 0) ||
            (grid[i + 1][j] != start_color && visited[i + 1][j] == 0) ||
            (grid[i][j - 1] != start_color && visited[i][j - 1] == 0) ||
            (grid[i][j + 1] != start_color && visited[i][j + 1] == 0))
            return true;
        return false;
    }

    bool is_valid(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= row)
            return false;
        if (j < 0 || j >= column)
            return false;
        if (grid[i][j] != start_color)
            return false;
        return true;
    }

    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color) {
        row = grid.size();
        if (row == 0)
            return grid;
        column = grid[0].size();
        start_color = grid[r0][c0];
        if (start_color == color)
            return grid;
        vector<vector<int>> visited(row, vector<int>(column));

        queue<pair<int, int>> q;
        q.push(make_pair(r0, c0));

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            visited[i][j] = 1;
            if (is_border(grid, i, j, visited))
                grid[i][j] = color;

            if (is_valid(grid, i - 1, j) && visited[i - 1][j] == 0) {
                q.push(make_pair(i - 1, j));
            }
            if (is_valid(grid, i + 1, j) && visited[i + 1][j] == 0) {
                q.push(make_pair(i + 1, j));
            }
            if (is_valid(grid, i, j - 1) && visited[i][j - 1] == 0) {
                q.push(make_pair(i, j - 1));
            }
            if (is_valid(grid, i, j + 1) && visited[i][j + 1] == 0) {
                q.push(make_pair(i, j + 1));
            }
        }
        return grid;
    }
};

int main() {
    vector<vector<int>> input(3, vector<int>(3));
    input[0][0] = 1;
    input[1][0] = 1;
    input[2][0] = 1;
    input[0][1] = 1;
    input[1][1] = 1;
    input[2][1] = 1;
    input[0][2] = 1;
    input[1][2] = 1;
    input[2][2] = 1;
    Solution s;
    auto v = s.colorBorder(input, 1, 1, 2);
    cout << v[1][1] << endl;
    return 0;
}
