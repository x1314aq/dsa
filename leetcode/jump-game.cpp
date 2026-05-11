using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        while (true) {
            int n = i + nums[i];
            if (n >= nums.size() - 1) {
                return true;
            }
            if (nums[i] == 0) {
                return false;
            }
            int cur = n;
            int next = i;
            for (int j = i + 1; j <= n && j < nums.size(); j++) {
                if (j + nums[j] >= cur) {
                    cur = j + nums[j];
                    next = j;
                }
            }
            i = next;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{5,9,3,2,1,0,2,3,3,1,0,0};
    bool ans = s.canJump(v);
    return 0;
}
