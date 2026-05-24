using namespace std;

/* 单调队列 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.emplace_back(nums[q.front()]);
        for (int i = k; i < n; i++) {
            int l = i - k + 1;
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() < l) {
                q.pop_front();
            }
            ans.emplace_back(nums[q.front()]);
        }
        return ans;
    }
};

/* 优先级队列 */
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        int n = nums.size();
//        vector<int> ans;
//        priority_queue<pair<int, int>> q;
//        for (int i = 0; i < k; i++) {
//            q.emplack(nums[i], i);
//        }
//        ans.emplace_back(q.top().first);
//        for (int i = k; i < n; i++) {
//            int l = i - k + 1;
//            q.emplace(nums[i], i);
//            while (q.top().second < l) {
//                q.pop();
//            }
//            ans.emplace_back(q.top().first);
//        }
//        return ans;
//    }
//};


int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{9,10,9,-7,-4,-8,2,-6};
    auto ans = s.maxSlidingWindow(v, 5);
    return 0;
}
