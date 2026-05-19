using namespace std;

class Solution {
public:
    using vvi = vector<vector<int>>;

    bool dfs(vector<int> &visited, vvi &g, int v, vector<int> &ans) {
        visited[v] = 1;
        for (auto n : g[v]) {
            if (visited[n] == 2) {
                continue;
            }
            if (visited[n] == 1) {
                return false;
            }
            if (!dfs(visited, g, n, ans)) {
                return false;
            }
        }
        visited[v] = 2;
        ans.push_back(v);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vvi g(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            g[a].push_back(b);
        }
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(visited, g, i, ans)) {
                    return vector<int>();
                }
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v{{1,0},{2,0},{3,1},{3,2}};
    auto ans = s.findOrder(4, v);
    return 0;
}
