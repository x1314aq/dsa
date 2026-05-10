using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int ans = 0;
        int pre = 0;
        for (auto x : nums) {
            pre += x;
            if (m.count(pre - k)) {
                ans += m[pre - k];
            }
            m[pre]++;
        }
        return ans;
        // int ans = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     int s = nums[i];
        //     if (s == k) {
        //         ans++;
        //     }
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         s += nums[j];
        //         if (s == k) {
        //             ans++;
        //         }
        //     }
        // }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
