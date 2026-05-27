using namespace std;

class Solution {
public:
    vector<string> ans;

    void dfs(vector<string> &letters, string &digits, int k, string &cur) {
        if (k == digits.size()) {
            ans.push_back(cur);
            return;
        }

        for (auto c : letters[digits[k] - '2']) {
            cur.push_back(c);
            dfs(letters, digits, k + 1, cur);
            cur.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> letters{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
        string cur;
        dfs(letters, digits, 0, cur);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string digits("23");
    auto ans = s.letterCombinations(digits);
    return 0;
}
