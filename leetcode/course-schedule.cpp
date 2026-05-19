using namespace std;

class Solution {
public:
    using vvi = vector<vector<int>>;

    bool dfs(vector<int> &visited, vvi &g, int v) {
        visited[v] = 1;
        for (auto n : g[v]) {
            if (visited[n] == 2) {
                continue;
            }
            if (visited[n] == 1) {
                return false;
            }
            if (!dfs(visited, g, n)) {
                return false;
            }
        }
        visited[v] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vvi g(numCourses, vector<int>());
        for (auto v : prerequisites) {
            int a = v[0];
            int b = v[1];
            g[a].push_back(b);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(visited, g, i)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> v{{1,4},{2,4},{3,1},{3,2}};
  Solution s;
  bool ans = s.canFinish(5, v);
  return 0;
}
