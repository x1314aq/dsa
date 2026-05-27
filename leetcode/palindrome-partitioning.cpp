using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;

public:
    void dfs(const string& s, int i) {
        if (i == n) {
            ret.push_back(ans);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (dp[i][j]) {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        dp.assign(n, vector<int>(n, true));

        // 边界1: 对角线，即单个字符，都是回文
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        // 边界2:对角线上侧紧邻斜线，即两个字符，判断是否相等，相等则为回文
        for(int i = 0; i < n - 1; i++){
            dp[i][i + 1] = s[i] == s[i + 1];
        }
        // 从下到上，边界1和边界2确定了两条斜线，所以只需要从倒数第三行开始往上补全右上三角
        for(int i = n - 3; i >= 0; i--){
            for(int j = i + 2; j < n; j++){
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            }
        }

        dfs(s, 0);
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string inp("aab");
    auto ans = s.partition(inp);
    return 0;
}
