using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1) {
            return s;
        }
        bool dp[1005][1005];

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            dp[i][i + 1] = s[i] == s[i + 1];
        }

        for (int i = n - 3; i >= 0; i--) {
            for (int j = n - 1; j > i + 1; j--) {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            }
        }

        int len = 1;
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dp[i][j]) {
                    if (j - i + 1 >= len) {
                        len = j - i + 1;
                        index = i;
                    }
                }
            }
        }

        return s.substr(index, len);
    };
};

int main(int argc, char *argv[]) {
  Solution s;
  string in("bananas");

  auto out = s.longestPalindrome(in);
  return 0;
}
