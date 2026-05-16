using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int x[105];
        bzero(x, sizeof(x));
        x[1] = s[0] == '0' ? 0 : 1;
        if (n >= 2) {
            int a = 10 * (s[0] - '0') + (s[1] - '0');
            if (s[0] != '0' && s[1] != '0') {
                x[2] += 1;
            }
            if (s[0] != '0' && a <= 26) {
                x[2] += 1;
            }
        }
        for (int i = 3; i <= n; i++) {
            int a = s[i - 1] == '0' ? 0 : 1;
            int b = 0;
            if (s[i - 2] != '0') {
                int c = 10 * (s[i - 2] - '0') + (s[i - 1] - '0');
                if (c <= 26) {
                    b = 1;
                }
            }
            x[i] = a * x[i - 1] + b * x[i - 2];
        }

        return x[n];
    }
};

int main(int argc, char *argv[]) {
  Solution s;
  string codes("301");
  int ans = s.numDecodings(codes);
  return 0;
}
