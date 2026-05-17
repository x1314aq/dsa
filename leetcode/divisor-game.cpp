using namespace std;

class Solution {
public:
    bool divisorGame(int n) {
        bool ans[1005];
        ans[1] = false;
        ans[2] = true;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= (int)sqrt(i); j++) {
                if (i % j == 0 && !ans[i - j]) {
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans[n];
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    bool ans = s.divisorGame(1000);
    return 0;
}
