using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount + 1, INT_MAX);
        for (int i = 1; i <= amount; i++) {
            for (auto n : coins) {
                if (n == i) {
                    dp[i] = 1;
                    break;
                }
                if (n < i && dp[i - n] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - n] + 1);
                }
            }
        }

        if (dp[amount] == INT_MAX) {
            return -1;
        }
        return dp[amount];
    }
};

int main(int argc, char *argv[]) {
    vector<int> coins{186, 419, 83, 408};
    Solution s;
    int ans = s.coinChange(coins, 6249);
    return 0;
}
