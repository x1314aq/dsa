using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m.insert({nums[i], i});
        }
        for (int i = 0; i < nums.size(); i++) {
            int x = target - nums[i];
            if (m.count(x) && (m[x] != i)) {
                return vector<int>({i, m[x]});
            }
        }
        return vector<int>({0, 1});
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    return 0;
}
