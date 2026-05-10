using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();

        for (int k = 0;; k++) {
            if (2 * k == n || 2 * k == (n - 1)) {
                return;
            }
            for (int i = k; i < n - k - 1; i++) {
                int a = matrix[k][i];
                int b = matrix[i][n - k - 1];
                int c = matrix[n - k - 1][n - i - 1];
                int d = matrix[n - i - 1][k];
                int x = d;
                matrix[n - i - 1][k] = c;
                matrix[n - k - 1][n - i - 1] = b;
                matrix[i][n - k - 1] = a;
                matrix[k][i] = x;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v{{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(v);
    return 0;
}
