using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        int base = 0;
        int last = 0;
        while (true) {
            int cur = 1 << base;
            for (int i = last + 1; i <= min(cur, n); i++) {
                ans[i] = ans[i - last] + 1;
            }
            if (cur > n) {
                break;
            }
            ans[cur] = 1;
            last = cur;
            base++;
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    auto ans = s.countBits(2);
    return 0;
}
