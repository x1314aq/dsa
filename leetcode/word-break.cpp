using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us;
        for (auto w : wordDict) {
            us.insert(w);
        }

        vector<bool> ans(s.length() + 1, false);
        ans[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                string sub = s.substr(j, i - j);
                if (ans[j] && us.find(sub) != us.end()) {
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans[s.length()];
    }
};

int main(int argc, char *argv[]) {
    string str("leetcode");
    vector<string> wordDict{"leet", "code"};
    Solution s;
    bool ans = s.wordBreak(str, wordDict);
    return 0;
}
