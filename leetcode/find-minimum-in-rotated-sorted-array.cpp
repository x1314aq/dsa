using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 1, r = nums.size();
        int x = nums[0];
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        if (l == nums.size()) {
            return nums[0];
        } else {
            return nums[l];
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> v{3,4,5,1,2};
    Solution s;
    int ans = s.findMin(v);
    return 0;
}
