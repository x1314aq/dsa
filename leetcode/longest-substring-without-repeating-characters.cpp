using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }

        int letter[256];
        int ans = 1;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            bzero(letter, sizeof(letter));
            letter[c] = 1;
            int last = i + 1;
            for (; last < s.length(); last++) {
                if (letter[s[last]]) {
                    ans = max(ans, last - i);
                    break;
                }
                letter[s[last]] = 1;
            }
            if (last == s.length()) {
                ans = max(ans, last - i);
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
