using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.length();
        int m = word.length();
        if (n < m) return 0;

        int dp[105];
        for (int i = 0; i < m; i++){
            dp[i] = 0;
        }
        int ans = 0;
        for (int i = m - 1; i < n; i++) {
            bool valid = true;
            for (int j = 0; j < m; j++) {
                if (word[j] != sequence[i - (m - 1) + j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                dp[i] = i == m - 1 ? 1 : dp[i - m] + 1;
            } else {
                dp[i] = 0;
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
  string sequence("ababc");
  string word("ab");
  Solution s;
  int ans = s.maxRepeating(sequence, word);
  return 0;
}
