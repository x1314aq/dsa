using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s;
        for (auto n : nums) {
            s.emplace(n);
        }

        for (auto n : s) {
            if (s.count(n - 1)) {
                continue;
            }
            int x = 1;
            for (int m = n + 1;;m++) {
                if (s.count(m) == 0) {
                    break;
                }
                x++;
            }
            ans = max(ans, x);
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
