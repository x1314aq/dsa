using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int lowest = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            ans = max(ans, prices[i] - lowest);
            lowest = min(lowest, prices[i]);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{7,1,5,3,6,4};
    int ans = s.maxProfit(v);
    return 0;
}
