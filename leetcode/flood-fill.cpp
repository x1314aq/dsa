/**
 * Leetcode 733 Flood Fill
 * brutal BFS
 */

#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    int row;
    int column;
    int start_color;

    bool is_valid(vector<vector<int>> &image, int i, int j) {
        if (i < 0 || j < 0)
            return false;
        if (i >= row || j >= column)
            return false;
        if (image[i][j] != start_color)
            return false;
        return true;
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        row = image.size();
        if (row == 0)
            return image;
        column = image[0].size();
        start_color = image[sr][sc];
        if (start_color == newColor)
            return image;

        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            image[i][j] = newColor;
            if (is_valid(image, i - 1, j)) {
                q.push(make_pair(i - 1, j));
            }
            if (is_valid(image, i + 1, j)) {
                q.push(make_pair(i + 1, j));
            }
            if (is_valid(image, i, j - 1)) {
                q.push(make_pair(i, j - 1));
            }
            if (is_valid(image, i, j + 1)) {
                q.push(make_pair(i, j + 1));
            }
        }
        return image;
    }
};

int main() {
    return 0;
}
