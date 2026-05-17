using namespace std;

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int K) {
        int dp[6][11][11];
        bzero(dp, sizeof(dp));

        vector<unordered_set<int>> v(n);
        for (int i = 0; i < relation.size(); i++) {
            int a = relation[i][0];
            int b = relation[i][1];
            v[b].insert(a);
            dp[1][a][b] = 1;
        }

        for (int k = 2; k <= K; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (auto p : v[j]) {
                        dp[k][i][j] += dp[k - 1][i][p];
                    }
                }
            }
        }
        return dp[K][0][n - 1];
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v{{0, 2},{2,1}};
    int ans = s.numWays(3, v, 2);
    return 0;
}
