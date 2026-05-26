using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string &word, int k) {
        int n = board.size();
        int m = board[0].size();
        if (k == word.length()) {
            return true;
        }

        visited[i][j] = true;
        if (j >= 1 && !visited[i][j - 1] && board[i][j - 1] == word[k]) {
            if (dfs(board, visited, i, j - 1, word, k + 1)) {
                return true;
            }
        }
        if (j + 1 < m && !visited[i][j + 1] && board[i][j + 1] == word[k]) {
            if (dfs(board, visited, i, j + 1, word, k + 1)) {
                return true;
            }
        }
        if (i >= 1 && !visited[i - 1][j] && board[i - 1][j] == word[k]) {
            if (dfs(board, visited, i - 1, j, word, k + 1)) {
                return true;
            }
        }
        if (i + 1 < n && !visited[i + 1][j] && board[i + 1][j] == word[k]) {
            if (dfs(board, visited, i + 1, j, word, k + 1)) {
                return true;
            }
        }
        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, visited, i, j, word, 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<char> a1{'A', 'B', 'C', 'E'};
    vector<char> a2{'S', 'F', 'C', 'S'};
    vector<char> a3{'A', 'D', 'E', 'E'};
    vector<vector<char>> board{a1, a2, a3};
    bool ans = s.exist(board, "ABCCED");
    return 0;
}
