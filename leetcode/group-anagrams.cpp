#include <cstring>
using namespace std;

class Solution {
public:
    int counts[10001][26];

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<int> flags(strs.size(), 0);

        bzero(counts, sizeof(counts));

        for (int i = 0; i < strs.size(); i++) {
            for (auto c : strs[i]) {
                counts[i][c - 'a']++;
            }
        }

        for (int i = 0; i < strs.size(); i++) {
            if (flags[i]) {
                continue;
            }

            vector<string> cur;
            cur.push_back(strs[i]);
            for (int j = i + 1; j < strs.size(); j++) {
                if (strs[i].length() != strs[j].length()) {
                    continue;
                }
                if (memcmp(counts[i], counts[j], sizeof(counts[i])) == 0) {
                    cur.push_back(strs[j]);
                    flags[j] = 1;
                }
            }

            ans.push_back(cur);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<string> input;
    input.push_back("eat");
    input.push_back("tea");
    input.push_back("tan");
    input.push_back("ate");
    input.push_back("nat");
    input.push_back("bat");
    auto ans = s.groupAnagrams(input);

    for (auto &x : ans) {
        for (auto &y : x) {
            cout << y << endl;
        }
    }
    return 0;
}
