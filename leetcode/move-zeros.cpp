#include <utility>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (i < nums.size()) {
            if (nums[i]) {
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{0,1,0,3,12};
    s.moveZeroes(v);

    return 0;
}
