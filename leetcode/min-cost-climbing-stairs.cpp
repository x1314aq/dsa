using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = 0, b = 0;
        int ans;
        for (int i = 2; i <= n; i++) {
            ans = min(b + cost[i - 1], a + cost[i - 2]);
            a = b;
            b = ans;
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{10, 15, 20};
    int ans = s.minCostClimbingStairs(v);
    return 0;
}
