using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < m; i++) {
            vector<int> v(n, 0);
            for (int j = 0; j < n; j++) {
                v[j] = matrix[j][i];
            }
            ans.push_back(v);
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v{{1,2,3}, {4,5,6}};
    auto ans = s.transpose(v);
    return 0;
}
