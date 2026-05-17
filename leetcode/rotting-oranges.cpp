using namespace std;

class Solution {
public:
    using pii = pair<int, int>;
    using vvi = vector<vector<int>>;
    using vvb = vector<vector<bool>>;

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vvb v(n, vector<bool>(m, false));
        queue<pii> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push(pii{i, j});
                    v[i][j] = true;
                }
            }
        }
        q.push(pii{-1, -1});

        int ans = 0;
        while (!q.empty()) {
            pii node = q.front();
            q.pop();
            int i = node.first;
            int j = node.second;
            if (i == -1 && j == -1) {
                if (q.empty()) {
                    break;
                }
                ans++;
                q.push(node);
                continue;
            }
            if (j - 1 >= 0 && !v[i][j - 1] && grid[i][j - 1] == 1) {
                v[i][j - 1] = true;
                q.push(pii{i, j - 1});
            }
            if (j + 1 < m && !v[i][j + 1] && grid[i][j + 1] == 1) {
                v[i][j + 1] = true;
                q.push(pii{i, j + 1});
            }
            if (i - 1 >= 0 && !v[i - 1][j] && grid[i - 1][j] == 1) {
                v[i - 1][j] = true;
                q.push(pii{i - 1, j});
            }
            if (i + 1 < n && !v[i + 1][j] && grid[i + 1][j] == 1) {
                v[i + 1][j] = true;
                q.push(pii{i + 1, j});
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !v[i][j]) {
                    return -1;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
