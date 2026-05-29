using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{-1, -1};
        int first = -1, last = -1;
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (l > 0 && nums[l - 1] == target) {
            last = l - 1;
        } else {
            return vector<int>{-1, -1};
        }

        l = 0;
        r = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        first = l;
        return vector<int>{first, last};
    }
};

int main(int argc, char *argv[]) {
    vector<int> v{5,7,7,8,8,10};
    Solution s;
    auto ans = s.searchRange(v, 8);
    return 0;
}
