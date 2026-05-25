using namespace std;

class Solution {
public:
    using pii = pair<int, int>;

    vector<vector<string>> ans;

    bool pos_ok(int row, int col, vector<pii> pos) {
        for (auto p : pos) {
            int x = p.first;
            int y = p.second;
            if (col == y) return false; //同一列

            for (int i = 1; i < 9; i++) {
                pii p1{x - i, y - i};
                pii p2{x - i, y + i};
                pii p3{x + i, y - i};
                pii p4{x + i, y + i};

                if (p1.first == row && p1.second == col) return false;
                if (p2.first == row && p2.second == col) return false;
                if (p3.first == row && p3.second == col) return false;
                if (p4.first == row && p4.second == col) return false;
            }
        }
        return true;
    }

    void dfs(int n, vector<string> &cur, vector<pii> &pos) {
        if (cur.size() == n) {
            ans.push_back(cur);
            return;
        }

        int m = cur.size();
        string tmp(n, '.');
        for (int i = 0; i < n; i++) {
            if (pos_ok(m, i, pos)) {
                tmp[i] = 'Q';
                pos.emplace_back(m, i);
                cur.push_back(tmp);
                dfs(n, cur, pos);
                cur.pop_back();
                pos.pop_back();
                tmp[i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<pii> pos;
        vector<string> cur;
        dfs(n, cur, pos);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    auto ans = s.solveNQueens(9);
    return 0;
}
