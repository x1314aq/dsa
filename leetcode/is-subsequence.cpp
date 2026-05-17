using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cur = -1;
        int n = s.length();
        int m = t.length();
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = cur + 1; j < m; j++) {
                if (s[i] == t[j]) {
                    cur = j;
                    found = true;
                    break;
                }
            }
            if (found == false) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    bool ans = s.isSubsequence("axc", "ahbgdc");
    return 0;
}
