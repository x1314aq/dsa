using namespace std;

class Solution {
public:
    using pii = pair<int, int>;

    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, pii node) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pii> q;
        q.push(node);
        while (!q.empty()) {
            pii cur = q.front();
            q.pop();
            int i = cur.first;
            int j = cur.second;
            if (j - 1 >= 0 && grid[i][j - 1] == '1' && !visited[i][j - 1]) {
                q.push(pii{i, j - 1});
                visited[i][j - 1] = true;
            }
            if (j + 1 < m && grid[i][j + 1] == '1' && !visited[i][j + 1]) {
                q.push(pii{i, j + 1});
                visited[i][j + 1] = true;
            }
            if (i - 1 >= 0 && grid[i - 1][j] == '1' && !visited[i - 1][j]) {
                q.push(pii{i - 1, j});
                visited[i - 1][j] = true;
            }
            if (i + 1 < n && grid[i + 1][j] == '1' && !visited[i + 1][j]) {
                q.push(pii{i + 1, j});
                visited[i + 1][j] = true;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    visited[i][j] = true;
                    bfs(grid, visited, pii{i, j});
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
