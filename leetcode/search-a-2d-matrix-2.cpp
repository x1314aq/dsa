using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if (it != matrix[i].end()) {
                if (*it == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v{{1,2,3},{4,5,6}};
    auto ans = s.searchMatrix(v, 4);
    return 0;
}
