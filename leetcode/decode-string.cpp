using namespace std;

class Solution {
  public:
    string decodeString(string s) {
        string str;
        vector<int> nums;
        vector<string> strs;

        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            while (isalpha(s[i])) {
                str.push_back(s[i]);
                i++;
            }
            while (isdigit(s[i])) {
                num *= 10;
                num += s[i] - '0';
                i++;
            }
            if (s[i] == '[') {
                nums.push_back(num);
                strs.push_back(str);
                num = 0;
                str.clear();
            } else if (s[i] == ']') {
                int cur_num = nums.back();
                nums.pop_back();
                string cur_str = strs.back();
                strs.pop_back();
                for (int i = 0; i < cur_num; i++) {
                    cur_str += str;
                }
                str = cur_str;
            }
        }
        return str;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    auto ans = s.decodeString("3[a2[c]]");
    return 0;
}