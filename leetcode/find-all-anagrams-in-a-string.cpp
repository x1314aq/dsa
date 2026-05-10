using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.length() < p.length()) {
            return ans;
        }

        int letter[26];
        bzero(letter, sizeof(letter));
        for (int i = 0; i < p.length(); i++) {
            letter[p[i] - 'a'] += 1;
        }
        for (int i = 0; i <= s.length() - p.length(); i++) {
            int tmp[26];
            bzero(tmp, sizeof(tmp));
            tmp[s[i] - 'a'] += 1;
            for (int j = i + 1; j < min(s.length(), i + p.length()); j++) {
                tmp[s[j] - 'a'] += 1;
            }
            if (memcmp(letter, tmp, sizeof(letter)) == 0) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
