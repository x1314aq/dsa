/**
 * Leetcode 127 Word Ladder
 * brutal BFS
 */

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> neigh;
    size_t num;

    bool is_neigh(string &a, string &b) {
        int cnt = 0;
        size_t sz = a.size();
        for (size_t i = 0; i < sz; i++) {
            if (a[i] != b[i])
                cnt++;
        }
        return cnt == 1;
    }

    void build(string &a, int i, vector<string> &words) {
        vector<int> &temp = neigh[i];
        for (size_t i = 0; i < num; i++) {
            if (is_neigh(a, words[i]))
                temp.push_back(i);
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        int ans = 1;
        num = wordList.size();
        neigh.resize(num + 1);
        vector<bool> visited(num, false);

        build(beginWord, 0, wordList);
        for (size_t i = 0; i < num; i++)
            build(wordList[i], i + 1, wordList);

        queue<int> q;
        q.push(-1);
        q.push(-2);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == -2) {
                if (q.empty())
                    break;
                ans++;
                q.push(-2);
                continue;
            }
            if (u >= 0)
                visited[u] = true;
            vector<int> &n = neigh[u + 1];
            size_t temp = n.size();

            for (size_t i = 0; i < temp; i++) {
                if (endWord == wordList[n[i]]) {
                    return ans + 1;
                }
                if (!visited[n[i]])
                    q.push(n[i]);
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    string begin("hit");
    string end("cog");
    vector<string> words = {"hot", "dot", "dog", "lot", "log"};
    cout << s.ladderLength(begin, end, words) << endl;
    return 0;
}
