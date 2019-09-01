/**
 * Leetcode 463 Island Perimeter
 * brutal BFS
 */

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int row;
    int column;

    bool valid(int i, int j) {
        return i >= 0 && i < row && j >= 0 && j < column;
    }

    int islandPerimeter(vector<vector<int>> &grid) {
        row = grid.size();
        column = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(column));
        int perimeter = 0;
        int sr = -1;
        int sc = -1;

        for(int i = 0; i < row; i++)
            for(int j = 0; j < column; j++)
                if(grid[i][j] == 1) {
                    sr = i;
                    sc = j;
                    goto START;
                }

START:
        queue<pair<int, int>> q;
        visited[sr][sc] = 1;
        q.push(make_pair(sr, sc));
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            perimeter += 4;
            if(valid(i - 1, j) && grid[i - 1][j]) {
                perimeter--;
                if(visited[i - 1][j] == 0) {
                    visited[i - 1][j] = 1;
                    q.push(make_pair(i - 1, j));
                }
            }
            if(valid(i + 1, j) && grid[i + 1][j]) {
                perimeter--;
                if(visited[i + 1][j] == 0) {
                    visited[i + 1][j] = 1;
                    q.push(make_pair(i + 1, j));
                }
            }
            if(valid(i, j - 1) && grid[i][j - 1]) {
                perimeter--;
                if(visited[i][j - 1] == 0) {
                    visited[i][j - 1] = 1;
                    q.push(make_pair(i, j - 1));
                }
            }
            if(valid(i, j + 1) && grid[i][j + 1]) {
                perimeter--;
                if(visited[i][j + 1] == 0) {
                    visited[i][j + 1] = 1;
                    q.push(make_pair(i, j + 1));
                }
            }
        }

        return perimeter;
    }
};

