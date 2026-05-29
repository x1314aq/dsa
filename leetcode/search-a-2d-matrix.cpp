using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0;
        int r = n * m;
        while (l < r) {
            int mid = (l + r) / 2;
            int i = mid / m;
            int j = mid % m;
            if (matrix[i][j] > target) {
                r = mid;
            } else if (matrix[i][j] == target) {
                return true;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    vector<int> a{1,3,5,7};
    vector<int> b{10,11,16,20};
    vector<int> c{23,30,34,60};
    vector<vector<int>> matrix{a,b,c};
    Solution s;
    bool ans = s.searchMatrix(matrix, 3);
    return 0;
}
