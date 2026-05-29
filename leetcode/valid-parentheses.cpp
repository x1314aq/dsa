using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                v.push_back(c);
            } else {
                if (v.empty()) return false;
                char a = v.back();
                if ((a == '(' && c == ')') || (a == '[' && c == ']') || (a == '{' && c == '}')) {
                    v.pop_back();
                } else {
                    return false;
                }
            }
        }
        return v.empty();
    }
};

int main(int argc, char *argv[]) {
    string st("()[[({})]]");
    Solution s;
    bool ans = s.isValid(st);
    return 0;
}
